#ifndef ARCA5_H
#define ARCA5_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "masks.h"

// Registers r32-r59 are extension core registers and left unimplemented for now.

typedef enum {
    r0 = 0x00,
    r1,
    r2,
    r3,
    r4,
    r5,
    r6,
    r7,
    r8,
    r9,
    r10,
    r11,
    r12,
    r13,
    r14,
    r15,
    r16,
    r17,
    r18,
    r19,
    r20,
    r21,
    r22,
    r23,
    r24,
    r25,
    gp,
    fp,
    sp,
    ilink1,
    ilink2,
    blink,
    lp_count,
    r61,
    r62,
    pc
} ARCA5RegisterReference;

//#pragma pack (2)
typedef struct CoreRegistersARCA5 {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t r13;
    uint32_t r14;
    uint32_t r15;
    uint32_t r16;
    uint32_t r17;
    uint32_t r18;
    uint32_t r19;
    uint32_t r20;
    uint32_t r21;
    uint32_t r22;
    uint32_t r23;
    uint32_t r24;
    uint32_t r25;
    uint32_t gp;
    uint32_t fp;
    uint32_t sp;
    uint32_t ilink1;
    uint32_t ilink2;
    uint32_t blink;
    uint32_t lp_count;
    uint32_t r61;
    uint32_t r62;
    uint32_t pc;
} CoreRegistersARCA5;

//#pragma pack (2)
typedef struct AuxiliaryRegistersARCA5
{
    uint32_t status;
    uint32_t semaphore;
    uint32_t lp_start;
    uint32_t lp_end;
    uint32_t identity;
    uint32_t debug;
    uint32_t pc;
    uint32_t status32;
    uint32_t status32_l1;
    uint32_t status32_l2;
    uint32_t int_vector_base;
    uint32_t aux_macmode;
    uint32_t aux_irq_lv12;
    uint32_t build_config_1; //listed in docs as "0x7F"
    uint32_t build_config_2; //listed in docs as "0xFF"
    uint32_t aux_irq_lev;
    uint32_t aux_irq_hint;
    uint32_t eret;
    uint32_t erbta;
    uint32_t erstatus;
    uint32_t ecr;
    uint32_t efa;
    uint32_t icause1;
    uint32_t icause2;
    uint32_t aux_ienable;
    uint32_t aux_itrigger;
    uint32_t bta;
    uint32_t bta_l1;
    uint32_t bta_l2;
    uint32_t aux_irq_pulse_cancel;
    uint32_t aux_irq_pending;
} AuxiliaryRegistersARCA5;

#define SET_STATUS_FLAG(flag) SET_BIT(auxRegs->status, flag)
#define UNSET_STATUS_FLAG(flag) CLEAR_BIT(auxRegs->status, flag)

#endif

