#include "ARCA5.h"

uint32_t* InitializeARCA5Memory()
{
    uint32_t* CoreRegistersARCA5 = (uint32_t*)malloc(REGISTER_COUNT * sizeof(uint32_t));
    memset(CoreRegistersARCA5, 0, REGISTER_COUNT * sizeof(uint32_t));
    return(CoreRegistersARCA5);
}

void UnimplementedInstruction()
{
    printf("Error: unimplemented instruction read\n");
    exit(1);
}

void EmulateARCA5(uint32_t* coreRegs, AuxiliaryRegistersARCA5* auxRegs, char* buffer)
{
    //printf("%c",buffer);
    uint32_t offset = coreRegs[pc];
    printf("Offset: %d\n", offset);
    unsigned char opcode = buffer[offset];
    uint32_t ic = TEST_BIT((int)buffer[offset], 0xF8); //masks out the 3 least signifcant bits to find the instruction code
    printf("Instruction code read: %x\n", ic);
    printf("Opcode read: %c\n", opcode);
    /*ic >>= 3;
    printf("Instruction code read post-shift: %d\n", ic);
    printf("Opcode read post-shift: %c\n", (char)ic);*/

    if (ic < 0x0C)
    {
        switch(ic)
        {
            case 0x00: UnimplementedInstruction();
            case 0x01: UnimplementedInstruction();
            case 0x02: UnimplementedInstruction();
            case 0x03: UnimplementedInstruction();
            case 0x04: UnimplementedInstruction();
            case 0x05: UnimplementedInstruction();
            case 0x06: UnimplementedInstruction();
            case 0x07: UnimplementedInstruction();
            case 0x08: UnimplementedInstruction();
            case 0x09: UnimplementedInstruction();
            case 0x0A: UnimplementedInstruction();
            case 0x0B: UnimplementedInstruction();
        }
        coreRegs[pc] += 4;
    }
    else
    {
        switch(ic)
        {
            case 0x0C: 
                /*int b = TEST_BIT((int)buffer[offset], 0x07);
                int a = TEST_BIT((int)buffer[++offset], 0x07);
                int c = (TEST_BIT((int)buffer[offset], 0xE0))>>5;
                int i = (TEST_BIT((int)buffer[offset], 0x18))>>3;*/
                int a = TEST_BIT((int)buffer[offset], 0x07);
                int b = TEST_BIT((int)buffer[--offset], 0x07);
                int c = (TEST_BIT((int)buffer[offset], 0xE0))>>5;
                int i = (TEST_BIT((int)buffer[offset], 0x18))>>3;

                switch(i)
                {
                    case 0x00:
                    case 0x01:
                    case 0x02:
                    case 0x03: //add registers A/B and load them to C
                        coreRegs[a] = coreRegs[b] + coreRegs[c];
                        coreRegs[a] == 0 ? SET_STATUS_FLAG(ZERO) : UNSET_STATUS_FLAG(ZERO);
                        TEST_BIT(coreRegs[a], 0x80000000) ? SET_STATUS_FLAG(NEGATIVE) : UNSET_STATUS_FLAG(NEGATIVE);
                        coreRegs[a] < a ? SET_STATUS_FLAG(CARRY) : UNSET_STATUS_FLAG(CARRY);
                        printf("Register A: %d, Register B: %d, Register C: %d\n", coreRegs[a], coreRegs[b], coreRegs[c]);
                        break;
                }
                break;
            case 0x0D: UnimplementedInstruction();
            case 0x0E: UnimplementedInstruction();
            case 0x0F: UnimplementedInstruction();
            case 0x10: UnimplementedInstruction();
            case 0x11: UnimplementedInstruction();
            case 0x12: UnimplementedInstruction();
            case 0x13: UnimplementedInstruction();
            case 0x14: UnimplementedInstruction();
            case 0x15: UnimplementedInstruction();
            case 0x16: UnimplementedInstruction();
            case 0x17: UnimplementedInstruction();
            case 0x18: UnimplementedInstruction();
            case 0x19: UnimplementedInstruction();
            case 0x1A: UnimplementedInstruction();
            case 0x1B: UnimplementedInstruction();
            case 0x1C: UnimplementedInstruction();
            case 0x1D: UnimplementedInstruction();
            case 0x1E: UnimplementedInstruction();
            case 0x1F: UnimplementedInstruction();
        }
        coreRegs[pc] += 2;
    }
    
}

int main(int argc, char** argv)
{
    CoreRegistersARCA5 coreRegs;
    AuxiliaryRegistersARCA5 auxRegs;
    ARCA5RegisterReference ref;

    FILE *readfile = fopen(argv[1], "rb");
    if (readfile==NULL) {    
        printf("Error: couldn't open %s\n", argv[1]);    
        exit(1);    
    }    
    fseek(readfile, 0L, SEEK_END);
    int fsize = ftell(readfile);
    fseek(readfile, 0L, SEEK_SET);

    unsigned char *buffer = malloc(fsize);
    fread(buffer, fsize, 1, readfile);
    fclose(readfile);
    
    uint32_t* ARCA5Memory = InitializeARCA5Memory();

    printf("Size of file: %d\n",fsize);
    while (ARCA5Memory[pc] < fsize) {
        printf("Program count: %d\n", ARCA5Memory[pc]);
        EmulateARCA5(ARCA5Memory, &auxRegs, buffer);
    }
    free(buffer);

    return 0;
}

/*registers.r0 = 0x00000000;
registers.pc = 0x00000100;
printf("%08x\n", registers.r0);
SET_BIT(registers.r0, 0x4);
printf("%08x\n", registers.r0);
TOGGLE_BIT(registers.r0, 0xff);
printf("%08x\n", registers.r0);
TOGGLE_BIT(registers.r0, 0xaa00);
printf("%08x\n", registers.r0);
CLEAR_BIT(registers.r0, 0xaafb);
printf("%08x\n", registers.r0);
printf("The register's first bit is set: %s\n", TEST_BIT(registers.r0, 0x0) ? "true" : "false");

    for (int i = 0; i < 4; i++)
    {
        registers.pc += EmulateARCA5(&registers);
    }

printf("%d\n", opcode);
    printf("%d\n", ic);
    
    printf("%d\n", ic);
                printf("Offset: %d\n",offset);
                printf("Memory: %d\n",(int)buffer[offset]);
printf("Register A: %d, Register B: %d, Register C: %d, Code I: %d\n",a,b,c,i);
*/