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
/**
 * @brief Copy the value from reg_b to reg_a. Takes 1 cycle.
 * 
 * @param reg_a Destination register
 * @param reg_b Source register
 * @return int 
 */
int ld_r8_r8(uint8_t *reg_a, uint8_t *reg_b);
/**
 * @brief Copy the value of v into reg. Takes 2 cycles
 * 
 * @param reg Destination register
 * @param v Value to copy
 * @return int 
 */
int ld_r8_n8(uint8_t *reg, uint8_t v);  // Can be used to implement LD [HL], n8 ? Takes the same amount of cycles
/**
 * @brief Copy the value of v into reg. Takes 3 cycles
 * 
 * @param reg Destination register
 * @param v Value to copy
 * @return int 
 */
int ld_r16_n16(uint16_t *reg, uint16_t v);
/**
 * @brief Copy value in reg to the adress pointed to by HL
 * 
 * @param reg Register with value to copy
 * @return int 
 */
int ld_hl_r8(uint8_t *reg);
/**
 * @brief Copy the value into the adress pointed to by HL. Takes 3 cycles
 * 
 * @param v Value to copy
 * @return int 
 */
int ld_hl_n8(uint8_t v);
#endif