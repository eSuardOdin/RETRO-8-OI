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
#include <stdint.h>

// ######### LD 8 bits #########
/**
 * @brief Copy the value from reg_y to reg_x.<br/>
 * OPCODE : 0b01xxxyyy<br/>
 * CYCLES : 1<br/>
 * LENGHT : 1<br/>
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_r8(uint8_t opcode, gameboy* gb);


/**
 * @brief Copy the next absolute value in memory into register.<br/>
 * OPCODE : 0b00xxx110 
 * CYCLES : 2<br/>
 * LENGHT : 2<br/>
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_n8(uint8_t opcode, gameboy* gb);  // Can be used to implement LD [HL], n8 ? Takes the same amount of cycles

/**
 * @brief Load data from memory address in [HL] into register.<br/>
 * OPCODE : 0b01xxx110 
 * CYCLES : 2<br/>
 * LENGHT : 1<br/>
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_hl(uint8_t opcode, gameboy* gb);


/**
 * @brief Copy the value into the adress pointed to by HL.
 * 
 * @param v Value to copy
 * @return 3 cycles
 */
int ld_hl_n8(uint8_t opcode, gameboy* gb);


/**
 * @brief Copy value in reg to the adress pointed to by HL
 * 
 * @param reg Register with value to copy
 * @return 2 cycles
 */
int ld_hl_r8(uint8_t opcode, gameboy* gb);










// ######### LD 16 bits #########
/**
 * @brief Copy the value of v into reg.
 * 
 * @param reg Destination register
 * @param v Value to copy
 * @return 3 cycles
 */
int ld_r16_n16(uint16_t *reg, uint16_t v);






/**
 * @brief Copies the value in A into byte pointed to by address
 * 
 * @param address_p The address pointer to memory to copy byte to
 * @param value The value to copy
 * @return 2 cycles
 */
int ld_r16_a(uint16_t address_p, uint8_t value);

/**
 * @brief Copies the value in A register to address
 * 
 * @param address Address to copy value to
 * @param value Value to copy
 * @return 4 cycles 
 */
int ld_n16_a(uint16_t address, uint8_t value);


/**
 * @brief Copy the value in register A into byte at address if address is between 0xFF00 and 0xFFFF
 * 
 * @param address 
 * @param value 
 * @return int 
 */
int ldh_n16_a(uint16_t address, uint8_t value);


#endif