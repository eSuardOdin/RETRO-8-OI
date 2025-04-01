#include "../../headers/instructions/cpu_instructions.h"
#include <stdint.h>

uint8_t fetch_instruction(gameboy* gb)
{
    // Increment Cycles and PC (while returning)
    inc_cycle(gb);
    uint8_t res = read_memory(gb, gb->reg->pc);
    gb->reg->pc++;
    return res;
}




void test_instructions(gameboy *gb)
{
    gb->reg->a = 0x22;
    gb->reg->b = 0x00;
    gb->reg->c = 0x44;
    gb->reg->d = 0x05;
    gb->reg->e = 0x12;
    gb->reg->f = 0xe3;
    gb->reg->hl = 0xff43;
    gb->reg->sp = 0x0034;
    print_registers(gb);
    
    // uint8_t* r = get_address(gb, 0xff43);
    // *r = 0xff;
    // ld_r8_r8(0b01111110, gb);
    

    // print_registers(gb);
    
    printf("BEFORE PUSH: SP = %04x.\n", gb->reg->sp);
    push_r16(0b11100101, gb); // PUSH value of HL register
    printf("AFTER PUSH: SP = %04x.\n", gb->reg->sp);
    printf("Points to %02x (lsb) %02x (msb).\n", get_byte(gb, gb->reg->sp), get_byte(gb, gb->reg->sp+1));

    // // LD B, A
    // printf("LD B into A -> 1 Cycle | 1 Length\n");
    // ld_r8_r8(0b01111000, gb);
    // print_registers(gb);

    // // LD C, 0x66
    // printf("LD 0x66 into C -> 2 Cycles | 2 Length\n");
    // uint8_t *value = get_address(gb, gb->reg->pc + 1);
    // *value = 0x66;
    // ld_r8_n8(0b00001110, gb);
    // print_registers(gb);

    // // LD r, [HL] -> I put it on 0xaa
    // value = get_address(gb, gb->reg->hl);
    // *value = 0xaa;
    // printf("LD [HL] (address : %04x | value : %02x) into D -> 2 Cycles | 1 Length\n", gb->reg->hl, get_byte(gb, gb->reg->hl));
    // ld_r8_hl(0b01010110, gb);
    // print_registers(gb);

    // // LD [HL], r
    // printf("LD [HL], E -> 2 Cycles | 1 Length\n");
    // ld_hl_r8(0b01110011, gb);
    // printf("[HL] : address: %04x | value: %0x\n", gb->reg->hl, get_byte(gb, gb->reg->hl));
    // print_registers(gb);

    // // LD [HL], n -> Setting it on 0xef
    // printf("LD [HL], n -> 3 Cycles | 2 Length\n");
    // value = get_address(gb, gb->reg->pc+1);
    // *value = 0xef;
    // ld_hl_n8(gb);
    // printf("[HL] : address: %04x | value: %0x\n", gb->reg->hl, get_byte(gb, gb->reg->hl));
    // print_registers(gb);

    // // LD A, [BC] -> Setting it on 0xa1
    // printf("LD A, [BC] -> 2 Cycles | Length 1\n");
    // value = get_address(gb, gb->reg->bc);
    // *value = 0xa1;
    // printf("[BC] : address: %04x | value: %0x\n", gb->reg->bc, get_byte(gb, gb->reg->bc));
    // ld_a_bc(gb);
    // print_registers(gb);


    // // LD A, [DE] -> Setting it on 0xff
    // printf("LD A, [DE] -> 2 Cycles | Length 1\n");
    // value = get_address(gb, gb->reg->de);
    // *value = 0xff;
    // printf("[DE] : address: %04x | value: %0x\n", gb->reg->de, get_byte(gb, gb->reg->de));
    // ld_a_de(gb);
    // print_registers(gb);


    // // LD [BC], A
    // gb->reg->a = 0x3;
    // printf("LD [BC], A (changed value to 03)\n");
    // printf("[BC] : address: %04x | value: %0x\n", gb->reg->bc, get_byte(gb, gb->reg->bc));
    // ld_bc_a(gb);
    // printf("[BC] : address: %04x | value: %0x\n", gb->reg->bc, get_byte(gb, gb->reg->bc));
    // print_registers(gb);


    // // LD [DE], A
    // gb->reg->a = 0x4;
    // printf("LD [DE], A (changed value to 04)\n");
    // printf("[DE] : address: %04x | value: %0x\n", gb->reg->de, get_byte(gb, gb->reg->de));
    // ld_de_a(gb);
    // printf("[DE] : address: %04x | value: %0x\n", gb->reg->de, get_byte(gb, gb->reg->de));
    // print_registers(gb);


    // // LD A, nn -> Setting read on 0x22f1
    // value = get_address(gb, gb->reg->pc + 1);
    // *value = 0xf1;
    // value = get_address(gb, gb->reg->pc + 2);
    // *value = 0x22;
    // value = get_address(gb, 0x22f1);
    // *value = 0xee;
    // printf("LD A, nn (%02x%02x)\n", get_byte(gb, gb->reg->pc + 2), get_byte(gb, gb->reg->pc + 1));
    // ld_a_nn(gb);
    // print_registers(gb);


    // // LD nn, A -> Changing HRAM 0xFF81 to A
    // value = get_address(gb, gb->reg->pc + 1);
    // *value = 0x81;
    // value = get_address(gb, gb->reg->pc + 2);
    // *value = 0xff;
    // printf("LD nn (%02x%02x), A\n", get_byte(gb, gb->reg->pc + 2), get_byte(gb, gb->reg->pc + 1));
    // ld_nn_a(gb);
    // printf("FF81 is now %02x.\n", get_byte(gb, 0xff81));
    // print_registers(gb);


    // // LDH A, C -> Putting 0xCC in A
    // value = get_address(gb, 0xff00 | gb->reg->c);
    // *value = 0xcc;
    // printf("LDH A, C (ff%02x)\n", gb->reg->c);
    // ldh_a_c(gb);
    // print_registers(gb);
    

    // // LDH C, A -> Changing C to get to ffaa
    // gb->reg->c = 0xaa;
    // printf("LDH (C), A (ff%02x)\n", gb->reg->c);
    // printf("Before : Value of FFAA is %0x.\n", get_byte(gb, 0xffaa));
    // ldh_c_a(gb);
    // printf("After : Value of FFAA is %0x.\n", get_byte(gb, 0xffaa));
    // print_registers(gb);


    // // LDH A, (n) -> Changing n to get value 0x45
    // value = get_address(gb, 0xff00 | get_byte(gb, gb->reg->pc + 1));
    // *value = 0x45;
    // printf("LDH A, n (%04x)\n", 0xff00 | get_byte(gb, gb->reg->pc + 1));
    // ldh_a_n(gb);
    // print_registers(gb);


}

