#include "../../headers/instructions/cpu_instructions.h"
#include <stdint.h>

uint8_t fetch_instruction(gameboy* gb)
{
    return gb->ram[gb->reg->pc++];
}

uint8_t get_byte(gameboy* gb, uint16_t addr)
{
    return gb->ram[addr];
}

uint16_t get_word(gameboy *gb, uint16_t addr)
{
    return (gb->ram[addr] << 8) | gb->ram[addr+1];
}

