/**
* @file cpu_logic.h
* @author Thomas HUMBERT (RACé)
* @brief This file is used to implement all gameboy's cpu logic instructions. This is done with the help of https://rgbds.gbdev.io/docs/v0.9.1/gbz80.7 
* @version 0.1
* @date 2025-03-23
* 
* @copyright Copyright (c) 2025
* 
*/
#ifndef CPU_LOGIC_H
#define CPU_LOGIC_H

#include "../gameboy.h"
#include <stdint.h>

 /**
 * @brief Performe un AND logique de A avec r8.
 * OPCODE : 0b10100 / 0xA0
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int and_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Performe un AND logique de A avec La valeur pointée par HL.
 * OPCODE : 0b10100110 / 0xA6
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int and_a_hl(gameboy* gb);

/**
 * @brief Performe un AND logique de A avec n.
 * OPCODE : 0b11100110 / 0xE6
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int and_a_n(gameboy* gb);

/*
=====================
    OR
=====================
*/

/**
 * @brief Performe un OR logique de A avec r8.
 * OPCODE : 0b10110 / 0xB0
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int or_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Performe un OR logique de A avec La valeur pointée par HL.
 * OPCODE : 0b10110110 /  0xB6
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int or_a_hl(gameboy* gb);

/**
 * @brief Performe un OR logique avec le carry de A avec n.
 * OPCODE : 0b11110110 /  0xF6
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int or_a_n(gameboy* gb);

/*
=====================
    XOR
=====================
*/

/**
 * @brief Performe un XOR logique de A avec r8.
 * OPCODE : 0b10101 / 0xA8
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int xor_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Performe un XOR logique de A avec La valeur pointée par HL.
 * OPCODE : 0b10101110 / 0xAE
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int xor_a_hl(gameboy* gb);

/**
 * @brief Performe un XOR logique avec le carry de A avec n.
 * OPCODE : 0b11101110 / 0xEE
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int xor_a_n(gameboy* gb);

/**
 * @brief Set les flags pour les fonctions logic.
 *
 * @author Thomas
 * @param carry le résultat du calcul.
 * @param is_h boolean si H doit être activé.
 */
void set_logic_flags(gameboy *gb, int carry, int is_h, int is_sub);

/**
 * @brief Performe un XOR logique avec le carry de A avec n.
 * OPCODE : 0b00111111 / 0x3F
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int ccf(gameboy* gb);

/**
 * @brief Met le flag C à 1 et le flag N et H à 0.
 * OPCODE : 0b00110111 / 0x37
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int scf(gameboy* gb);

/**
 * @brief Flip le flage Z et C puis mets H à 0.
 * OPCODE : 0b00100111 / 0x27
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int daa(gameboy* gb);


#endif
