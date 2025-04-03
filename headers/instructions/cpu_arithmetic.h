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
#ifndef CPU_LOAD_H
#define CPU_LOAD_H

#include "../gameboy.h"
#include <stdint.h>

/**
 * @brief Additionne A avec r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int add_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Additionne A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int add_a_hl(gameboy* gb);

/**
 * @brief Additionne A avec n.
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
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int adc_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Additionne avec le carry, A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int adc_a_hl(gameboy* gb);

/**
 * @brief Additionne avec le carry, A avec n.
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
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int sub_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Soustrait A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int sub_a_hl(gameboy* gb);
/**
 * @brief Soustrait A avec n.
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
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int sbc_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Soustrait avec le carry, A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
 int sbc_a_hl(gameboy* gb);

/**
 * @brief Soustrait avec le carry, A avec n.
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
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int cp_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Compare A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int cp_a_hl(gameboy* gb);

/**
 * @brief Compare A avec n.
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
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int inc_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Incremente de 1 la valeur pointée par HL.
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
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int dec_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Decremente de 1 la valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int dec_hl(gameboy* gb);