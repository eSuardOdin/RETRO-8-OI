#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "cpu_reg.h"
#include <stdint.h>


typedef struct {
    cpu_reg *reg;
    /// Represents the whole memory adressable by the GameBOY
    uint8_t ram[0x10000];
} gameboy;

void reset_gameboy(gameboy *gb);

uint8_t fetch_opcode(gameboy* gb);
uint8_t fetch_byte(gameboy* gb);
uint16_t fetch_word(gameboy* gb);

#endif