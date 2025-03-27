#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include "../headers/gameboy.h"
#include "../headers/memory_constants.h"

void reset_gameboy(gameboy *gb, char *path)
{
    memset(gb, 0, sizeof(gameboy));
    gb->reg = malloc(sizeof(cpu_reg));
    gb->mem = malloc(sizeof(memory));
    gb->cart = malloc(sizeof(cartridge));
    load_cart(path, gb->cart);
    // True program start
    gb->reg->pc = 0x0100;
}


int run_gameboy(gameboy *gb)
{

    printf("========================\n");
    printf("\t%s\n",gb->cart->title);
    printf("ROM\n\tSIZE: %0x\n\tBANKS: %0x\n", gb->cart->rom_size, gb->cart->rom_banks);
    printf("RAM\n\tSIZE: %0x\n\tBANKS: %0x\n", gb->cart->ram_size, gb->cart->ram_banks);
    printf("CGB: %d\n", gb->cart->gen_type);
    printf("MBC: %d\n", gb->cart->mbc_type);
    printf("========================\n");
    if(gb->cart->gen_type == CGB || gb->cart->rom_banks != 2|| gb->cart->ram_size)
    {
        fprintf(stderr, "Cartridge not compatible YET.\nDoing only DMG with no ROM banking or external RAM YET.\n");
        return 1;
    }

    // while(1)
    // {
    //     // Fetch 
    //     //read_memory(gb->mem, uint16_t address)

    //     // Execute



    //     // Decode
    // }



    return 0;
}



uint8_t read_memory(gameboy *gb, uint16_t address)
{
    // Get IE
    if(address == 0xFFFF)
    {
        printf("Reading IE\n");
        return gb->mem->interrupt_enable_reg;
    }

    // Get from cartridge
    if(address <= 0x3FFF)
    {
        printf("Reading ROM Bank 0\n");
        return gb->cart->rom[address];
    }

    // Get from cartridge BANKED ROM (if MBC enabled -> TO IMPLEMENT)
    if(address >= 0x4000 && address <= 0x7FFF)
    {
        printf("Reading Banked ROM\n");
        return gb->cart->rom[address];
    }

    // Get Video Ram (VRAM)
    if(address >= 0x8000 && address <= 0x9FFF)
    {
        printf("Reading VRAM\n");
        return gb->mem->vram[address - VRAM_OFST];
    }

    // Get External RAM (Implement RAM banking if any)
    if(address >= 0xA000 && address <= 0xBFFF)
    {
        printf("Reading External RAM\n");
        return gb->mem->wram[address];
    }

    // Get Work RAM
    if(address >= 0xC000 && address <= 0xDFFF)
    {
        printf("Reading WRAM\n");
        return gb->mem->wram[address - WRAM_OFST];
    }

    // Get OAM
    if(address >= 0xFE00 && address <= 0xFE9F)
    {
        printf("Reading OAM\n");
        return gb->mem->oam[address - OAM_OFST];
    }

    // Get IO 
    if(address >= 0xFF00 && address <= 0xFF7F)
    {
        printf("Reading IO Registers\n");
        return gb->mem->io[address - IO_OFST];
    }

    // Get HRAM
    if(address >= 0xFF80 && address < 0xFFFF)
    {
        printf("Reading High RAM\n");
        return gb->mem->hram[address - HRAM_OFST];
    }

    printf("Bad address request\n");
    // Handle error
    return 0;
}

uint8_t *get_address(gameboy *gb, uint16_t address)
{
    // Get IE
    if(address == 0xFFFF)
    {
        printf("Getting IE\n");
        return &(gb->mem->interrupt_enable_reg);
    }

    // Get from cartridge
    if(address <= 0x3FFF)
    {
        printf("Getting ROM Bank 0\n");
        return &(gb->cart->rom[address]);
    }

    // Get from cartridge BANKED ROM (if MBC enabled -> TO IMPLEMENT)
    if(address >= 0x4000 && address <= 0x7FFF)
    {
        printf("Getting Banked ROM\n");
        return &(gb->cart->rom[address]);
    }

    // Get Video Ram (VRAM)
    if(address >= 0x8000 && address <= 0x9FFF)
    {
        printf("Getting VRAM\n");
        return &(gb->mem->vram[address - VRAM_OFST]);
    }

    // Get External RAM (Implement RAM banking if any)
    if(address >= 0xA000 && address <= 0xBFFF)
    {
        printf("Getting External RAM\n");
        return &(gb->mem->wram[address]);
    }

    // Get Work RAM
    if(address >= 0xC000 && address <= 0xDFFF)
    {
        printf("Getting WRAM\n");
        return &(gb->mem->wram[address - WRAM_OFST]);
    }

    // Get OAM
    if(address >= 0xFE00 && address <= 0xFE9F)
    {
        printf("Getting OAM\n");
        return &(gb->mem->oam[address - OAM_OFST]);
    }

    // Get IO 
    if(address >= 0xFF00 && address <= 0xFF7F)
    {
        printf("Getting IO Registers\n");
        return &(gb->mem->io[address - IO_OFST]);
    }

    // Get HRAM
    if(address >= 0xFF80 && address < 0xFFFF)
    {
        printf("Getting High RAM\n");
        return &(gb->mem->hram[address - HRAM_OFST]);
    }

    printf("Bad address request\n");
    // Handle error
    return NULL;
}


void inc_cycle(gameboy *gb)
{
    gb->t_cycles += 4;
}

uint8_t *get_r8(uint8_t byte, gameboy *gb)
{
    switch(byte)
    {
        case 0x0:
            return &(gb->reg->b);
        case 0x1:
            return &(gb->reg->c);
        case 0x2:
            return &(gb->reg->d);
        case 0x3:
            return &(gb->reg->e);
        case 0x4:
            return &(gb->reg->h);
        case 0x5:
            return &(gb->reg->l);
        case 0x6: // GET [HL] (Indirection of HL)
            return get_address(gb, byte);
        case 0x7:
            return &(gb->reg->a);
    }
}


