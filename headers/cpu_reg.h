/**
 * @file cpu_reg.h
 * @author Erwann SUARD
 * @brief Defines the struct used to manipulate CPU registers. As specified in pandocs, some 8bit registers can be mixed to use them as 16 bits register (https://gbdev.io/pandocs/CPU_Registers_and_Flags.html)
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef CPU_REG_H
#define CPU_REG_H

#include <stdint.h>


typedef struct {
    union {
        struct {
            /**
             * @brief Accumulator register.
             */
            uint8_t a;
            /**
             * @brief Flag register, lower nibble must ALWAYS be zero.<br>
             * Bit 7 : Zero flag            (z)<br>
             * Bit 6 : Substraction flag    (s)<br>
             * Bit 5 : Half carry flag      (h)<br>
             * Bit 4 : Carry flag           (c)
             */
            uint8_t f; 
        };

        uint16_t af;
    };
    union {
        struct {
            uint8_t b;
            uint8_t c; 
        };
        uint16_t bc;
    };
    union {
        struct {
            uint8_t d;
            uint8_t e; 
        };
        uint16_t de;
    };
    union {
        struct {
            uint8_t h;
            uint8_t l; 
        };
        uint16_t hl;
    };

    /**
     * @brief Instruction Register
     * 
     */
    uint8_t ir;

    /**
     * @brief Interrupt Enable
     * 
     */
    uint8_t ie;

    /**
     * @brief Stack pointer
     */
    uint16_t sp;
    /**
     * @brief Program counter
     */
    uint16_t pc;
} cpu_reg;

#endif