/**
 * @file cpu_rotate.h
 * @author Louis Gallo
 * @brief This file is used to implement all gameboy's cpu rotate instructions
 * @version 0.1
 * @date 07/04/2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #ifndef CPU_ROTATE_H
 #define CPU_ROTATE_H

#include "../gameboy.h"
#include <stdint.h>

// ########## Rotate ###########

/**
  * @brief Rotate the contents of register A to the left. 
  * That is, the contents of bit 0 are copied to bit 1, and the previous contents of bit 1 (before the copy operation) are copied to bit 2. 
  * The same operation is repeated in sequence for the rest of the register. The contents of bit 7 are placed in both the CY flag and bit 0 of register A.
  * 
  * OPCODE 0b00000111/0x07 | CYCLES : 1 | LENGTH : 1
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_lc_a(gameboy* gb);


/**
  * @brief Rotate the contents of register A to the right. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the register. The contents of bit 0 are placed in both the CY flag and bit 7 of register A.
  * 
  * OPCODE 0b00001111/0x0F | CYCLES : 1 | LENGTH : 1
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_rc_a(gameboy* gb);
 

/**
  * @brief Rotate the contents of register A to the left, through the carry (CY) flag. 
  * That is, the contents of bit 0 are copied to bit 1, and the previous contents of bit 1 (before the copy operation) are copied to bit 2. 
  * The same operation is repeated in sequence for the rest of the register. The previous contents of the carry flag are copied to bit 0.
  * 
  * OPCODE 0b00010111/0x17 | CYCLES : 1 | LENGTH : 1
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_l_a(gameboy* gb);


/**
  * @brief Rotate the contents of register A to the right, through the carry (CY) flag. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the register. The previous contents of the carry flag are copied to bit 7.
  * 
  * OPCODE 0b00011111/0x1F | CYCLES : 1 | LENGTH : 1
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_r_a(gameboy* gb);


 /**
  * @brief Rotate the contents of register R to the left. 
  * That is, the contents of bit 0 are copied to bit 1, and the previous contents of bit 1 (before the copy operation) are copied to bit 2. 
  * The same operation is repeated in sequence for the rest of the register. The contents of bit 7 are placed in both the CY flag and bit 0 of register R.
  * 
  * OPCODE 0b00000xxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_lc_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Rotate the contents of register that HL points to the left. 
  * That is, the contents of bit 0 are copied to bit 1, and the previous contents of bit 1 (before the copy operation) are copied to bit 2. 
  * The same operation is repeated in sequence for the rest of the register. The contents of bit 7 are placed in both the CY flag and bit 0 of register that HL points.
  * 
  * OPCODE 0b00000110/0x06 | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_lc_hl(gameboy* gb);

/**
  * @brief Rotate the contents of register R to the right. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the register. The contents of bit 0 are placed in both the CY flag and bit 7 of register R.
  * 
  * OPCODE 0b00001xxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo

  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_rc_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Rotate the contents of register that HL points to the right. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the register. The contents of bit 0 are placed in both the CY flag and bit 7 of register that HL points.
  * 
  * OPCODE 0b00001110/0x0E | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_rc_hl(gameboy* gb);


/**
  * @brief Rotate the contents of register R to the left, through the carry (CY) flag. 
  * That is, the contents of bit 0 are copied to bit 1, and the previous contents of bit 1 (before the copy operation) are copied to bit 2. 
  * The same operation is repeated in sequence for the rest of the register. The previous contents of the carry flag are copied to bit 0.
  * 
  * OPCODE 0b00010xxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_l_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Rotate the contents of register that HL points to the left, through the carry (CY) flag. 
  * That is, the contents of bit 0 are copied to bit 1, and the previous contents of bit 1 (before the copy operation) are copied to bit 2. 
  * The same operation is repeated in sequence for the rest of the register. The previous contents of the carry flag are copied to bit 0.
  * 
  * OPCODE 0b00010110/0x16 | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_l_hl(gameboy* gb);


/**
  * @brief Rotate the contents of register R to the right, through the carry (CY) flag. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the register. The previous contents of the carry flag are copied to bit 7.
  * 
  * OPCODE 0b00011xxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_r_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Rotate the contents of register that HL points to the right, through the carry (CY) flag. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the register. The previous contents of the carry flag are copied to bit 7.
  * 
  * OPCODE 0b00011110/0x1E | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int r_r_hl(gameboy* gb);

/**
  * @brief Shift the contents of register R to the left. 
  * That is, the contents of bit 0 are copied to bit 1, and the previous contents of bit 1 (before the copy operation) are copied to bit 2. 
  * The same operation is repeated in sequence for the rest of the register. The contents of bit 7 are copied to the CY flag, and bit 0 of register R is reset to 0.
  * 
  * OPCODE 0b00100xxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int s_la_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Shift the contents of memory specified by register pair HL to the left. 
  * That is, the contents of bit 0 are copied to bit 1, and the previous contents of bit 1 (before the copy operation) are copied to bit 2. 
  * The same operation is repeated in sequence for the rest of the memory location. The contents of bit 7 are copied to the CY flag, and bit 0 of (HL) is reset to 0.
  * 
  * OPCODE 0b00100110/0x26 | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int s_la_hl(gameboy* gb);


/**
  * @brief Shift the contents of register R to the right. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy operation) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the register. The contents of bit 0 are copied to the CY flag, and bit 7 of register R is unchanged.
  * 
  * OPCODE 0b00101xxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int s_ra_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Shift the contents of memory specified by register pair HL to the right. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy operation) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the memory location. The contents of bit 0 are copied to the CY flag, and bit 7 of (HL) is unchanged.
  * 
  * OPCODE 0b00101110/0x2E | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int s_ra_hl(gameboy* gb);


/**
  * @brief Shift the contents of the lower-order four bits (0-3) of register R to the higher-order four bits (4-7) of the register, 
  * and shift the higher-order four bits to the lower-order four bits.
  * 
  * OPCODE 0b00110xxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int swap_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Shift the contents of the lower-order four bits (0-3) of the contents of memory specified by 
  * register pair HL to the higher-order four bits (4-7) of that memory location, 
  * and shift the contents of the higher-order four bits to the lower-order four bits.
  * 
  * OPCODE 0b00110110/0x36 | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int swap_hl(gameboy* gb);


/**
  * @brief Shift the contents of register R to the right. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy operation) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the register. 
  * The contents of bit 0 are copied to the CY flag, and bit 7 of register R is reset to 0.
  * 
  * OPCODE 0b00111xxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int s_rl_r8(uint8_t opcode, gameboy* gb);

 
/**
  * @brief Shift the contents of memory specified by register pair HL to the right. 
  * That is, the contents of bit 7 are copied to bit 6, and the previous contents of bit 6 (before the copy operation) are copied to bit 5. 
  * The same operation is repeated in sequence for the rest of the memory location. 
  * The contents of bit 0 are copied to the CY flag, and bit 7 of (HL) is reset to 0.
  * 
  * OPCODE 0b00111110/various | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int s_rl_hl(gameboy* gb);


/**
  * @brief Copy the complement of the contents of bit b in register R 
  * to the Z flag of the program status word (PSW).
  * 
  * OPCODE 0b01xxxxxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int bit_b_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Copy the complement of the contents of bit b in the memory location specified 
  * by register pair HL to the Z flag of the program status word (PSW).
  * 
  * OPCODE 0b01xxx110/various | CYCLES : 3 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int bit_b_hl(uint8_t opcode, gameboy* gb);

 
/**
  * @brief Reset bit b in register R to 0.
  * 
  * OPCODE 0b10xxxxxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int res_b_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Reset bit b in the memory location specified by register pair HL to 0..
  * 
  * OPCODE 0b10xxx110/various | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int res_b_hl(uint8_t opcode, gameboy* gb);


/**
  * @brief Set bit b in register R to 1.
  * 
  * OPCODE 0b11xxxxxx/various | CYCLES : 2 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int set_b_r8(uint8_t opcode, gameboy* gb);


/**
  * @brief Set bit b in the memory location specified by register pair HL to 1.
  * 
  * OPCODE 0b11xxx110/various | CYCLES : 4 | LENGTH : 2
  * @author Louis Gallo
  * @param opcode Opcode to get register from
  * @param gb Gameboy struct
  * @return TO DETERMINE
  */
int set_b_hl(uint8_t opcode, gameboy* gb);


 #endif