/**
 * @file cpu_load.h
 * @author Erwann SUARD
 * @brief This file is used to implement all gameboy's cpu load instructions. This is done with the help of https://rgbds.gbdev.io/docs/v0.9.1/gbz80.7 
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef CPU_LOAD_H
#define CPU_LOAD_H

#include "../gameboy.h"
/**
 * @brief Copy the value from reg_y to reg_x.
 * 
 * @param reg_x Destination register
 * @param reg_y Source register
 * @return 1 cycle
 */
int ld_r8_r8(uint8_t *reg_x, uint8_t *reg_y);


/**
 * @brief Copy the value of v into reg.
 * 
 * @param reg Destination register
 * @param v Value to copy
 * @return 2 cycles
 */
int ld_r8_n8(uint8_t *reg, uint8_t v);  // Can be used to implement LD [HL], n8 ? Takes the same amount of cycles


/**
 * @brief Copy the value of v into reg.
 * 
 * @param reg Destination register
 * @param v Value to copy
 * @return 3 cycles
 */
int ld_r16_n16(uint16_t *reg, uint16_t v);


/**
 * @brief Copy value in reg to the adress pointed to by HL
 * 
 * @param reg Register with value to copy
 * @return 2 cycles
 */
int ld_hl_r8(uint8_t *reg);


/**
 * @brief Copy the value into the adress pointed to by HL.
 * 
 * @param v Value to copy
 * @return 3 cycles
 */
int ld_hl_n8(uint8_t v);


/**
 * @brief Copy value in adress pointed by HL to register.
 * 
 * @param reg Copy destination
 * @return 2 cycles
 */
int ld_r8_hl(uint8_t *reg);
#endif