#include "../../headers/tests/test_cpu_control_flow.h"

int test_jp_nn(gameboy *gb)
{
    // JMP from 0x0 to 0x0110
    printf("jp_nn from 0x0 to 0x0110. (Using 4 cycles)\n");
    print_registers(gb);
    jp_nn(gb);
    print_registers(gb);

    if(gb->reg->pc != 0x0110)
    {
        fprintf(stderr, "jp_nn failed with a jump on value %0X\n", gb->reg->pc);
        return -1;
    }

    // JMP from 0x0110 to 0x4433
    printf("jp_nn from 0x0110 to 0x4433. (Using 4 cycles)\n");
    print_registers(gb);
    jp_nn(gb);
    print_registers(gb);

    if(gb->reg->pc != 0x4433)
    {
        fprintf(stderr, "jp_nn failed with a jump on value %0X\n", gb->reg->pc);
        return -1;
    }

    // JMP from 0x4433 to 0x7FFF
    printf("jp_nn from 0x4433 to 0x7FFF. (Using 4 cycles)\n");
    print_registers(gb);
    jp_nn(gb);
    print_registers(gb);

    if(gb->reg->pc != 0x7FFF)
    {
        fprintf(stderr, "jp_nn failed with a jump on value %0X\n", gb->reg->pc);
        return -1;
    }

    return 0;
}


int control_test_suite()
{
    gameboy* gb;
    gb = (gameboy*)malloc(sizeof(gameboy));
    reset_test_gameboy(gb, "src/tests/test_cpu_control_flow_rom");
    test_jp_nn(gb);

    free(gb);
    return 0;
}