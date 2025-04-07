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

    set_logic_flags(carry, 1);
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
    
    set_logic_flags(carry, 1);
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
    
    set_logic_flags(carry, 1);
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

    set_logic_flags(carry, 0);
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
    
    set_logic_flags(carry, 0);
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
    
    set_logic_flags(carry, 0);
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

    set_logic_flags(carry, 0);
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
    
    set_logic_flags(carry, 0);
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
    
    set_logic_flags(carry, 0);
    return 0;
}

/*
=====================
    FLAGS
=====================
*/

void set_logic_flags(int carry, int is_h){

    //Si c'est un AND C=1, Si c'est un OR/XOR C=0
    int a,b = 0;
    if(!is_h)
        b = 20;

    set_Z_flags(gb,carry);
    set_N_flag(gb, is_sub);
    set_H_flag(gb, a, b, 1);
    set_C_flag(gb, carry, 1);
}

int ccf(gameboy* gb){
    set_N_flag(gb, 0);
    set_H_flag(gb, 0, 0, 1);
    //Flip la valeur de C
    gb->reg->f = gb->reg->f ^ 0b00010000;

    return 0;
}

int scf(gameboy* gb){
    set_N_flag(gb, 0);
    set_H_flag(gb, 0, 0, 1);
    set_C_flag(gb, 300, 1);

    return 0;
}

int daa(gameboy* gb){
    //Flip la valeur de Z
    gb->reg->f = gb->reg->f ^ 0b10000000;
    set_H_flag(gb, 0, 0, 1);
    //Flip la valeur de C 
    gb->reg->f = gb->reg->f ^ 0b00010000;

    return 0;
}

