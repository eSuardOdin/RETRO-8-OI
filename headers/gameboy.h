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

uint16_t *get_r16(uint8_t byte, gameboy *gb);

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


int set_flags(gameboy* gb, unsigned int result, int is_8_bit, int is_sub);
/**
 * @brief Set the H (Half Carry flag) [TO REFACTOR]
 * 
 * @details 
 * 
 * Add : 
 *    - Set to 1 if a Carry occurs from bit 3 to bit 4 
 *    - Set to 0 if no Carry occurs from bit 3 to bit 4
 * 
 * Sub :
 *    - Set to 1 if a Borrow from bit 4 occurs
 *    - Set to 0 if no Borrow from bit 4 occurs
 * 
 * On 16bit arithmetic, carry occurs from bit 11 to 12.
 * 
 * @param gb The gameboy struct
 * @param a The left operande 
 * @param b The right operande
 * @param is_8bit 
 * @return TO DETERMINE
 */
int set_H_flag(gameboy *gb, int32_t a, int32_t b, uint8_t is_8bit);
int set_C_flag(gameboy* gb, unsigned int result, int is_8bit);
int set_N_flag(gameboy* gb, int is_sub);
int set_Z_flags(gameboy* gb, unsigned int result);

#endif