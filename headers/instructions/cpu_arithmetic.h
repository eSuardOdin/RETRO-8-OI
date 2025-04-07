/**
* @file cpu_logic.h
* @author Thomas HUMBERT (RACé)
* @brief This file is used to implement all gameboy's cpu arithmetic instructions. This is done with the help of https://rgbds.gbdev.io/docs/v0.9.1/gbz80.7 
* @version 0.1
* @date 2025-03-23
* 
* @copyright Copyright (c) 2025
* 
*/
#ifndef CPU_ARITHMETIC_H
#define CPU_ARITHMETIC_H

#include "../gameboy.h"
#include <stdint.h>

/**
 * @brief Additionne A avec r8.
 * OPCODE : 0b10000 / 0x80
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int add_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Additionne A avec La valeur pointée par HL.
 * OPCODE : 0b10000110 / 0x86
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int add_a_hl(gameboy* gb);

/**
 * @brief Additionne A avec n.
 * OPCODE : 0b11000110 / 0xC6
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int add_a_n(gameboy* gb);

/*
=====================
    ADC
=====================
*/

/**
 * @brief Additionne avec le carry, A avec r8.
 * OPCODE : 0b10001 / 0x88
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int adc_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Additionne avec le carry, A avec La valeur pointée par HL.
 * OPCODE : 0b10001110 / 0x8E
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int adc_a_hl(gameboy* gb);

/**
 * @brief Additionne avec le carry, A avec n.
 * OPCODE : 0b11001110 / 0xCE
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int adc_a_n(gameboy* gb);

/*
=====================
    SUB
=====================
*/

/**
 * @brief Soustrait A avec r8.
 * OPCODE : 0b10010 / 0x90
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int sub_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Soustrait A avec La valeur pointée par HL.
 * OPCODE : 0b10010110 / 0x96
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int sub_a_hl(gameboy* gb);

/**
 * @brief Soustrait A avec n.
 * OPCODE : 0b11010110 / 0xD6
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int sub_a_n(gameboy* gb);

/*
=====================
    SBC
=====================
*/

/**
 * @brief Soustrait avec le carry, A avec r8.
 * OPCODE : 0b10011xxx / 0x98
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int sbc_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Soustrait avec le carry, A avec La valeur pointée par HL.
 * OPCODE : 0b10011110 / 0x9E
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
 int sbc_a_hl(gameboy* gb);

/**
 * @brief Soustrait avec le carry, A avec n.
 * OPCODE : 0b11011110 / 0xDE
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int sbc_a_n(gameboy* gb);

/*
=====================
    CP
=====================
*/

/**
 * @brief Compare A avec r8.
 * OPCODE : 0b10111 / 0xB8
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int cp_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Compare A avec La valeur pointée par HL.
 * OPCODE : 0b10011110 / 0x9E
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int cp_a_hl(gameboy* gb);

/**
 * @brief Compare A avec n.
 * OPCODE : 0b11111110 / 0xFE
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int cp_a_n(gameboy* gb);

/*
    INC
*/

/**
 * @brief Incremente de 1 r8.
 * OPCODE : 0b00xxx100 / 0x04
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int inc_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Incremente de 1 la valeur pointée par HL.
 * OPCODE : 0b00110100 / 0x34
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int inc_hl(gameboy* gb);

/*
    DEC
*/

/**
 * @brief Decremente de 1 r8.
 * OPCODE : 0b00xxx101 / 0x05
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int dec_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Decremente de 1 la valeur pointée par HL.
 * OPCODE : 0b00110101 / 0x35
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int dec_hl(gameboy* gb);

/**
 * @brief Set les flags pour les fonctions artihmetic.
 *
 * @author Thomas
 * @param carry le résultat du calcul.
 * @param is_sub boolean si le calcul est une soustraction
 */
void set_arithmetic_flags(int carry, int is_sub);


#endif