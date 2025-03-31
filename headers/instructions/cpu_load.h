/**
 * @file cpu_load.h
 * @author Erwann SUARD
 * @brief This file is used to implement all gameboy's cpu load instructions. This is done with the help of https://rgbds.gbdev.io/docs/v0.9.1/gbz80.7 
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef CPU_LOAD_H
#define CPU_LOAD_H

#include "../gameboy.h"
#include <stdint.h>

// ######### LD 8 bits #########

/**
 * @brief Copy the value from src register to dst register. (LD r, r’)
 * 
 * OPCODE : 0b01xxxyyy | CYCLES : 1 | LENGTH : 1
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_r8(uint8_t opcode, gameboy* gb);


/**
 * @brief Copy the next absolute value in memory into register. (LD r, n)
 * 
 * OPCODE : 0b00xxx110 | CYCLES : 2 | LENGTH : 2
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_n8(uint8_t opcode, gameboy* gb);  // Can be used to implement LD [HL], n8 ? Takes the same amount of cycles


/**
 * @brief Load data from memory address in [HL] into register. (LD r, (HL))
 * 
 * OPCODE : 0b01xxx110 | CYCLES : 2 | LENGTH : 1
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_hl(uint8_t opcode, gameboy* gb);


/**
 * @brief Load data from register in memory address in [HL]. (LD (HL), r)
 * 
 * OPCODE : 0b01110xxx | CYCLES : 2 | LENGTH : 1
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_hl_r8(uint8_t opcode, gameboy* gb);


/**
 * @brief Load next immediate data in [HL]. (LD (HL), n)
 * 
 * OPCODE : 0b00110110/0x36 | CYCLES : 3 | LENGTH : 2
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_hl_n8(gameboy* gb);


/**
 * @brief Load data from indirection [BC] into acc A. (LD A, (BC))
 * 
 * OPCODE : 0b00001010/0x0A | CYCLES : 2 | LENGTH : 1
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_a_bc(gameboy *gb);


/**
 * @brief Load data from indirection [DE] into acc A. (LD A, (DE))
 * 
 * OPCODE : 0b00011010/0x1A | CYCLES : 2 | LENGTH : 1
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_a_de(gameboy *gb);


/**
 * @brief Load data from indirection acc A into [BC]. (LD (BC), A)
 * 
 * OPCODE : 0b00000010/0x02 | CYCLES : 2 | LENGTH : 1
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_bc_a(gameboy *gb);


/**
 * @brief Load data from indirection acc A into [DE]. (LD (DE), A)
 * 
 * OPCODE : 0b00010010/0x12 | CYCLES : 2 | LENGTH : 1
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_de_a(gameboy *gb);


/**
 * @brief Load to the 8-bit A register, data from the absolute address specified by the 16-bit operand nn. (LD A, (nn))
 * 
 * OPCODE : 0b11111010/0xFA | CYCLES : 4 | LENGTH : 3
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_a_nn(gameboy *gb);


/**
 * @brief Load to the absolute address specified by the 16-bit operand nn, data from the 8-bit A register.
 * 
 * OPCODE : 0b11101010/0xEA | CYCLES : 4 | LENGTH : 3
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_nn_a(gameboy *gb);


/**
 * @brief Load to the 8-bit A register, data from the address specified by the 8-bit C register.
 * 
 * OPCODE : 0b11110010/0xF2 | CYCLES : 2 | LENGTH : 1
 * 
 * @details The full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the least significant byte to the value of C, so the possible range is 0xFF00-0xFFFF.
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ldh_a_c(gameboy *gb);



/**
 * @brief Load to the address specified by the 8-bit C register, data from the 8-bit A register.
 * 
 * OPCODE : 0b11100010/0xE2 | CYCLES : 2 | LENGTH : 1
 * 
 * @details The full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the least significant byte to the value of C, so the possible range is 0xFF00-0xFFFF.
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ldh_c_a(gameboy *gb);



/**
 * @brief Load to the 8-bit A register, data from the address specified by the 8-bit immediate data n.
 * 
 * OPCODE : 0b11110000/0xF0 | CYCLES : 3 | LENGTH : 2
 * 
 * @details The full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ldh_a_n(gameboy *gb);






// ######### LD 16 bits #########
/**
 * @brief Copy the value of v into reg.
 * 
 * @param reg Destination register
 * @param v Value to copy
 * @return 3 cycles
 */
int ld_r16_n16(uint16_t *reg, uint16_t v);






/**
 * @brief Copies the value in A into byte pointed to by address
 * 
 * @param address_p The address pointer to memory to copy byte to
 * @param value The value to copy
 * @return 2 cycles
 */
int ld_r16_a(uint16_t address_p, uint8_t value);

/**
 * @brief Copies the value in A register to address
 * 
 * @param address Address to copy value to
 * @param value Value to copy
 * @return 4 cycles 
 */
int ld_n16_a(uint16_t address, uint8_t value);


/**
 * @brief Copy the value in register A into byte at address if address is between 0xFF00 and 0xFFFF
 * 
 * @param address 
 * @param value 
 * @return int 
 */
int ldh_n16_a(uint16_t address, uint8_t value);


#endif