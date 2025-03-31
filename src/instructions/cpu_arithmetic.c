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
int add_hl_a(gameboy* gb){
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
int sub_hl_a(gameboy* gb){
    uint8_t *dst = &gb->reg->a;
    uint8_t *src = get_address(gb, gb->reg->hl);
    inc_cycle(gb);

    uint8_t result = *src - *dst;
    int carry = *src - *dst;
    inc_cycle(gb);

    *dst = result;
    
    set_flags(gb,carry,1,0);
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

    *dst = result;

    set_flags(gb,carry,1,1);
    return result;
}

