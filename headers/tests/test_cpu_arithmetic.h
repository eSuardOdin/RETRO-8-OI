/**
 * @file cartridge.h
 * @author Thomas HUMBERT (RACé)
 * @brief ça fait des tests
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #ifndef TEST_CPU_ARITHMETIC_H
 #define TEST_CPU_ARITHMETIC_H
 
 #include <stdint.h>
#include "../gameboy.h"
#include "../instructions/cpu_arithmetic.h"
/**
 * @brief Display the value of the reg
 */
void display_reg(gameboy* gb);

/**
 * @brief Put every reg at 0
 */
void reset_reg(gameboy* gb);

/**
 * @brief test the add_r8 function
 */
void test_add_r8(gameboy* gb);

/**
 * @brief test the sub_r8 function
 */
void test_sub_r8(gameboy* gb);

#endif