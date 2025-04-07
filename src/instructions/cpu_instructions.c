#include "../../headers/instructions/cpu_instructions.h"
#include <stdint.h>
#include <stdio.h>

uint8_t decode_execute_instruction(gameboy *gb, uint8_t opcode)
{
    uint8_t l_nib = (opcode & 0xF0) >> 8;
    uint8_t r_nib = opcode & 0xF;
    // Big branching to operate on smaller switches (Check opcodes table : https://gbdev.io/gb-opcodes/optables/)
    // ### NO PREFIX ###
    if(opcode != 0xCB)
    {
        // LOAD OPERATIONS
        // ### VARIABLE LOAD OPCODES ###
        if(opcode & 0b01000000) // If opcode is 0b01xxxyyy
        {
            // Check if any of the register bits is 110 (Indirection of HL)
            if((opcode & 0b00111000) >> 3 == 0x6)
            {
                ld_hl_r8(opcode, gb);
            }
            else if((opcode & 0b00000111) == 0x6)
            {
                ld_r8_hl(opcode, gb);
            }
            else
            {
                ld_r8_r8(opcode, gb);
            }
        }
        // ### CONSTANT LOAD OPCODES (no register bits to switch) ###
        else if(
            l_nib >= 0x4 && l_nib <= 0x7 ||
            l_nib <= 0x3 && (r_nib == 0x2 || r_nib == 0x6 || r_nib == 0xa || r_nib == 0xe) ||
            l_nib >= 0xe && (r_nib == 0x0 || r_nib == 0x2 || r_nib == 0xa))
        {
            printf("%04x is a load operation.\n", opcode); // Debug print
            switch (opcode)
            {
                case 0x36:
                    printf("LD [HL] n\n"); // Debug print
                    ld_hl_n8(gb);
                    break;
                case 0x0a:
                    printf("LD A [BC]\n"); // Debug print
                    ld_a_bc(gb);
                    break;
                case 0x1a:
                    printf("LD A [DE]\n"); // Debug print
                    ld_a_de(gb);
                    break;
                case 0x02:
                    printf("LD [BC] A\n"); // Debug print
                    ld_bc_a(gb);
                    break;
                case 0x12:
                    printf("LD [DE] A\n"); // Debug print
                    ld_de_a(gb);
                    break;
                case 0xfa:
                    printf("LD A nn\n"); // Debug print
                    ld_a_nn(gb);
                    break;
                case 0xea:
                    printf("LD nn A\n"); // Debug print
                    ld_nn_a(gb);
                    break;
                case 0xf2:
                    printf("LD A C\n"); // Debug print
                    ldh_a_c(gb);
                    break;
                case 0xe2:
                    printf("LD C A\n"); // Debug print
                    ldh_c_a(gb);
                    break;
                case 0xf0:
                    printf("LD A n\n"); // Debug print
                    ldh_a_n(gb);
                    break;
                case 0xe0:
                    printf("LD n A\n"); // Debug print
                    ldh_n_a(gb);
                    break;
                case 0x3a:
                    printf("LD A [HL-]\n"); // Debug print
                    ldh_a_hl_dec(gb);
                    break;
                case 0x32:
                    printf("LD [HL-] A\n"); // Debug print
                    ld_hl_dec_a(gb);
                    break;
                case 0x2a:
                    printf("LD A [HL+]\n"); // Debug print
                    ldh_a_hl_inc(gb);
                    break;
                case 0x22:
                    printf("LD [HL+] A\n"); // Debug print
                    ld_hl_inc_a(gb);
                    break;
                case 0x08:
                    printf("LD nn SP\n"); // Debug print
                    ld_nn_sp(gb);
                    break;
                case 0xf9:
                    printf("LD SP HL\n"); // Debug print
                    ld_sp_hl(gb);
                    break;
                case 0xf8:
                    printf("LD HL SP+e\n"); // Debug print
                    ld_hl_sp_e(opcode, gb);
                    break;
            }
        }
        // ### CONSTANT arithmetic OPCODES (no register bits to switch) ###
        else if(
            l_nib >= 0x4 && l_nib <= 0x7 ||
            l_nib <= 0x3 && (r_nib == 0x2 || r_nib == 0x6 || r_nib == 0xa || r_nib == 0xe) ||
            l_nib >= 0xe && (r_nib == 0x0 || r_nib == 0x2 || r_nib == 0xa))
        {
            printf("%04x is a arithmetic operation.\n", opcode); // Debug print
            switch (opcode)
            {
                case 0x80:
                    printf("ADD A R8\n"); // Debug print
                    add_a_r8(opcode,gb);
                    break;
                case 0x86:
                    printf("ADD A [HL]\n"); // Debug print
                    add_a_hl(gb);
                    break;
                case 0xC6:
                    printf("ADD A nn\n"); // Debug print
                    add_a_n(gb);
                    break;
                case 0x88:
                    printf("ADC A R8\n"); // Debug print
                    adc_a_r8(opcode,gb);
                    break;
                case 0x8E:
                    printf("ADC A [HL]\n"); // Debug print
                    adc_a_hl(gb);
                    break;
                case 0xCE:
                    printf("ADC A nn\n"); // Debug print
                    adc_a_n(gb);
                    break;
                case 0x90:
                    printf("SUB A R8\n"); // Debug print
                    sub_a_r8(opcode, gb);
                    break;
                case 0x96:
                    printf("SUB A [HL]\n"); // Debug print
                    sub_a_hl(gb);
                    break;
                case 0xD6:
                    printf("SUB A nn\n"); // Debug print
                    sub_a_n(gb);
                    break;
                case 0x98:
                    printf("SBC A R8\n"); // Debug print
                    sbc_a_r8(opcode, gb);
                    break;
                case 0xDE:
                    printf("SBC A nn\n"); // Debug print
                    sbc_a_hl(gb);
                    break;
                case 0xB8:
                    printf("CP A R8\n"); // Debug print
                    cp_a_r8(opcode, gb);
                    break;
                case 0x9E:
                    printf("CP A [HL]\n"); // Debug print
                    cp_a_hl(gb);
                    break;
                case 0xFE:
                    printf("CP A nn\n"); // Debug print
                    cp_a_r8(opcode, gb);
                    break;
                case 0x04:
                    printf("INC R8\n"); // Debug print
                    inc_r8(opcode, gb);
                    break;
                case 0x34:
                    printf("INC HL\n"); // Debug print
                    inc_hl(gb);
                    break;
                case 0x05:
                    printf("DEC R8\n"); // Debug print
                    dec_r8(opcode, gb);
                    break;
                case 0x35:
                    printf("DEC HL\n"); // Debug print
                    dec_hl(gb);
                    break;
            }
        }
        // ### CONSTANT logic OPCODES (no register bits to switch) ###
        else if(
            l_nib >= 0x4 && l_nib <= 0x7 ||
            l_nib <= 0x3 && (r_nib == 0x2 || r_nib == 0x6 || r_nib == 0xa || r_nib == 0xe) ||
            l_nib >= 0xe && (r_nib == 0x0 || r_nib == 0x2 || r_nib == 0xa))
        {
            printf("%04x is a logic operation.\n", opcode); // Debug print
            switch (opcode)
            {
                case 0xA0:
                    printf("AND A R8\n"); // Debug print
                    and_a_r8(opcode,gb);
                    break;
                case 0xA6:
                    printf("AND A [HL]\n"); // Debug print
                    and_a_hl(gb);
                    break;
                case 0xE6:
                    printf("AND A nn\n"); // Debug print
                    and_a_n(gb);
                    break;
                case 0xB0:
                    printf("OR A R8\n"); // Debug print
                    or_a_r8(opcode,gb);
                    break;
                case 0xB6:
                    printf("OR A [HL]\n"); // Debug print
                    or_a_hl(gb);
                    break;
                case 0xF6:
                    printf("OR A nn\n"); // Debug print
                    or_a_n(gb);
                    break;
                case 0xA8:
                    printf("XOR A R8\n"); // Debug print
                    xor_a_r8(opcode, gb);
                    break;
                case 0xAE:
                    printf("XOR A [HL]\n"); // Debug print
                    xor_a_hl(gb);
                    break;
                case 0xEE:
                    printf("XOR A nn\n"); // Debug print
                    xor_a_n(gb);
                    break;
                case 0x3F:
                    printf("CCF\n"); // Debug print
                    ccf(gb);
                    break;
                case 0x37:
                    printf("SCF\n"); // Debug print
                    scf(gb);
                    break;
                case 0x27:
                    printf("DAA\n"); // Debug print
                    daa(gb);
                    break;
            }
        }
    }
    // ### PREFIXED OPCODE ###
    else 
    {
        // Increment pc and switch next opcode
        gb->reg->pc++;
        opcode = get_byte(gb, gb->reg->pc);
        switch (opcode)
        {
        
        }
    }



    return 0; // Mouais
}


void test_instructions(gameboy *gb)
{
    gb->reg->a = 0x22;
    gb->reg->b = 0x00;
    gb->reg->c = 0x44;
    gb->reg->d = 0x05;
    gb->reg->e = 0x12;
    gb->reg->f = 0x00;
    gb->reg->hl = 0xff43;
    gb->reg->sp = 0x0034;
    print_registers(gb);
    
    // uint8_t* r = get_address(gb, 0xff43);
    // *r = 0xff;
    // ld_r8_r8(0b01111110, gb);
    
    // ### Test of half carry ###
    /*
    // -> Should be set to 0
    int32_t a = 5;
    int32_t b = -5;
    printf("Checking for %d + (%d).\n", a, b);
    set_H_flag(gb, a, b,1);
    printf("Flag register is %02x.\n", gb->reg->f);
    print_registers(gb);
    // -> Should be set to 1
    b = -6;
    printf("Checking for %d + (%d).\n", a, b);
    set_H_flag(gb, a, b,1);
    printf("Flag register is %02x.\n", gb->reg->f);
    print_registers(gb);
    */
    
    // // -> Should be set to 1
    // int32_t a = 0x98;
    // int32_t b = 0x08;
    // printf("Checking for %02x + (%02x) = %02x.\n", a, b, a + b);
    // set_H_flag(gb, a, b,1);
    // printf("Flag register is %02x.\n", gb->reg->f);
    // print_registers(gb);
    // // -> Should be set to 0
    // a = 0xc8;
    // b = 0x33;
    // printf("Checking for %02x + (%02x) = %02x.\n", a, b, a + b);
    // set_H_flag(gb, a, b,1);
    // printf("Flag register is %02x.\n", gb->reg->f);
    // print_registers(gb);

    // // -> Should be set to 1
    // a = 0x17;
    // b = -0x6a;
    // printf("Checking for %02x + (%02x) = %02x.\n", a, b, a + b);
    // set_H_flag(gb, a, b,1);
    // printf("Flag register is %02x.\n", gb->reg->f);
    // print_registers(gb);
    // b = -6;
    // printf("Checking for %d + (%d).\n", a, b);
    // set_H_flag(gb, a, b,1);
    // printf("Flag register is %02x.\n", gb->reg->f);
    // print_registers(gb);



    // print_registers(gb);
    
    // printf("BEFORE PUSH: SP = %04x.\n", gb->reg->sp);
    // push_r16(0b11100101, gb); // PUSH value of HL register
    // printf("AFTER PUSH: SP = %04x.\n", gb->reg->sp);
    // printf("Points to %02x (lsb) %02x (msb).\n", get_byte(gb, gb->reg->sp), get_byte(gb, gb->reg->sp+1));


    // printf("Poping to BC register.\n");
    // pop_r16(0b11000001, gb);
    // printf("AFTER POP: SP = %04x.\n", gb->reg->sp);
    // print_registers(gb);

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

    // LD [HL], r
    printf("LD [HL], E -> 2 Cycles | 1 Length\n");
    gb->reg->l = 0x33;
    printf("[HL] : address: %04x | value: %0x\n", gb->reg->hl, get_byte(gb, gb->reg->hl));
    ld_hl_r8(0b01110101, gb);
    printf("[HL] : address: %04x | value: %0x\n", gb->reg->hl, get_byte(gb, gb->reg->hl));
    print_registers(gb);

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

