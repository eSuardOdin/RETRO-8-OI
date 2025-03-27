/**
 * @file memory.h
 * @author Erwann SUARD
 * @brief Defines the memory mapped by gameboy (DMG) and how to access it.
 * @remark Check https://gbdev.io/pandocs/Memory_Map.html for details
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define ROM_SIZE            0X4000
#define VRAM_SIZE           0X2000
#define EXTERNAL_RAM_SIZE   0x2000
#define WRAM_SIZE           0X2000
#define OAM_SIZE            0xA0
#define IO_SIZE             0x80
#define HIGH_RAM_SIZE       0x7F

typedef struct
{
    /// Rom bank 0 (always charged in mem)
    uint8_t rom_b0[ROM_SIZE];
    /// Banked rom (if MBC)
    uint8_t rom_bn[ROM_SIZE];
    uint8_t vram[VRAM_SIZE];
    uint8_t ext_ram[EXTERNAL_RAM_SIZE];
    uint8_t wram[WRAM_SIZE];
    uint8_t oam[OAM_SIZE];
    uint8_t io[IO_SIZE];
    uint8_t hram[HIGH_RAM_SIZE];
    uint8_t interrupt_enable_reg;
} memory;


#endif