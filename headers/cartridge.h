/**
 * @file cartridge.h
 * @author Erwann SUARD
 * @brief Defines a cartridge and associated functions, most of infos are from cart header : https://gbdev.io/pandocs/The_Cartridge_Header.html#0147--cartridge-type
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <stdint.h>
/**
 * @brief Enum of cartridge type, can be used in memory bank switching later. 
 * 
 */
typedef enum
{
    ROM_ONLY,
    MBC1,
    MBC1_RAM,
    MBC1_RAM_BATTERY,
    MBC2,
    MBC2_BATTERY,
    ROM_RAM,
    ROM_RAM_BATTERY,
    MMM01,
    MMM01_RAM,
    MMM01_RAM_BATTERY,
    MBC3_TIMER_BATTERY,
    MBC3_TIMER_RAM_BATTERY,
    MBC3,
    MBC3_RAM,
    MBC3_RAM_BATTERY,
    MBC5,
    MBC5_RAM,
    MBC5_RAM_BATTERY,
    MBC5_RUMBLE,
    MBC5_RUMBLE_RAM,
    MBC5_RUMBLE_RAM_BATTERY,
    MBC6,
    MBC7_SENSOR_RUMBLE_RAM_BATTERY,
    POCKET_CAMERA,
    BANDAI_TAMA5,
    HuC3,
    HuC1_RAM_BATTERY,
    UNKNOWN_MBC
} e_mbc;

/**
 * @brief Enum for DMG, CGB only or retro-compatible CGB
 * 
 */
typedef enum {
    DMG,
    CGB_DMG,
    CGB
} e_cgb;

typedef struct
{
    char title[17];
    e_mbc mbc_type;
    e_cgb gen_type;
    uint16_t rom_banks;
    uint32_t rom_size;
    uint16_t ram_banks;
    uint32_t ram_size;
    uint8_t header_checksum;
    uint8_t *rom;   // To malloc with rom size
} cartridge;


/**
 * @brief Load cart and init cartridge struct
 * 
 * @param path The path to rom
 * @param c The struct to copy cart file to
 * @return Returns the cart to be loaded in gameboy struct
 */
cartridge* load_cart(char *path, cartridge* c);

/**
 * @brief Get the mbc type
 * 
 * @param byte Byte at address 0x147 representing Cartridge type.
 * @return e_mbc 
 */
e_mbc get_mbc(uint8_t byte);

/**
 * @brief Get the cgb status
 * 
 * @param byte Byte at address 0x0143
 * @return e_cgb 
 */
e_cgb get_cgb(uint8_t byte);

/**
 * @brief Get the number of rom banks and rom size based on byte at 0x0148<br>
 * ### Warning ###<br>Changes the struct attributes directly 
 * @param byte The value checked in header
 * @param cartridge The cartridge struct to modify (rom_banks and rom_size)
 * @return error status to implement
 */
int get_rom_banks_size(uint8_t byte, cartridge *c);


/**
 * @brief Get the number of ram banks and ram size based on byte at 0x0149<br>
 * ### Warning ###<br>Changes the struct attributes directly 
 * @param byte The value checked in header
 * @param cartridge The cartridge struct to modify (ram_banks and ram_size)
 * @return error status to implement
 */
int get_ram_banks_size(uint8_t byte, cartridge *c);
#endif