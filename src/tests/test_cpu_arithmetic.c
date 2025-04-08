#include "../../headers/tests/test_cpu_arithmetic.h"
#include <stdint.h>
#include <stdio.h>

void display_reg(gameboy* gb){
    printf("=====================\n");
    printf("a :%d\n", gb->reg->a);
    printf("b :%d\n", gb->reg->b);
    printf("c :%d\n", gb->reg->c);
    printf("d :%d\n", gb->reg->d);
    printf("e :%d\n", gb->reg->e);
    printf("=====================\n");
}

void reset_reg(gameboy* gb){
    gb->reg->a = 0;
    gb->reg->b = 0;
    gb->reg->c = 0;
    gb->reg->d = 0;
    gb->reg->e = 0;
}

void test_add_r8(gameboy* gb){
    printf("ton pere\n");
    printf("ADD A+B\n");

    gb->reg->b = 5;
    display_reg(gb);
    
    uint8_t opcode = 0b10000000;
    add_a_r8(opcode,gb);
    display_reg(gb);

    reset_reg(gb);
    printf("ADD A+C\n");
    gb->reg->c = 3;
    display_reg(gb);

    opcode = 0b10000001;
    add_a_r8(opcode,gb);
    display_reg(gb);

    reset_reg(gb);
    printf("ADD A+D\n");
    gb->reg->d = 2;
    display_reg(gb);

    opcode = 0b10000010;
    add_a_r8(opcode,gb);
    display_reg(gb);
    reset_reg(gb);
}

void test_sub_r8(gameboy* gb){
    printf("ton pere\n");
    printf("ADD A-B\n");
    gb->reg->a = 10;
    gb->reg->b = 5;
    display_reg(gb);
    
    uint8_t opcode = 0b10010000;
    sub_a_r8(opcode,gb);
    display_reg(gb);

    reset_reg(gb);
    printf("ADD A-C\n");
    gb->reg->a = 10;
    gb->reg->c = 3;
    display_reg(gb);

    opcode = 0b10010001;
    sub_a_r8(opcode,gb);
    display_reg(gb);

    reset_reg(gb);
    printf("ADD A-D\n");
    gb->reg->a = 10;
    gb->reg->d = 2;
    display_reg(gb);

    opcode = 0b10010010;
    sub_a_r8(opcode,gb);
    display_reg(gb);
    
}