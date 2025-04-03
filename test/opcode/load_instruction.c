#include <stdint.h>

#include "../../headers/gameboy.h"
#include "../../headers/cartridge.h"
#include "../../headers/memory.h"
#include "../../headers/memory_constants.h"
#include "../../headers/instructions/cpu_instructions.h"
#include "../../headers/instructions/cpu_load.h"

gameboy *gb;
void init_ld(){
    char* path = "Tetris.gb";
    reset_gameboy(gb, path);
    gb->reg->a = 0x22;
    gb->reg->b = 0x00;
    gb->reg->c = 0x44;
    gb->reg->d = 0x05;
    gb->reg->e = 0x12;
    gb->reg->f = 0xe3;
    gb->reg->h = 0x54;
    gb->reg->l = 0x41;
    gb->reg->hl = 0xff43;
    *(get_address(gb, gb->reg->hl)) = 0x62;
}

// Load Instruction ld_r8_r8
void test_ld_r8_r8(void){
    init_ld();
    ld_r8_r8(0b01111000, gb);
    TEST_ASSERT_EQUAL(0x00, gb->reg->b);
}

void test_ld_r8_r8_hl(void){
    init_ld();
    ld_r8_r8(0b01110000, gb);
    TEST_ASSERT_EQUAL(get_byte(gb, gb->reg->hl), gb->reg->b);
}


// Load Instruction ld_r8_n8
void test_ld_r8_n8_b(void){
    init_ld();
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00000110, gb);
    TEST_ASSERT_EQUAL(0x66, gb->reg->b);
}

void test_ld_r8_n8_c(void){
    init_ld();
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00001110, gb);
    TEST_ASSERT_EQUAL(0x66, gb->reg->c);
}

void test_ld_r8_n8_d(void){
    init_ld();
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00010110, gb);
    TEST_ASSERT_EQUAL(0x66, gb->reg->d);
}

void test_ld_r8_n8_e(void){
    init_ld();
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00011110, gb);
    TEST_ASSERT_EQUAL(0x66, gb->reg->e);
}

void test_ld_r8_n8_h(void){
    init_ld();
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00100110, gb);
    TEST_ASSERT_EQUAL(0x66, gb->reg->h);
}

void test_ld_r8_n8_l(void){
    init_ld();
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00101110, gb);
    TEST_ASSERT_EQUAL(0x66, gb->reg->l);
}

void test_ld_r8_n8_hl(void){
    init_ld();
    uint8_t *value = get_address(gb, gb->reg->hl);
    *value = 0x66;
    ld_r8_n8(0b00110110, gb);
    TEST_ASSERT_EQUAL(0x66, get_byte(gb, gb->reg->hl));
}

void test_ld_r8_n8_a(void){
    init_ld();
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00111110, gb);
    TEST_ASSERT_EQUAL(0x66, gb->reg->a);
}


// Load Instruction ld_r8_hl
void test_r8_hl_b(){
    init_ld();
    ld_r8_hl(0b01000110, gb);
    TEST_ASSERT_EQUAL(0x62, gb->reg->b);
}

void test_r8_hl_c(){
    init_ld();
    ld_r8_hl(0b01001110, gb);
    TEST_ASSERT_EQUAL(0x62, gb->reg->c);
}

void test_r8_hl_d(){
    init_ld();
    ld_r8_hl(0b01010110, gb);
    TEST_ASSERT_EQUAL(0x62, gb->reg->d);
}

void test_r8_hl_e(){
    init_ld();
    ld_r8_hl(0b01011110, gb);
    TEST_ASSERT_EQUAL(0x62, gb->reg->e);
}

void test_r8_hl_h(){
    init_ld();
    ld_r8_hl(0b01100110, gb);
    TEST_ASSERT_EQUAL(0x62, gb->reg->h);
}

void test_r8_hl_l(){
    init_ld();
    ld_r8_hl(0b01101110, gb);
    TEST_ASSERT_EQUAL(0x62, gb->reg->l);
}

void test_r8_hl_a(){
    init_ld();
    ld_r8_hl(0b01111110, gb);
    TEST_ASSERT_EQUAL(0x62, gb->reg->a);
}


// Load Instruction ld_hr_r8
void test_hl_r8_b(){
    init_ld();
    ld_hl_r8(0b110000, gb);
    TEST_ASSERT_EQUAL(0x00, get_byte(gb, gb->reg->hl));
}

void test_hl_r8_c(){
    init_ld();
    ld_hl_r8(0b110001, gb);
    TEST_ASSERT_EQUAL(0x44, get_byte(gb, gb->reg->hl));
}

void test_hl_r8_d(){
    init_ld();
    ld_hl_r8(0b110010, gb);
    TEST_ASSERT_EQUAL(0x05, get_byte(gb, gb->reg->hl));
}

void test_hl_r8_e(){
    init_ld();
    ld_hl_r8(0b110011, gb);
    TEST_ASSERT_EQUAL(0x12, get_byte(gb, gb->reg->hl));
}

void test_hl_r8_h(){ // To check
    init_ld();
    printf("%d\n",get_byte(gb, gb->reg->hl));
    ld_hl_r8(0b110100, gb);
    printf("%d\n",get_byte(gb, gb->reg->hl));
    TEST_ASSERT_EQUAL(0x54, get_byte(gb, gb->reg->hl));
}

void test_hl_r8_l(){ // To check
    init_ld();
    printf("%d\n", get_byte(gb, gb->reg->hl));
    ld_hl_r8(0b110101, gb);
    printf("%d\n",get_byte(gb, gb->reg->hl));
    TEST_ASSERT_EQUAL(0x41, get_byte(gb, gb->reg->hl));
}

void test_hl_r8_a(){
    init_ld();
    ld_hl_r8(0b110111, gb);
    TEST_ASSERT_EQUAL(0x22, get_byte(gb, gb->reg->hl));
}
