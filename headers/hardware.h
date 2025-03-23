/**
 * @file hardware.h
 * @author Erwann Suard
 * @brief Define constant adresses used to access special "registers" in RAM
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef HARDWARE_H
#define HARDWARE_H
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
#endif