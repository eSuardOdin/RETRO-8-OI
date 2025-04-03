#include "unity.c"
#include <stdlib.h>

#include "../headers/gameboy.h"
#include "../headers/cartridge.h"
#include "../headers/memory.h"
#include "../headers/memory_constants.h"
#include "../headers/instructions/cpu_instructions.h"
#include "../headers/instructions/cpu_load.h"
#include "opcode/flags/set_flags.c"
#include "opcode/load_instruction.c"


gameboy *gb;
void setUp(){

}

void tearDown(){

}

void test(){

}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage : ./gb ROM_FILE\n");
        exit(EXIT_FAILURE);
    }

    // Init gameboy
    gb = malloc(sizeof(gameboy));
    reset_gameboy(gb, argv[1]);

    UNITY_BEGIN();

    //FLAGS TEST
    RUN_TEST(test_no_flag);
    RUN_TEST(test_flag_Z);
    RUN_TEST(test_flag_N);
    RUN_TEST(test_flag_H);
    RUN_TEST(test_flag_C_255);
    RUN_TEST(test_flag_C_65535);

    //LOAD INSTRUCTIONS TEST
    //LD_R8_R8
    RUN_TEST(test_ld_r8_r8);
    RUN_TEST(test_ld_r8_r8_hl);
    //LD_R8_N8
    RUN_TEST(test_ld_r8_n8_b);
    RUN_TEST(test_ld_r8_n8_c);
    RUN_TEST(test_ld_r8_n8_d);
    RUN_TEST(test_ld_r8_n8_e);
    RUN_TEST(test_ld_r8_n8_h);
    RUN_TEST(test_ld_r8_n8_l);
    RUN_TEST(test_ld_r8_n8_hl);
    RUN_TEST(test_ld_r8_n8_a);
    //LD_R8_HL
    RUN_TEST(test_ld_r8_hl_b);
    RUN_TEST(test_ld_r8_hl_c);
    RUN_TEST(test_ld_r8_hl_d);
    RUN_TEST(test_ld_r8_hl_e);
    RUN_TEST(test_ld_r8_hl_l);
    RUN_TEST(test_ld_r8_hl_h);
    RUN_TEST(test_ld_r8_hl_a);
    //LD_HL_R8
    RUN_TEST(test_ld_hl_r8_b);
    RUN_TEST(test_ld_hl_r8_c);
    RUN_TEST(test_ld_hl_r8_d);
    RUN_TEST(test_ld_hl_r8_e);
    RUN_TEST(test_ld_hl_r8_h);
    RUN_TEST(test_ld_hl_r8_l);
    RUN_TEST(test_ld_hl_r8_a);

    //LD_HL_N8
    RUN_TEST(test_ld_hl_n8);

    UNITY_END();
    return 0;
}

