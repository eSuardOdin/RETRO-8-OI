#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "cpu_reg.h"
#include "memory.h"
#include <stdint.h>


typedef struct {
    /// Cpu registers of gameboy
    cpu_reg *reg;
    /// Represents the whole memory adressable by the GameBOY
    memory *mem;
} gameboy;

void reset_gameboy(gameboy *gb);



#endif