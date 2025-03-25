#include "../headers/memory.h"
#include "../headers/memory_constants.h"
#include <stdint.h>
#include <stdio.h>

uint8_t read_memory(memory *mem, uint16_t address)
{
    // Get IE
    if(address == 0xFFFF)
    {
        printf("Reading IE\n");
        return mem->interrupt_enable_reg;
    }

    // Get from cartridge
    if(address <= 0x7FFF)
    {
        printf("Reading ROM\n");
        return mem->rom[address];
    }

    // Get Video Ram (VRAM)
    if(address >= 0x8000 && address <= 0x9FFF)
    {
        printf("Reading VRAM\n");
        return mem->rom[address - VRAM_OFST];
    }

    // Get External RAM
    if(address >= 0xA000 && address <= 0xBFFF)
    {
        printf("Reading External RAM\n");
        return mem->rom[address - EXT_RAM_OFST];
    }

    // Get Work RAM
    if(address >= 0xC000 && address <= 0xDFFF)
    {
        printf("Reading WRAM\n");
        return mem->rom[address - WRAM_OFST];
    }

    // Get OAM
    if(address >= 0xFE00 && address <= 0xFE9F)
    {
        printf("Reading OAM\n");
        return mem->rom[address - OAM_OFST];
    }

    // Get IO 
    if(address >= 0xFF00 && address <= 0xFF7F)
    {
        printf("Reading IO Registers\n");
        return mem->rom[address - IO_OFST];
    }

    // Get HRAM
    if(address >= 0xFF80 && address < 0xFFFF)
    {
        printf("Reading High RAM\n");
        return mem->rom[address - HRAM_OFST];
    }

    printf("Bad address request\n");
}