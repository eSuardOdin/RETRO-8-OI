#include "../../../headers/gameboy.h"
#include "../../../headers/cartridge.h"
#include "../../../headers/memory.h"
#include "../../../headers/memory_constants.h"
#include "../../../headers/instructions/cpu_instructions.h"
#include "../../../headers/instructions/cpu_load.h"

gameboy *gb;
void init_flag(){
    char* path = "Tetris.gb";
    reset_gameboy(gb, path);
}

void test_no_flag(void){
    init_flag();
    int r = set_flags(gb, 1, 0, 0);
    TEST_ASSERT_EQUAL(0b00000000, gb->reg->f);
}

void test_flag_Z(void){
    init_flag();
    int r = set_flags(gb, 0, 0, 0);
    TEST_ASSERT_EQUAL(0b10000000, gb->reg->f);
}

void test_flag_N(void){
    init_flag();
    int r = set_flags(gb, 1, 0, 1);
    TEST_ASSERT_EQUAL(0b01000000, gb->reg->f);
}

void test_flag_H(void){
    init_flag();
    int r = set_flags(gb, 16, 1, 0);
    TEST_ASSERT_EQUAL(0b00100000, gb->reg->f);
}

void test_flag_C_255(void){
    init_flag();
    int r = set_flags(gb, 256, 1, 0);
    TEST_ASSERT_EQUAL(0b00110000, gb->reg->f);
}

void test_flag_C_65535(void){
    init_flag();
    int r = set_flags(gb, 65536, 0, 0);
    TEST_ASSERT_EQUAL(0b00010000, gb->reg->f);
}