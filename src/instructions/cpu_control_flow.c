#include "../../headers/instructions/cpu_control_flow.h"
#include "../../headers/gameboy.h"
#include "../../headers/memory_constants.h"
#include <stdint.h>
#include <stdio.h>

int jp_nn(gameboy *gb)
{
    // Increment cycle
    inc_cycle(gb);
    uint16_t address = 0;

    // Increment PC to get LSB - Increment cycle
    gb->reg->pc++;
    address = get_byte(gb, gb->reg->pc);
    inc_cycle(gb);

    // Increment PC to get MSB - Increment cycle
    gb->reg->pc++;
    address |= get_byte(gb, gb->reg->pc) << 8;
    inc_cycle(gb);

    // Set program counter to the address
    gb->reg->pc = address;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int jp_hl(gameboy *gb)
{
    // Set pc to hl
    gb->reg->pc = gb->reg->hl;
    
    // Increment cycle
    inc_cycle(gb);
    return 0;
}


int jp_cc_nn(gameboy *gb, uint8_t opcode)
{
    uint16_t address = 0;
    
    // Check the condition
    int is_jmp = is_cond(gb, opcode);
    
    // Increment Cycle
    inc_cycle(gb);

    // Increment PC to get LSB - Increment cycle
    gb->reg->pc++;
    address = get_byte(gb, gb->reg->pc);
    inc_cycle(gb);

    // Increment PC to get MSB - Increment cycle
    gb->reg->pc++;
    address |= get_byte(gb, gb->reg->pc) << 8;
    inc_cycle(gb);

    // Jump if condition
    if(is_jmp)
    {
        gb->reg->pc = address;
        inc_cycle(gb);
    }
    return 0;
}


int jr_e(gameboy *gb)
{
    int8_t e = 0;
    
    // Increment cycle and PC to get e
    inc_cycle(gb);
    gb->reg->pc++;
    e = get_byte(gb, gb->reg->pc);

    // Increment cycle
    inc_cycle(gb);

    // Jump to new address
    gb->reg->pc += e;

    // Increment cycle
    inc_cycle(gb);
    return 0;
}

int jr_cc_e(gameboy *gb, uint8_t opcode)
{
    int8_t e = 0;

    // Check the condition
    int is_jmp = is_cond(gb, opcode);
    
    // Increment cycle and PC to get e
    inc_cycle(gb);
    gb->reg->pc++;
    e = get_byte(gb, gb->reg->pc);

    // Increment cycle
    inc_cycle(gb);

    // Jump and increment cycle if condition true
    if(is_jmp)
    {
        gb->reg->pc += e;
        inc_cycle(gb);
    }

    return 0;
}


int call_nn(gameboy *gb)
{

    uint16_t address = 0;
    uint8_t lsb = 0;
    uint8_t msb = 0;

    // Increment Cycle
    inc_cycle(gb);

    // Increment PC to get LSB - Increment cycle
    gb->reg->pc++;
    lsb = get_byte(gb, gb->reg->pc);
    address = lsb;
    inc_cycle(gb);

    // Increment PC to get MSB - Increment cycle
    gb->reg->pc++;
    address |= get_byte(gb, gb->reg->pc) << 8;
    inc_cycle(gb);
    
    // Decrement SP and copy MSB
    gb->reg->sp--;
    *(get_address(gb, gb->reg->sp)) = msb;
    // Increment cycle
    inc_cycle(gb);

    // Decrement SP and copy LSB
    gb->reg->sp--;
    *(get_address(gb, gb->reg->sp)) = lsb;
    // Increment cycle
    inc_cycle(gb);

    // Jump to address and increment cycle
    gb->reg->pc = address;
    inc_cycle(gb);
    
    return 0;
}



int call_cc_nn(uint8_t opcode, gameboy *gb)
{

    uint16_t address = 0;
    uint8_t lsb = 0;
    uint8_t msb = 0;
    int is_call = is_cond(gb, opcode);
    // Increment Cycle
    inc_cycle(gb);

    // Increment PC to get LSB - Increment cycle
    gb->reg->pc++;
    lsb = get_byte(gb, gb->reg->pc);
    address = lsb;
    inc_cycle(gb);

    // Increment PC to get MSB - Increment cycle
    gb->reg->pc++;
    address |= get_byte(gb, gb->reg->pc) << 8;
    inc_cycle(gb);
    
    // If cc = true, same logic as call_nn()
    if(is_call)
    {
        // Decrement SP and copy MSB
        gb->reg->sp--;
        *(get_address(gb, gb->reg->sp)) = msb;
        // Increment cycle
        inc_cycle(gb);

        // Decrement SP and copy LSB
        gb->reg->sp--;
        *(get_address(gb, gb->reg->sp)) = lsb;
        // Increment cycle
        inc_cycle(gb);

        // Jump to address and increment cycle
        gb->reg->pc = address;
        inc_cycle(gb);
    }
    
    return 0;
}



int ret(gameboy *gb)
{
    uint16_t address = 0;
    uint8_t lsb = 0;
    uint8_t msb = 0;
    // Increment cycle
    inc_cycle(gb);

    // Get lsb and increment stack pointer
    lsb = get_byte(gb, gb->reg->sp);
    gb->reg->sp++;
    // Increment cycle
    inc_cycle(gb);

    // Get msb and increment stack pointer
    msb = get_byte(gb, gb->reg->sp);
    gb->reg->sp++;
    // Increment cycle
    inc_cycle(gb);

    // Set address to return to
    address = lsb;
    address |= msb << 8;

    // Increment cycle and jump
    inc_cycle(gb);
    gb->reg->pc = address;
    return 0;
}



int ret_cc(uint8_t opcode, gameboy *gb)
{
    uint16_t address = 0;
    uint8_t lsb = 0;
    uint8_t msb = 0;
    int is_ret = is_cond(gb, opcode);

    // Get lsb and increment stack pointer
    lsb = get_byte(gb, gb->reg->sp);
    gb->reg->sp++;
    // Increment cycle
    inc_cycle(gb);

    // Get msb and increment stack pointer
    msb = get_byte(gb, gb->reg->sp);
    gb->reg->sp++;
    // Increment cycle
    inc_cycle(gb);

    if(is_ret)
    {
        // Set address to return to
        address = lsb;
        address |= msb << 8;

        // Increment cycle and jump
        inc_cycle(gb);
        gb->reg->pc = address;
    }

    return 0;
}


int reti(gameboy *gb)
{
    uint16_t address = 0;
    uint8_t lsb = 0;
    uint8_t msb = 0;

    // Get lsb and increment stack pointer
    lsb = get_byte(gb, gb->reg->sp);
    gb->reg->sp++;
    // Increment cycle
    inc_cycle(gb);

    // Get msb and increment stack pointer
    msb = get_byte(gb, gb->reg->sp);
    gb->reg->sp++;
    // Increment cycle
    inc_cycle(gb);

    // Set address to return to
    address = lsb;
    address |= msb << 8;

    // Increment cycle and jump
    inc_cycle(gb);
    gb->reg->pc = address;

    // Set EMI to 1
    gb->reg->ime = 1;
    // Increment cycle
    inc_cycle(gb);

    return 0;
}


int rst(uint8_t opcode, gameboy* gb)
{
    uint8_t msb;
    uint8_t lsb;
    uint16_t new_pc = 0;
    // Increment cycle
    inc_cycle(gb);

    // Store PC in stack
    msb = (gb->reg->pc & 0xF0) >> 8;
    lsb = (gb->reg->pc & 0xF);
    gb->reg->sp--;
    *(get_address(gb, gb->reg->sp)) = msb;
    gb->reg->sp--;
    *(get_address(gb, gb->reg->sp)) = lsb;
    // Increment cycle
    inc_cycle(gb);

    // Set new pc
    new_pc = opcode << 8;
    new_pc &= 0xF0; // Just to be sure lsb nibble set to 0
    gb->reg->pc = new_pc;
    // Increment cycle
    inc_cycle(gb);
    inc_cycle(gb);
    return 0;
}


