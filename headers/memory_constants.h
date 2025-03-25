/**
 * @file memory_constants.h
 * @author Erwann Suard
 * @brief Define constant adresses used to access special "registers" in RAM - Doing only DMG (original GB)
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef MEMORY_CONSTANTS_H
#define MEMORY_CONSTANTS_H

// O#########################O
// |                         |
// |    SPECIAL REGISTERS    |
// |                         |
// O#########################O




// ##############
// ### Joypad ###
// ##############
/**
 * @brief Joypad Register
 */
#define JOYP 0xFF00

// #######################
// ### Serial Transfer ###
// #######################
/**
 * @brief Serial Byte - The next byte to be transfered
 */
#define SB 0xFF01

/**
 * @brief Serial Control - Used to check transfer status
 */
#define SC 0xFF02

// ###########################
// ### Timers and Dividers ###
// ###########################
/**
 * @brief Divider Register - Increments at ~0.016MhZ
 */
#define DIV 0xFF04

/**
 * @brief Timer Counter - Increments at speed specified by TAC (FF07).<br>
 * When overflow, resets to value specified in TMA (FF06) and interrupt requested.
 */
#define TIMA 0xFF05

/**
 * @brief Timer Modulo - Generates an interrupt when TIMA (FF05) overflows.
 */
#define TMA 0xFF06

/**
 * @brief Timer Control - Enable/Disable TIMA and select its frequency (see details)
 * @details https://gbdev.io/pandocs/Timer_and_Divider_Registers.html#ff07--tac-timer-control
 */
#define TAC 0xFF07


// ############################
// ### Interrupt Management ###
// ############################

/**
 * @brief Interrupt Flag - Used to know if an interrupt is requested
 * @details Manages all the interrupts depending on bits set :<br>
 * Bit 0 : VBlank <br>
 * Bit 1 : LCD <br>
 * Bit 2 : Timer <br>
 * Bit 3 : Serial <br>
 * Bit 4 : Joypad <br>
 * See specifics at https://gbdev.io/pandocs/Interrupts.html#ff0f--if-interrupt-flag
 */
#define IF 0xFF0F

/**
 * @brief Interrupt Enable - Same bit order as IF (FF0F)
 */
#define IE 0xFFFF


// #############
// ### Audio ###
// #############
// Oui ben we'll see mais it will wait brother
// 0xFF10 - 0xFF3F



// #####################
// ### LCD Registers ###
// #####################

/**
 * @brief LDC Control - Manages what elements are printed on screen and how
 * @details Check doc at https://gbdev.io/pandocs/LCDC.html#ff40--lcdc-lcd-control
 */
#define LCDC 0xFF40 

/**
 * @brief LCD Status - Check doc
 */
#define STAT 0xFF41

/**
 * @brief Background Viewport Y - Topleft Y axis of visible area in BG map.
 */
#define SCY 0xFF42

/**
 * @brief Background Viewport X - Topleft X axis of visible area in BG map.
 */
#define SCX 0xFF43

/**
 * @brief Window Y Position - Onscreen coordinate of the window's Y top left pixel.
 */
#define WY 0xFF4A

/**
 * @brief Window X Position - Onscreen coordinate of the window's X top left pixel.
 */
 #define WX 0xFF4B

/**
 * @brief LCD Y coordinate [READ ONLY] - Indicate line to draw, drawing or just been drawn.
 */
#define LY 0xFF44

/**
 * @brief LY Compare - GameBoy checks if LYC = LY and set STAT interrupt if enabled.
 */
#define LYC 0xFF45


// ##########################
// ### Tiles and Palettes ###
// ##########################

/**
 * @brief OAM DMA - Contains source from RAM or ROM to copy into OAM, writing to this register starts the DMA transfer.
 */
#define DMA 0xFF46

/**
 * @brief Background Palette Data - Assigns shades of gray for BG and Windows tiles.
 */
#define BGP 0xFF47

/**
 * @brief OBJ Palette 0
 */
#define OBP0 0xFF48

/**
 * @brief OBJ Palette 1
 */
#define OBP1 0xFF49






// O##########################O
// |                          |
// |      MEMORY OFFSETS      |
// |                          |
// O##########################O

#define VRAM_OFST 0X8000

#define EXT_RAM_OFST 0XA000

#define WRAM_OFST 0XC000

#define OAM_OFST 0XFE00

#define IO_OFST 0XFF00

#define HRAM_OFST 0XFF80

#endif