#include "../../headers/instructions/cpu_control_flow.h"
#include "../../headers/gameboy.h"
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
    address = get_byte;
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
