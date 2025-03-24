#include "gameboy.h"
#include <string.h>

void reset_gameboy(gameboy *gb)
{
    memset(gb, 0, sizeof(gameboy));
    gb->reg->pc = 0x0100;
}

uint8_t fetch_opcode(gameboy* gb);
uint8_t fetch_byte(gameboy* gb);
uint16_t fetch_word(gameboy* gb);