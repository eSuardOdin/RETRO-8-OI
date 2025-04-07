/**
 * @file cpu_load.h
 * @author Erwann SUARD
 * @brief This file is used to implement gameboy's cpu control flow. This is done with the help of https://rgbds.gbdev.io/docs/v0.9.1/gbz80.7 
 * @version 0.1
 * @date 2025-04-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef CPU_CONTROL_FLOW_H
#define CPU_CONTROL_FLOW_H

#include "../gameboy.h"

/**
 * @brief Unconditional jump to the absolute address specified by the 16-bit immediate operand nn.
 * 
 * OPCODE : 0b11000011/0xC3 | CYCLES : 3 | LENGTH : 4
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int jp_nn(gameboy *gb);


/**
 * @brief Unconditional jump to the absolute address specified by the 16-bit register HL.
 * 
 * OPCODE : 0b11101001/0xE9 | CYCLES : 1 | LENGTH : 1
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int jp_hl(gameboy *gb);


/**
 * @brief Conditional jump to the absolute address specified by the 16-bit operand nn, 
 * depending on the condition cc.
 *
 * Note that the operand (absolute address) is read even when the condition is false!
 * 
 * OPCODE : 0b110xx010 | CYCLES : 3 or 4 (check doc) | LENGTH : 3
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int jp_cc_nn(gameboy* gb, uint8_t opcode);


/**
 * @brief Unconditional jump to the relative address specified by the signed 8-bit operand e
 * 
 * OPCODE : 0b00011000/0x18 | CYCLES : 3 | LENGTH : 2
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int jr_e(gameboy *gb);


/**
 * @brief Conditional jump to the relative address specified by the signed 8-bit operand e, 
 * depending on the condition cc.
 * 
 * Note that the operand (relative address offset) is read even when the condition is false!
 * 
 * OPCODE : 0b001xx000 | CYCLES : 3 (cc = true) or 2 (cc = false) | LENGTH : 2
 * @author Erwann SUARD
 * @param gb Gameboy struct
 * @return TO DETERMINE
 */
int jr_cc_e(gameboy *gb);

#endif