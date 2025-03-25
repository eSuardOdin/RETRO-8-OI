#ifndef CPU_INSTRUCTIONS_H
#define CPU_INSTRUCTIONS_H

#include <stdint.h>
#include "../gameboy.h"

/**
 * @brief Fetch the next instruction pointed to by Program Counter to put it in IR or variable
 * 
 * @param pc The CPU Program Counter
 * @return The next instruction
 */
uint8_t fetch_instruction(uint16_t pc);

/**
 * @brief Executes the instruction provided in argument
 * 
 * @param opcode The instruction to execute
 * @return Number of M-cycles elapsed
 */
uint8_t execute_instruction(uint8_t opcode);

/**
 * @brief Get the byte in memory correponding with addr and return it.
 * 
 * @param addr The addr where to get the byte
 * @return The byte pointed to.
 */
uint8_t get_byte(uint16_t addr);

/**
 * @brief Get the byte in memory correponding with addr and return it.
 * 
 * @param addr The addr where to get the byte
 * @return The word pointed to.
 */
uint16_t get_word(uint16_t addr);




#endif