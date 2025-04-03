#include <stdint.h>

#include "../../headers/gameboy.h"
#include "../../headers/cartridge.h"
#include "../../headers/memory.h"
#include "../../headers/memory_constants.h"
#include "../../headers/instructions/cpu_instructions.h"
#include "../../headers/instructions/cpu_load.h"

void init_ld(gameboy *gb){
    char* path = "Tetris.gb";
    gb = malloc(sizeof(gameboy));
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

#pragma region ld_r8_r8
// Load Instruction ld_r8_r8
void test_ld_r8_r8(void){
    gameboy *gb = malloc(sizeof(gameboy));
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

    ld_r8_r8(0b01111000, gb);
    uint8_t buff = gb->reg->b;
    free(gb);

    TEST_ASSERT_EQUAL(0x00, buff);
}

void test_ld_r8_r8_hl(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    
    ld_r8_r8(0b01110000, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);

    TEST_ASSERT_EQUAL(0x00, buff);
}
#pragma endregion

#pragma region ld_r8_n8
// Load Instruction ld_r8_n8
void test_ld_r8_n8_b(void){
    gameboy *gb = malloc(sizeof(gameboy));
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

    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00000110, gb);
    uint8_t buff = gb->reg->b;
    free(gb);

    TEST_ASSERT_EQUAL(0x66, buff);
}

void test_ld_r8_n8_c(void){
    gameboy *gb = malloc(sizeof(gameboy));
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

    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00001110, gb);
    uint8_t buff = gb->reg->c;
    free(gb);
    TEST_ASSERT_EQUAL(0x66, buff);
}

void test_ld_r8_n8_d(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00010110, gb);
    uint8_t buff = gb->reg->d;
    free(gb);
    TEST_ASSERT_EQUAL(0x66, buff);
}

void test_ld_r8_n8_e(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00011110, gb);
    uint8_t buff = gb->reg->e;
    free(gb);
    TEST_ASSERT_EQUAL(0x66, buff);
}

void test_ld_r8_n8_h(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00100110, gb);
    uint8_t buff = gb->reg->h;
    free(gb);
    TEST_ASSERT_EQUAL(0x66, buff);
}

void test_ld_r8_n8_l(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00101110, gb);
    uint8_t buff = gb->reg->l;
    free(gb);
    TEST_ASSERT_EQUAL(0x66, buff);
}

void test_ld_r8_n8_hl(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    uint8_t *value = get_address(gb, gb->reg->hl);
    *value = 0x66;
    ld_r8_n8(0b00110110, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x66, buff);
}

void test_ld_r8_n8_a(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_r8_n8(0b00111110, gb);
    uint8_t buff = gb->reg->a;
    free(gb);
    TEST_ASSERT_EQUAL(0x66, buff);
}
#pragma endregion

#pragma region ld_r8_hl
// Load Instruction ld_r8_hl
void test_ld_r8_hl_b(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_r8_hl(0b01000110, gb);
    uint8_t buff = gb->reg->b;
    free(gb);
    TEST_ASSERT_EQUAL(0x62, buff);
}

void test_ld_r8_hl_c(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_r8_hl(0b01001110, gb);
    uint8_t buff = gb->reg->c;
    free(gb);
    TEST_ASSERT_EQUAL(0x62, buff);
}

void test_ld_r8_hl_d(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_r8_hl(0b01010110, gb);
    uint8_t buff = gb->reg->d;
    free(gb);
    TEST_ASSERT_EQUAL(0x62, buff);
}

void test_ld_r8_hl_e(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_r8_hl(0b01011110, gb);
    uint8_t buff = gb->reg->e;
    free(gb);
    TEST_ASSERT_EQUAL(0x62, buff);
}

void test_ld_r8_hl_h(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_r8_hl(0b01100110, gb);
    uint8_t buff = gb->reg->h;
    free(gb);
    TEST_ASSERT_EQUAL(0x62, buff);
}

void test_ld_r8_hl_l(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_r8_hl(0b01101110, gb);
    uint8_t buff = gb->reg->l;
    free(gb);
    TEST_ASSERT_EQUAL(0x62, buff);
}

void test_ld_r8_hl_a(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_r8_hl(0b01111110, gb);
    uint8_t buff = gb->reg->a;
    free(gb);
    TEST_ASSERT_EQUAL(0x62, buff);
}
#pragma endregion

#pragma region ld_hl_r8
// Load Instruction ld_hl_r8
void test_ld_hl_r8_b(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_hl_r8(0b01110000, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x00, buff);
}

void test_ld_hl_r8_c(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_hl_r8(0b01110001, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x44, buff);
}

void test_ld_hl_r8_d(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_hl_r8(0b01110010, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x05, buff);
}

void test_ld_hl_r8_e(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_hl_r8(0b01110011, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x12, buff);
}

void test_ld_hl_r8_h(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    gb->reg->h = 0x54;
    ld_hl_r8(0b01110100, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x54, buff);
}

void test_ld_hl_r8_l(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    gb->reg->l = 0x41;
    ld_hl_r8(0b01110101, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x41, buff);
}

void test_ld_hl_r8_a(void){
    gameboy *gb = malloc(sizeof(gameboy));
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
    ld_hl_r8(0b01110111, gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x22, buff);
}

// Load Instructions ld_hl_n8
void test_ld_hl_n8(void){
    gameboy *gb = malloc(sizeof(gameboy));
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

    uint8_t *value = get_address(gb, gb->reg->pc + 1);
    *value = 0x66;
    ld_hl_n8(gb);
    uint8_t buff = get_byte(gb, gb->reg->hl);
    free(gb);
    TEST_ASSERT_EQUAL(0x66, buff);

}
#pragma endregion

