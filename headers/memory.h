#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define ROM_SIZE 0X8000
#define VRAM_SIZE 0X2000
#define WRAM_SIZE 0X2000
#define OAM_SIZE 0xA0
#define IO_SIZE 0x80
#define HIGH_RAM_SIZE 0x7F

typedef struct
{
    uint8_t rom[ROM_SIZE];
    uint8_t vram[VRAM_SIZE];
    uint8_t wram[WRAM_SIZE];
    uint8_t oam[OAM_SIZE];
    uint8_t hram[HIGH_RAM_SIZE];
} memory;
/**
 * @brief Gets the absolute address and switch it to get in the right struct 
 * subaddress. Returns the value in memory
 * 
 * @param mem The divided memory
 * @param address The absolut adress
 * @return The value in memory
 */
uint8_t read_memory(memory *mem, uint16_t address);


uint8_t write_memory(memory *mem, uint16_t address);

#endif