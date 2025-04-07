#include "../../headers/instructions/cpu_rotate.h"
#include "../../headers/gameboy.h"
#include <stdint.h>
#include <stdio.h>


int r_lc_a(gameboy* gb)
{
    uint8_t* reg;
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b10000000, fmask = 0b11100000;

    //get register value
    reg = get_address(gb, gb->reg->a);

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte >> 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    *reg += last_byte;
    
    //Set the carry flag;
    last_byte = last_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    return 0;
}

int r_rc_a(gameboy* gb)
{
    uint8_t* reg;
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get register value
    reg = get_address(gb, gb->reg->a);

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte << 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    *reg += last_byte;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    return 0;
}

int r_l_a(gameboy* gb)
{
    uint8_t* reg;
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b10000000, fmask = 0b11100000;

    //get register value
    reg = get_address(gb, gb->reg->a);

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte >> 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    
    //Set the carry flag;
    last_byte = last_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    return 0;
}

int r_r_a(gameboy* gb)
{
    uint8_t* reg;
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get register value
    reg = get_address(gb, gb->reg->a);

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte << 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    return 0;
}

int r_lc_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b10000000, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte >> 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    *reg += last_byte;
    
    //Set the carry flag;
    last_byte = last_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int r_lc_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b10000000, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte >> 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    *reg += last_byte;
    
    //Set the carry flag;
    last_byte = last_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int r_rc_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte << 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    *reg += last_byte;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int r_rc_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte << 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    *reg += last_byte;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int r_l_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b10000000, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte >> 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    
    //Set the carry flag;
    last_byte = last_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int r_l_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b10000000, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte >> 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    
    //Set the carry flag;
    last_byte = last_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int r_r_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte << 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int r_r_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte << 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int s_la_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b10000000, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte >> 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    
    //Set the carry flag;
    last_byte = last_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int s_la_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b10000000, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte >> 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    
    //Set the carry flag;
    last_byte = last_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int s_ra_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte << 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int s_ra_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get last_byte
    last_byte = *reg & mask;
    last_byte = last_byte << 7;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int swap_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t value;
    uint8_t last_bytes;
    uint8_t mask = 0b11110000;

    last_bytes = *reg & mask;

    *reg = *reg << 4;
    *reg += last_bytes;

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int swap_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t last_bytes;
    uint8_t mask = 0b11110000;

    last_bytes = *reg & mask;

    *reg = *reg << 4;
    *reg += last_bytes;

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}
