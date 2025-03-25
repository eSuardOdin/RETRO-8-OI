#include "memory.h"
#include <stdint.h>

uint8_t read_memory(memory *mem, uint16_t address)
{
    uint16_t offset;
    if(address < 0x8000)
    {
        return mem->rom[address];
    }

    if(address >= 0x8000 && address < 0xA000)
    {
        return mem->rom[address - ];
    }
}