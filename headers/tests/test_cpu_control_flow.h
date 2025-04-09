#ifndef TEST_CPU_CONTROL_FLOW_H
#define TEST_CPU_CONTROL_FLOW_H
#include "../../headers/gameboy.h"
#include "../../headers/memory_constants.h"
#include "../../headers/instructions/cpu_control_flow.h"
#include <stdio.h>
#include <stdlib.h>

int control_test_suite();

int test_jp_nn(gameboy *gb);

/**
 * @brief Used to check if jp is well done
 * 
 * @param target_address 
 * @param target_cycle 
 * @return int 
 */
int check_jp(gameboy* gb, uint16_t target_address, uint32_t target_cycle);

#endif