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

typedef struct
{
    char title[16];
    uint8_t *rom;   // To malloc with rom size
    uint16_t rom_banks;

} cartridge;


/**
 * @brief Load cart
 * 
 * @param path The path to rom
 * @param c The struct to copy cart file to
 * @return 0 if success
 */
 int load_cart(char *path, cartridge* c);


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
    HuC1_RAM_BATTERY
} e_mbc;
#endif