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