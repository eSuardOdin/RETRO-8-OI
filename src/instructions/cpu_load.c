#include "../../headers/instructions/cpu_load.h"
#include "../../headers/gameboy.h"
#include <stdint.h>
/*
    8 Bits LD
*/
int ld_r8_r8(uint8_t opcode, gameboy *gb)
{
    // Get the registers
    uint8_t *src;
    uint8_t *dst;
    uint8_t dst_byte = (opcode & 0b00111000) >> 3;
    uint8_t src_byte = (opcode & 0b00000111) >> 3;
    dst = get_r8(dst_byte, gb);
    src = get_r8(src_byte, gb);

    // Increment Cycle
    inc_cycle(gb);
    
    // LD Registers
    *dst = *src;
    return 0;
}



int ld_r8_n8(uint8_t opcode, gameboy *gb)
{
    uint8_t value;
    uint8_t *dst;
    uint8_t dst_byte = (opcode & 0b00111000) >> 3;
    // Get destination register
    dst = get_r8(dst_byte, gb);

    // Increment Cycle and PC
    inc_cycle(gb);
    gb->reg->pc++;

    // Get immediate value
    inc_cycle(gb);
    value = read_memory(gb, gb->reg->pc);

    // Assign value
    *dst = value;
    return 0;
}


int ld_r8_hl(uint8_t opcode, gameboy *gb)
{
    uint8_t *dst;
    uint8_t *src;

    uint8_t dst_byte = (opcode & 0b00111000) >> 3;
    dst = get_r8(dst_byte, gb);
    return 0;
}