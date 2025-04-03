#include <stdint.h>
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
        return gb->mem->interrupt_enable_reg;
    }

    // Get from cartridge
    if(address <= 0x3FFF)
    {
        return gb->cart->rom[address];
    }

    // Get from cartridge BANKED ROM (if MBC enabled -> TO IMPLEMENT)
    if(address >= 0x4000 && address <= 0x7FFF)
    {
        return gb->cart->rom[address];
    }

    // Get Video Ram (VRAM)
    if(address >= 0x8000 && address <= 0x9FFF)
    {
        return gb->mem->vram[address - VRAM_OFST];
    }

    // Get External RAM (Implement RAM banking if any)
    if(address >= 0xA000 && address <= 0xBFFF)
    {
        return gb->mem->wram[address];
    }

    // Get Work RAM
    if(address >= 0xC000 && address <= 0xDFFF)
    {
        return gb->mem->wram[address - WRAM_OFST];
    }

    // Get OAM
    if(address >= 0xFE00 && address <= 0xFE9F)
    {
        return gb->mem->oam[address - OAM_OFST];
    }

    // Get IO 
    if(address >= 0xFF00 && address <= 0xFF7F)
    {
        return gb->mem->io[address - IO_OFST];
    }

    // Get HRAM
    if(address >= 0xFF80 && address < 0xFFFF)
    {
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
        return &(gb->mem->interrupt_enable_reg);
    }

    // Get from cartridge
    if(address <= 0x3FFF)
    {
        return &(gb->cart->rom[address]);
    }

    // Get from cartridge BANKED ROM (if MBC enabled -> TO IMPLEMENT)
    if(address >= 0x4000 && address <= 0x7FFF)
    {
        return &(gb->cart->rom[address]);
    }

    // Get Video Ram (VRAM)
    if(address >= 0x8000 && address <= 0x9FFF)
    {
        return &(gb->mem->vram[address - VRAM_OFST]);
    }

    // Get External RAM (Implement RAM banking if any)
    if(address >= 0xA000 && address <= 0xBFFF)
    {
        return &(gb->mem->wram[address]);
    }

    // Get Work RAM
    if(address >= 0xC000 && address <= 0xDFFF)
    {
        return &(gb->mem->wram[address - WRAM_OFST]);
    }

    // Get OAM
    if(address >= 0xFE00 && address <= 0xFE9F)
    {
        return &(gb->mem->oam[address - OAM_OFST]);
    }

    // Get IO 
    if(address >= 0xFF00 && address <= 0xFF7F)
    {
        return &(gb->mem->io[address - IO_OFST]);
    }

    // Get HRAM
    if(address >= 0xFF80 && address < 0xFFFF)
    {
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
            return get_address(gb, gb->reg->hl);
        case 0x7:
            return &(gb->reg->a);
    }
    return NULL;
}

uint16_t *get_r16(uint8_t byte, gameboy *gb)
{
    switch(byte)
    {
        case 0x0:
            return &(gb->reg->bc);
        case 0x1:
            return &(gb->reg->de);
        case 0x2:
            return &(gb->reg->hl);
        case 0x3:
            return &(gb->reg->sp);
    }
    return NULL;
}

void print_registers(gameboy *gb)
{
    printf("============================\n");
    printf("A : %02x\t\tB : %02x\n", gb->reg->a, gb->reg->b);
    printf("C : %02x\t\tD : %02x\n", gb->reg->c, gb->reg->d);
    printf("E : %02x\t\tF : %02x\n", gb->reg->e, gb->reg->f);
    printf("HL: %04x\tPC: %04x\n", gb->reg->hl, gb->reg->pc);
    printf("M-Cycles : %d\n", gb->t_cycles/4);
    printf("============================\n\n");

}



uint8_t get_byte(gameboy* gb, uint16_t addr)
{
    return read_memory(gb, addr);
}

uint16_t get_word(gameboy *gb, uint16_t addr)
{
    return (read_memory(gb, addr) << 8) | read_memory(gb, addr+1);
}


// ES : Need to change signature and implementation
int set_flags(gameboy* gb, unsigned int result, int is_8_bit, int is_sub){
    int mask = 0;
    if(!result)
        mask += 0b10000000; //setup Z
    if(is_sub)
        mask += 0b01000000; //setup N
    // Warning : Not accurate, the result may have been > 15 before operation. Check : https://gist.github.com/meganesu/9e228b6b587decc783aa9be34ae27841 
    if(result > 15 && is_8_bit) //peut être modifier que avec du 8bits
        mask += 0b00100000; //setup H
    if((is_8_bit && (result > 255)) || (!is_8_bit && (result > 65535)))
        mask += 0b00010000; //setup C
    gb->reg->f = (gb->reg->f | mask) & 0b11110000; //on applique le mask et on suppr les 4 derniers bits
}


int set_H_flag(gameboy *gb, int32_t a, int32_t b, uint8_t is_8bit)
{
    uint8_t is_sub = b < 0 ? 1 : 0;
    int8_t a_nib, b_nib;
    // For 8 bit
    if(is_8bit)
    {
        // Get the nibbles to check
        a_nib = a & 0xF;
        b_nib = abs(b) & 0xF;

        // Check for overflow or borrow depending on operation
        if(!is_sub) // If addition
        {
            // Set H flag
            if((a_nib + b_nib) & 0x10) // 1
            {
                gb->reg->f |= 0x20;    
            }
            else // 0
            {
                gb->reg->f &= 0xd0;
            }
        }
        else        // If substraction
        {
            if(a_nib < b_nib) // 1
            {
                gb->reg->f |= 0x20;
            }
            else // 0
            {
                gb->reg->f &= 0xd0;
            }
        }
    }
    if(!is_8bit)
    {
        // Get the nibbles to check
        a_nib = a & 0xFFF;
        b_nib = abs(b) & 0xFFF;

        // Check for overflow or borrow depending on operation
        if(!is_sub) // If addition
        {
            // Set H flag
            if((a_nib + b_nib) & 0x1000) // 1
            {
                gb->reg->f |= 0x20;    
            }
            else // 0
            {
                gb->reg->f &= 0xd0;
            }
        }
        else        // If substraction
        {
            if(a_nib < b_nib) // 1
            {
                gb->reg->f |= 0x20;
            }
            else // 0
            {
                gb->reg->f &= 0xd0;
            }
        }
    }

    return 0;
}
