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
    // Get destination register
    uint8_t dst_byte = (opcode & 0b00111000) >> 3;
    dst = get_r8(dst_byte, gb);

    // Increment cycle
    inc_cycle(gb);

    // Get [HL]
    src = get_address(gb, gb->reg->hl);
    
    // Assign value
    *dst = *src;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int ld_hl_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t *dst;
    uint8_t *src;

    // Get source register
    uint8_t src_byte = opcode & 0x07;
    src = get_r8(src_byte, gb);

    // Increment cycle
    inc_cycle(gb);

    // Get destination [HL]
    dst = get_address(gb, gb->reg->hl);

    // Assign value
    *dst = *src;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int ld_hl_n8(gameboy* gb)
{
    uint8_t *dst;
    uint8_t value;
    
    // Get destination [HL]
    dst = get_address(gb, gb->reg->hl);

    // Increment Cycle and PC
    inc_cycle(gb);
    gb->reg->pc++;

    // Get value
    value = read_memory(gb, gb->reg->pc);

    // Increment Cycle
    inc_cycle(gb);

    // Assign value
    *dst = value;

    // Increment Cycle
    inc_cycle(gb);
    return 0;
}


int ld_a_bc(gameboy *gb)
{
    uint8_t *src;
    
    // Get source [BC]
    src = get_address(gb, gb->reg->bc);

    // Increment cycle
    inc_cycle(gb);

    // Assign value
    gb->reg->a = *src;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int ld_a_de(gameboy *gb)
{
    uint8_t *src;
    
    // Get source [DE]
    src = get_address(gb, gb->reg->de);

    // Increment cycle
    inc_cycle(gb);

    // Assign value
    gb->reg->a = *src;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int ld_bc_a(gameboy* gb)
{
    uint8_t *dst;

    // Get destination register
    dst = get_address(gb, gb->reg->bc);

    // Increment cycle
    inc_cycle(gb);

    // Assign value
    *dst = gb->reg->a;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int ld_de_a(gameboy* gb)
{
    uint8_t *dst;

    // Get destination register
    dst = get_address(gb, gb->reg->de);

    // Increment cycle
    inc_cycle(gb);

    // Assign value
    *dst = gb->reg->a;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int ld_a_nn(gameboy *gb)
{
    uint16_t addr = 0;

    // Increment PC
    gb->reg->pc++;
    
    // Get LSB
    addr = read_memory(gb, gb->reg->pc);
    
    // Increment Cycle and PC
    inc_cycle(gb);
    gb->reg->pc++;
    
    // Get MSB
    addr = addr | ((uint16_t) read_memory(gb, gb->reg->pc) << 8);
    
    // Increment Cycle
    inc_cycle(gb);
    
    // Assign value
    gb->reg->a = read_memory(gb, addr);

    // Increment cycle
    inc_cycle(gb);
    return 0;
}