#include "../../headers/instructions/cpu_arithmetic.h"
#include "../../headers/gameboy.h"
#include <stdint.h>
#include <stdio.h>


/*
    ARITHMETIC 
*/


/*
=====================
    ADD
=====================
*/


int add_a_r8(uint8_t opcode, gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src + *dst;
    int carry = *src + *dst;
    inc_cycle(gb);

    *dst = result;

    set_flags(gb,carry,1,0);
    return 0;
}


int add_a_hl(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src + *dst;
    int carry = *src + *dst;
    inc_cycle(gb);

    *dst = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}


int add_a_n(gameboy* gb){
    gb->reg->pc++;
    uint8_t n = get_byte(gb, gb->reg->pc);
    uint8_t dst = gb->reg->a;
    inc_cycle(gb);

    uint8_t result = n + dst;
    int carry = n + dst;
    inc_cycle(gb);

    gb->reg->a = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}

/*
=====================
    ADC
=====================
*/


int adc_a_r8(uint8_t opcode, gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src;
    uint8_t flag_c = gb->reg->f & 0b00010000;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src + *dst + flag_c;
    int carry = *src + *dst + flag_c;
    inc_cycle(gb);

    *dst = result;

    set_flags(gb,carry,1,0);
    return 0;
}


int adc_a_hl(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    uint8_t flag_c = gb->reg->f & 0b00010000;
    inc_cycle(gb);

    uint8_t result = *src + *dst + flag_c;
    int carry = *src + *dst + flag_c;
    inc_cycle(gb);

    *dst = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}


int adc_a_n(gameboy* gb){
    gb->reg->pc++;
    uint8_t src = get_byte(gb, gb->reg->pc);
    uint8_t dst = gb->reg->a;
    uint8_t flag_c = gb->reg->f & 0b00010000;
    inc_cycle(gb);

    uint8_t result = src + dst + flag_c;
    int carry = src + dst + flag_c;
    inc_cycle(gb);

    gb->reg->a = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}

/*
=====================
    SUB
=====================
*/


int sub_a_r8(uint8_t opcode, gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src - *dst;
    int carry = *src - *dst;
    inc_cycle(gb);

    *dst = result;

    set_flags(gb,carry,1,1);
    return 0;
}


int sub_a_hl(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src - *dst;
    int carry = *src - *dst;
    inc_cycle(gb);

    *dst = result;
    
    set_flags(gb,carry,1,1);
    return 0;
}


int sub_a_n(gameboy* gb){
    gb->reg->pc++;
    uint8_t src = get_byte(gb, gb->reg->pc);
    uint8_t dst = gb->reg->a;
    inc_cycle(gb);

    uint8_t result = src - dst;
    int carry = src - dst;
    inc_cycle(gb);

    gb->reg->a = result;
    
    set_flags(gb,carry,1,1);
    return 0;
}

/*
=====================
    SBC
=====================
*/


int sbc_a_r8(uint8_t opcode, gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src;
    uint8_t flag_c = gb->reg->f & 0b00010000;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src - *dst - flag_c;
    int carry = *src - *dst - flag_c;
    inc_cycle(gb);

    *dst = result;

    set_flags(gb,carry,1,1);
    return 0;
}


int sbc_a_hl(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    uint8_t flag_c = gb->reg->f & 0b00010000;
    inc_cycle(gb);

    uint8_t result = *src - *dst - flag_c;
    int carry = *src - *dst - flag_c;
    inc_cycle(gb);

    *dst = result;
    
    set_flags(gb,carry,1,1);
    return 0;
}


int sbc_a_n(gameboy* gb){
    gb->reg->pc++;
    uint8_t src = get_byte(gb, gb->reg->pc);
    uint8_t dst = gb->reg->a;
    uint8_t flag_c = gb->reg->f & 0b00010000;
    inc_cycle(gb);

    uint8_t result = src - dst - flag_c;
    int carry = src - dst - flag_c;
    inc_cycle(gb);

    gb->reg->a = result;
    
    set_flags(gb,carry,1,1);
    return 0;
}

/*
=====================
    CP
=====================
*/


int cp_a_r8(uint8_t opcode, gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src;

    // Get source register
    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src - *dst;
    int carry = *src - *dst;
    inc_cycle(gb);

    set_flags(gb,carry,1,1);
    return result;
}


int cp_a_hl(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src - *dst;
    int carry = *src - *dst;
    inc_cycle(gb);
    
    set_flags(gb,carry,1,1);
    return result;
}


int cp_a_n(gameboy* gb){
    gb->reg->pc++;
    uint8_t src = get_byte(gb, gb->reg->pc);
    uint8_t dst = gb->reg->a;
    inc_cycle(gb);

    uint8_t result = src - dst;
    int carry = src - dst;
    inc_cycle(gb);
    
    set_flags(gb,carry,1,1);
    return result;
}

/*
    INC
*/


int inc_r8(uint8_t opcode, gameboy* gb){
    uint8_t *src;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src + 1;
    int carry = *src + 1;
    inc_cycle(gb);

    *src = result;

    set_flags(gb,carry,1,0);
    return 0;
}


int inc_hl(gameboy* gb){
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src + 1;
    int carry = *src + 1;
    inc_cycle(gb);
    inc_cycle(gb);

    *src = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}

/*
    DEC
*/


int dec_r8(uint8_t opcode, gameboy* gb){
    uint8_t *src;

    uint8_t src_byte = opcode & 0x03;
    src = get_r8(src_byte, gb);
    uint8_t result = *src - 1;
    int carry = *src - 1;
    inc_cycle(gb);

    *src = result;

    set_flags(gb,carry,1,0);
    return 0;
}


int dec_hl(gameboy* gb){
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src - 1;
    int carry = *src - 1;
    inc_cycle(gb);
    inc_cycle(gb);

    *src = result;
    
    set_flags(gb,carry,1,0);
    return 0;
}