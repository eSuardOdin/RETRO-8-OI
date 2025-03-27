#include "../../headers/instructions/cpu_instructions.h"
#include <stdint.h>

uint8_t fetch_instruction(gameboy* gb)
{
    // Increment Cycles and PC (while returning)
    inc_cycle(gb);
    uint8_t res = read_memory(gb, gb->reg->pc);
    gb->reg->pc++;
    return res;
}

uint8_t get_byte(gameboy* gb, uint16_t addr)
{
    return read_memory(gb, addr);
}

uint16_t get_word(gameboy *gb, uint16_t addr)
{
    return (read_memory(gb, addr) << 8) | read_memory(gb, addr+1);
}

