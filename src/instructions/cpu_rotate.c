#include "../../headers/instructions/cpu_rotate.h"
#include "../../headers/gameboy.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>


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

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

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

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    *reg &= 0b01111111;
    *reg += last_byte;
    
    //Set the carry flag;
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    set_Z_flags(gb, *reg);

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

    //shift left and shift 7th bit to the first one
    *reg = *reg << 1;
    *reg &= 0b01111111;
    *reg += last_byte;
    
    //Set the carry flag
    last_byte = last_byte >> 3;
    gb->reg->f &= fmask;
    gb->reg->f |= last_byte;

    set_Z_flags(gb, *reg);

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
    uint8_t first_byte;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, lmask = 0b10000000, fmask = 0b11100000;

    //get last_byte
    first_byte = *reg & mask;
    last_byte = *reg & lmask;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    *reg &= 0b01111111;
    *reg += last_byte;
    
    //Set the carry flag
    first_byte = first_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= first_byte;

    set_Z_flags(gb, *reg);

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int s_ra_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t first_byte;
    uint8_t last_byte;
    uint8_t mask = 0b00000001, lmask = 0b10000000, fmask = 0b11100000;

    //get last_byte
    first_byte = *reg & mask;
    last_byte = *reg & lmask;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    *reg &= 0b01111111;
    *reg += last_byte;
    
    //Set the carry flag
    first_byte = first_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= first_byte;

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

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

    set_Z_flags(gb, *reg);

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int s_rl_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t value;
    uint8_t first_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get last_byte
    first_byte = *reg & mask;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    
    //Set the carry flag
    first_byte = first_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= first_byte;

    set_Z_flags(gb, *reg);

    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int s_rl_hl(gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t value;
    uint8_t first_byte;
    uint8_t mask = 0b00000001, fmask = 0b11100000;

    //get last_byte
    first_byte = *reg & mask;

    //shift left and shift 7th bit to the first one
    *reg = *reg >> 1;
    
    //Set the carry flag
    first_byte = first_byte << 4;
    gb->reg->f &= fmask;
    gb->reg->f |= first_byte;

    set_Z_flags(gb, *reg);

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}

int bit_b_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t byte_pos = opcode & 0b00111000 >> 3;
    uint8_t byte = *reg >> byte_pos;
    byte = byte & 0b00000001;

    set_Z_flags(gb, byte);
    gb->reg->f |= 0b00100000;

    inc_cycle(gb);
    inc_cycle(gb);
}

int bit_b_hl(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t byte_pos = opcode & 0b00111000 >> 3;
    uint8_t byte = *reg >> byte_pos;
    byte = byte & 0b00000001;

    set_Z_flags(gb, byte);
    gb->reg->f |= 0b00100000;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
}

int res_b_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t byte_pos = opcode & 0b00111000 >> 3;
    uint8_t mask = 0b11111110;
    mask = mask << byte_pos;
    mask += pow(2, byte_pos) - 1;

    *reg &= mask;

    inc_cycle(gb);
    inc_cycle(gb);
}

int res_b_hl(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t byte_pos = opcode & 0b00111000 >> 3;
    uint8_t mask = 0b11111110;
    mask = mask << byte_pos;
    mask += pow(2, byte_pos) - 1;

    *reg &= mask;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
}

int set_b_r8(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_r8(opcode & 0b00000111, gb);
    uint8_t byte_pos = opcode & 0b00111000 >> 3;
    uint8_t mask = 0b00000001;
    mask = mask << byte_pos;

    *reg |= mask;

    inc_cycle(gb);
    inc_cycle(gb);
}

int set_b_hl(uint8_t opcode, gameboy* gb)
{
    uint8_t* reg = get_address(gb, gb->reg->hl);
    uint8_t byte_pos = opcode & 0b00111000 >> 3;
    uint8_t mask = 0b00000001;
    mask = mask << byte_pos;

    *reg |= mask;

    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
    inc_cycle(gb);
}
