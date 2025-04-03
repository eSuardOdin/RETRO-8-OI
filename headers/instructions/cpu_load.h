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
 * @author Erwann SUARD
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_r8(uint8_t opcode, gameboy* gb);


/**
 * @brief Copy the next absolute value in memory into register. (LD r, n)
 * 
 * OPCODE : 0b00xxx110 | CYCLES : 2 | LENGTH : 2
 * @author Erwann SUARD
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_n8(uint8_t opcode, gameboy* gb);  // Can be used to implement LD [HL], n8 ? Takes the same amount of cycles


/**
 * @brief Load data from memory address in [HL] into register. (LD r, (HL))
 * 
 * OPCODE : 0b01xxx110 | CYCLES : 2 | LENGTH : 1
 * @author Erwann SUARD
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r8_hl(uint8_t opcode, gameboy* gb);


/**
 * @brief Load data from register in memory address in [HL]. (LD (HL), r)
 * 
 * OPCODE : 0b01110xxx | CYCLES : 2 | LENGTH : 1
 * @author Erwann SUARD
 * @param opcode Opcode to get register from
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_hl_r8(uint8_t opcode, gameboy* gb);


/**
 * @brief Load next immediate data in [HL]. (LD (HL), n)
 * 
 * OPCODE : 0b00110110/0x36 | CYCLES : 3 | LENGTH : 2
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_hl_n8(gameboy* gb);


/**
 * @brief Load data from indirection [BC] into acc A. (LD A, (BC))
 * 
 * OPCODE : 0b00001010/0x0A | CYCLES : 2 | LENGTH : 1
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_a_bc(gameboy *gb);


/**
 * @brief Load data from indirection [DE] into acc A. (LD A, (DE))
 * 
 * OPCODE : 0b00011010/0x1A | CYCLES : 2 | LENGTH : 1
 * @author Erwann SUARD
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


/**
 * @brief Load to the address specified by the 8-bit C register, data from the 8-bit A register
 * 
 * OPCODE : 0b11100000/0xE0 | CYCLES : 3 | LENGTH : 2
 * 
 * @details The full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ldh_n_a(gameboy *gb);



/**
 * @brief Load to the 8-bit A register, data from the absolute address specified by the 16-bit register HL
 * 
 * OPCODE : 0b00111010/0x3A | CYCLES : 2 | LENGTH : 1
 * 
 * @details The value of HL is decremented after the memory read.
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ldh_a_hl_dec(gameboy *gb);



/**
 * @brief Load to the absolute address specified by the 16-bit register HL, data from the 8-bit A register
 * 
 * OPCODE : 0b00110010/0x32 | CYCLES : 2 | LENGTH : 1
 * 
 * @details The value of HL is decremented after the memory write.
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_hl_dec_a(gameboy *gb);



/**
 * @brief Load to the 8-bit A register, data from the absolute address specified by the 16-bit register HL.
 * 
 * OPCODE : 0b00101010/0x2A | CYCLES : 2 | LENGTH : 1
 * 
 * @details The value of HL is incremented after the memory read. 
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ldh_a_hl_inc(gameboy *gb);



/**
 * @brief Load to the absolute address specified by the 16-bit register HL, data from the 8-bit A register
 * 
 * OPCODE : 0b00100010/0x32 | CYCLES : 2 | LENGTH : 1
 * 
 * @details The value of HL is incremented after the memory write.
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_hl_inc_a(gameboy *gb);


// ######### LD 16 bits #########



/**
 * @brief Load to the 16-bit register rr, the immediate 16-bit data nn.
 * 
 * OPCODE : 0b00xx0001 | CYCLES : 3 | LENGTH : 3
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_r16_n16(uint8_t opcode, gameboy *gb);



/**
 * @brief Load to the absolute address specified by the 16-bit operand nn, data from the 16-bit SP register.
 * 
 * OPCODE : 0b00001000/0x08 | CYCLES : 5 | LENGTH : 3
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_nn_sp(gameboy *gb);



/**
 * @brief Load to the 16-bit SP register, data from the 16-bit HL register
 * 
 * OPCODE : 0b11111001/0xF9 | CYCLES : 2 | LENGTH : 1
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_sp_hl(gameboy *gb);



/**
 * @brief Push to the stack memory, data from the 16-bit register rr
 * OPCODE : 0b11xx0101 | CYCLES : 4 | LENGTH : 1
 * @details Decrease SP by one to copy MSB, then, deacrease SP by one to copy LSB
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int push_r16(uint8_t opcode, gameboy *gb);


/**
 * @brief Pop from the stack memory to the 16-bit register rr
 * OPCODE : 0b11xx0001 | CYCLES : 3 | LENGTH : 1
 * @details Copy LSB and increase SP, then, copy MSB and increase SP by one
 *
 * WARNING : MAY MODIFY F REGISTER   
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int pop_r16(uint8_t opcode, gameboy *gb);


/**
 * @brief Add the signed value e8 to SP and copy the result in HL.
 * OPCODE : 0b11111000/0xF8 | CYCLES : 3 | LENGTH : 2
 * @details Flags : Z = 0 | N = 0 | H = Overflow from bit 3 | C = Overflow from bit 7  
 * 
 * WARNING : Need to test well this one, flags, negative e, etc.. 
 *@author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int ld_hl_sp_e(uint8_t opcode, gameboy *gb);


#endif