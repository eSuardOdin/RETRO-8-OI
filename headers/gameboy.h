#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "cpu_reg.h"
#include "memory.h"
#include "cartridge.h"
#include <stdint.h>


typedef struct {
    uint32_t t_cycles;
    uint32_t m_cycles;
    /// Cpu registers of gameboy
    cpu_reg *reg;
    /// Represents the whole memory adressable by the GameBOY
    memory *mem;

    cartridge *cart;
} gameboy;

void reset_gameboy(gameboy *gb, char *path);

int run_gameboy(gameboy *gb);

/**
 * @brief Gets the absolute address and switch it to get in the right struct 
 * subaddress. Returns the value in memory
 * 
 * @param mem The divided memory
 * @param address The absolut adress
 * @return The value in memory
 */
uint8_t read_memory(gameboy *gb, uint16_t address);


uint8_t write_memory(gameboy *gb, uint16_t address);
#endif