#include "../../headers/instructions/cpu_logic.h"
#include "../../headers/gameboy.h"
#include <stdint.h>
#include <stdio.h>


/*
    LOGIC 
*/


/*
=====================
    AND
=====================
*/


int and_a_r8(uint8_t opcode, gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src & *dst;

    //setup pour bloquer le flag C.
    int carry = *src & *dst;
    inc_cycle(gb);

    *dst = result;

    set_flags(gb,carry,1,0);
    return 0;
}


 int and_a_hl(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src & *dst;

    //setup pour bloquer le flag C.
    int carry = *src & *dst;
    inc_cycle(gb);

    *dst = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}

int and_a_n(gameboy* gb){
    gb->reg->pc++;
    uint8_t n = get_byte(gb, gb->reg->pc);
    uint8_t dst = gb->reg->a;
    inc_cycle(gb);

    uint8_t result = n & dst;

    //setup pour bloquer le flag C.
    int carry = n & dst;
    inc_cycle(gb);

    gb->reg->a = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}

/*
=====================
    OR
=====================
*/


int or_a_r8(uint8_t opcode, gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src | *dst;

    //setup pour bloquer le flag C.
    int carry = *src | *dst;
    inc_cycle(gb);

    *dst = result;

    set_flags(gb,carry,1,0);
    return 0;
}


int or_a_hl(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src | *dst;

    //setup pour bloquer le flag C.
    int carry = *src | *dst;
    inc_cycle(gb);

    *dst = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}


int or_a_n(gameboy* gb){
    gb->reg->pc++;
    uint8_t n = get_byte(gb, gb->reg->pc);
    uint8_t dst = gb->reg->a;
    inc_cycle(gb);

    uint8_t result = n | dst;

    //setup pour bloquer le flag C.
    int carry = n | dst;
    inc_cycle(gb);

    gb->reg->a = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}

/*
=====================
    XOR
=====================
*/


int xor_a_r8(uint8_t opcode, gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src ^ *dst;

    //setup pour bloquer le flag C.
    int carry = *src ^ *dst;
    inc_cycle(gb);

    *dst = result;

    set_flags(gb,carry,1,0);
    return 0;
}


int xor_a_hl(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src ^ *dst;

    //setup pour bloquer le flag C.
    int carry = *src ^ *dst;
    inc_cycle(gb);

    *dst = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}


int xor_a_n(gameboy* gb){
    gb->reg->pc++;
    uint8_t n = get_byte(gb, gb->reg->pc);
    uint8_t dst = gb->reg->a;
    inc_cycle(gb);

    uint8_t result = n ^ dst;

    //setup pour bloquer le flag C.
    int carry = n ^ dst;
    inc_cycle(gb);

    gb->reg->a = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}