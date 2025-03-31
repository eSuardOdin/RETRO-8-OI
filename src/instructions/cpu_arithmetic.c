#include "../../headers/instructions/cpu_load.h"
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

/**
 * @brief Additionne A avec r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
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

/**
 * @brief Additionne A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Additionne A avec n.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Additionne avec le carry, A avec r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
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

/**
 * @brief Additionne avec le carry, A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Additionne avec le carry, A avec n.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Soustrait A avec r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
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

/**
 * @brief Soustrait A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Soustrait A avec n.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Soustrait avec le carry, A avec r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
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

/**
 * @brief Soustrait avec le carry, A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Soustrait avec le carry, A avec n.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Compare A avec r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
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

/**
 * @brief Compare A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Compare A avec n.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Incremente de 1 r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
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

/**
 * @brief Incremente de 1 la valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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

/**
 * @brief Decremente de 1 r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
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

/**
 * @brief Decremente de 1 la valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
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