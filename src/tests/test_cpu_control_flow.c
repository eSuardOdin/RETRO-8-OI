#include "../../headers/tests/test_cpu_control_flow.h"
#include <stdint.h>


int check_jp(gameboy* gb, uint16_t target_address, uint32_t target_cycle)
{
    if(gb->reg->pc != target_address)
    {
        fprintf(stderr, "jump failed with a jump on value %0X\n", gb->reg->pc);
        return 1;
    }
    if(gb->m_cycles != target_cycle)
    {
        fprintf(stderr, "jump failed, bad cycle value on exit: %d\n", gb->m_cycles);
        return 1;
    }
    return 0;
}


int test_jp_nn(gameboy *gb)
{
    uint32_t cycles = gb->m_cycles;

    // --- Unconditionnal jumps to next bytes N address ---
    // JMP from 0x0 to 0x0110
    printf("####################################################\n");
    printf("jp_nn from 0 to 0110. (Using 4 cycles)\n");
    print_registers(gb);
    jp_nn(gb);
    print_registers(gb);
    if(check_jp(gb, 0x0110, cycles+4)) return 1;
    cycles = gb->m_cycles;

    
    // JMP from 0x0110 to 0x4433
    printf("####################################################\n");
    printf("jp_nn from 0x0110 to 4433. (Using 4 cycles)\n");
    print_registers(gb);
    jp_nn(gb);
    print_registers(gb);
    if(check_jp(gb, 0x4433, cycles+4)) return 1;
    cycles = gb->m_cycles;


    // JMP from 0x4433 to 0x7FFF
    printf("####################################################\n");
    printf("jp_nn from 0x4433 to 7FFF. (Using 4 cycles)\n");
    print_registers(gb);
    jp_nn(gb);
    print_registers(gb);
    if(check_jp(gb, 0x7fff, cycles+4)) return 1;
    cycles = gb->m_cycles;


    // --- Unconditionnal jumps to [HL] ---
    // JMP from 0x7FFF to 0x3A50
    gb->reg->hl = 0x3a50;
    printf("####################################################\n");
    printf("jp_hl from 0x7FFF to [HL] (%04X). (Using 1 cycles)\n", gb->reg->hl);
    print_registers(gb);
    jp_hl(gb);
    print_registers(gb);
    if(check_jp(gb, gb->reg->hl, cycles+1)) return 1;
    cycles = gb->m_cycles;


    // JMP from 0x3A50 to 0x23A1
    gb->reg->hl = 0x23a1;
    printf("####################################################\n");
    printf("jp_hl from %04X to [HL] (%04X). (Using 1 cycles)\n",gb->reg->pc , gb->reg->hl);
    print_registers(gb);
    jp_hl(gb);
    print_registers(gb);
    if(check_jp(gb, gb->reg->hl, cycles+1)) return 1;
    cycles = gb->m_cycles;



    
    // --- Conditionnal jumps ---
    // 0: NZ | 1: Z | 2: NC | 3: C

    // jp_cc_nn : 0b110xx010
    // ---- opcode A2 (condition on NZ) ----
    // Don't JMP from 0x23A1 to 0x23A3 (NZ = 0)
    gb->reg->f = 0x80; // Flag Zero set
    printf("####################################################\n");
    printf("jp_cc_nn from %04X to %04X (condition not met, using 3 cycles)\n", gb->reg->pc, gb->reg->pc+3);
    print_registers(gb);
    jp_cc_nn(gb, 0xa2);
    print_registers(gb);
    if(check_jp(gb, 0x23A3, cycles+3)) return 1;
    cycles = gb->m_cycles;

    // JMP from 0x23A3 to 0x3020    (NZ = 1)
    gb->reg->f = 0x0; // Flag Zero unset
    printf("####################################################\n");
    printf("jp_cc_nn from %04X to 3020 (condition met, using 4 cycles)\n", gb->reg->pc);
    print_registers(gb);
    jp_cc_nn(gb, 0xa2);
    print_registers(gb);
    if(check_jp(gb, 0x3020, cycles+4)) return 1;
    cycles = gb->m_cycles;

    // ---- opcode AA (condition on Z) ----
    // JMP from 0x3020 to 0x3022    (Z = 0)
    printf("####################################################\n");
    printf("jp_cc_nn from %04X to 3022 (condition not met, using 3 cycles)\n", gb->reg->pc);
    print_registers(gb);
    jp_cc_nn(gb, 0xaa);
    print_registers(gb);
    if(check_jp(gb, 0x3022, cycles+3)) return 1;
    cycles = gb->m_cycles;


    // JMP from 0x3020 to 0x0c80    (Z = 1)
    gb->reg->f = 0x80;
    printf("####################################################\n");
    printf("jp_cc_nn from %04X to 0C80 (condition met, using 4 cycles)\n", gb->reg->pc);
    print_registers(gb);
    jp_cc_nn(gb, 0xaa);
    print_registers(gb);
    if(check_jp(gb, 0x0c80, cycles+4)) return 1;
    cycles = gb->m_cycles;

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