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
#ifndef CPU_LOAD_H
#define CPU_LOAD_H

#include "../gameboy.h"
#include <stdint.h>

 /**
 * @brief Performe un AND logique de A avec r8.
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int and_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Performe un AND logique de A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int and_a_hl(gameboy* gb);

/**
 * @brief Performe un AND logique de A avec n.
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
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int or_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Performe un OR logique de A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int or_a_hl(gameboy* gb);

/**
 * @brief Performe un OR logique avec le carry de A avec n.
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
 *
 * @author Thomas
 * @param opcode Opcode.
 * @param gb Instance de GameBoy.
 */
int xor_a_r8(uint8_t opcode, gameboy* gb);

/**
 * @brief Performe un XOR logique de A avec La valeur pointée par HL.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int xor_a_hl(gameboy* gb);

/**
 * @brief Performe un XOR logique avec le carry de A avec n.
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
void set_logic_flags(int carry, int is_h);

/**
 * @brief Performe un XOR logique avec le carry de A avec n.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int ccf(gameboy* gb);

/**
 * @brief Met le flag C à 1 et le flag N et H à 0.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int scf(gameboy* gb);

/**
 * @brief Flip le flage Z et C puis mets H à 0.
 *
 * @author Thomas
 * @param gb Instance de GameBoy.
 */
int daa(gameboy* gb);
