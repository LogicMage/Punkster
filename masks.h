#ifndef MASKS_H
#define MASKS_H

#define OVERFLOW 0x40
#define CARRY 0x80
#define NEGATIVE 0x100
#define ZERO 0x200

#define SET_BIT(reg, bit) ((reg) |= (bit))
#define CLEAR_BIT(reg, bit) ((reg) &= ~(bit))
#define TOGGLE_BIT(reg, bit) ((reg) ^= (bit))
#define TEST_BIT(reg, bit) ((reg) & (bit))

#define REGISTER_COUNT 36

#endif