#ifndef CPU_INSTRUCTIONS_H
#define CPU_INSTRUCTIONS_H

#include <stdint.h>
#include <stdio.h>

#include "../gameboy.h"
#include "cpu_load.h"


/**
 * @brief Executes the instruction provided in argument
 * 
 * @param opcode The instruction to execute
 * @return TO DETERMINE
 */
uint8_t decode_execute_instruction(gameboy *gb, uint8_t opcode);


/**
 * @brief Just here to test cases waiting for something better
 * 
 * @param gb 
 */
void test_instructions(gameboy *gb);


#endif