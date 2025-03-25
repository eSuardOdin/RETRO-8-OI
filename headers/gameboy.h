#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "cpu_reg.h"
#include <stdint.h>


typedef struct {
    /// Cpu registers of gameboy
    cpu_reg *reg;
    /// Represents the whole memory adressable by the GameBOY
    uint8_t ram[0x10000];
} gameboy;

void reset_gameboy(gameboy *gb);

int load_cart(char *path);

#endif