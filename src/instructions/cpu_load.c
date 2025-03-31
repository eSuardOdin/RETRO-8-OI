#include "../../headers/instructions/cpu_load.h"
#include "../../headers/gameboy.h"
#include <stdint.h>
#include <stdio.h>
/*
    8 Bits LD
*/
int ld_r8_r8(uint8_t opcode, gameboy *gb)
{
    // Get the registers
    uint8_t *src;
    uint8_t *dst;
    uint8_t dst_byte = (opcode & 0b00111000) >> 3;
    uint8_t src_byte = opcode & 0b00000111;
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


int ld_nn_a(gameboy *gb)
{
    uint16_t dst_addr = 0;
    uint8_t *dst;
    // Increment PC
    gb->reg->pc++;
    
    // Get LSB
    dst_addr = read_memory(gb, gb->reg->pc);
    
    // Increment Cycle and PC
    inc_cycle(gb);
    gb->reg->pc++;
    
    // Get MSB
    dst_addr = dst_addr | ((uint16_t) read_memory(gb, gb->reg->pc) << 8);
    //printf("### DST : %04x. ###\n", dst_addr);
    // Increment Cycle
    inc_cycle(gb);
    
    // Get target pointer and assign value
    dst = get_address(gb, dst_addr);
    *dst = gb->reg->a;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int ldh_a_c(gameboy *gb)
{
    // Get source data
    uint8_t data = get_byte(gb, 0xff00 | gb->reg->c);

    // Increment Cycles
    inc_cycle(gb);

    // Assign value
    gb->reg->a = data;

    // Increment cycles
    inc_cycle(gb);
    return 0;
}


int ldh_c_a(gameboy *gb)
{
    // Get dst pointer 
    uint8_t *dst = get_address(gb, 0xff00 | gb->reg->c);

    // Increment Cycle
    inc_cycle(gb);

    // Assign value
    *dst = gb->reg->a;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int ldh_a_n(gameboy *gb)
{
    uint16_t dst;
    
    // Increment Cycle
    inc_cycle(gb);

    // Increment PC and cycle
    gb->reg->pc++;
    inc_cycle(gb);

    // Assign LSB
    dst = 0xff00 | get_byte(gb, gb->reg->pc);

    // Assign Value
    gb->reg->a = get_byte(gb, dst);

    // Increment Cycle
    inc_cycle(gb);
    return 0;
}//


