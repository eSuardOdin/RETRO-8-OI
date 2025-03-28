#ifndef CPU_INSTRUCTIONS_H
#define CPU_INSTRUCTIONS_H

#include <stdint.h>
#include <stdio.h>

#include "../gameboy.h"
#include "cpu_load.h"


/**
 * @brief Fetch the next instruction pointed to by Program Counter to put it in IR or variable
 * 
 * @param gb The gameboy to get CPU Program Counter from
 * @return The next instruction
 */
uint8_t fetch_instruction(gameboy* gb);

/**
 * @brief Executes the instruction provided in argument
 * 
 * @param opcode The instruction to execute
 * @return Number of M-cycles elapsed
 */
uint8_t execute_instruction(uint8_t opcode);


/**
 * @brief Just here to test cases waiting for something better
 * 
 * @param gb 
 */
void test_instructions(gameboy *gb);


#endif