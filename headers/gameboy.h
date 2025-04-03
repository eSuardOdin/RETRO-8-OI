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

/**
 * @brief Get the address of a memory location
 * 
 * @param gb 
 * @param address 
 * @return uint8_t* 
 */
uint8_t *get_address(gameboy *gb, uint16_t address);






uint8_t write_memory(gameboy *gb, uint16_t address);



/**
 * @brief Get the the address of an 8 bits register depending on opcode
 * 
 * @param byte Byte to decode
 * @param gb Gameboy struct to get register address
 * @return A pointer to the register
 */
uint8_t *get_r8(uint8_t byte, gameboy* gb);


/**
 * @brief Get the byte in memory correponding with addr and return it.
 * 
 * @param gb To get the ram from
 * @param addr The addr where to get the byte
 * @return The byte pointed to.
 */
uint8_t get_byte(gameboy* gb, uint16_t addr);

/**
 * @brief Get the byte in memory correponding with addr and return it.
 * @param gb To get the ram from
 * @param addr The addr where to get the word
 * @return The word pointed to.
 */
uint16_t get_word(gameboy* gb, uint16_t addr);

/**
 * @brief set flags corresponding to the result
 * @param gb To get the ram from
 * @param result 
 * @param is_8_bit
 * @param is_sub
 */
int set_flags(gameboy *gb, unsigned int result, int is_8_bit, int is_sub);


/**
 * @brief Just increments T-Cycles by 4
 * 
 * @param gb 
 */
void inc_cycle(gameboy *gb);


/**
 * @brief Just here to debug
 * 
 * @param gb 
 */
void print_registers(gameboy *gb);
#endif