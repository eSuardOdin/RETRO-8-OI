#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "cpu_reg.h"


typedef struct {
    cpu_reg *reg;
    /// Represents the whole memory adressable by the GameBOY
    uint8_t ram[0x10000];
} gameboy;

#endif