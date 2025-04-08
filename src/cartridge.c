
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#include "../headers/cartridge.h"

cartridge* load_cart(char *path, cartridge* c)
{
    uint16_t address;
    uint8_t byte;

    /* Open cart */
    int fd = open(path, O_RDONLY);
    if(fd == -1)
    {
        perror("Open ROM");
        exit(EXIT_FAILURE);
    }

    /* Get title */
    address = 0x134;
    if(pread(fd, c->title, 16, address) == -1)
    {
        strerror(errno);
        perror("Reading title");
        close(fd);
        exit(EXIT_FAILURE);
    }


    /* Get gen (if 0x80 -> CGB but retro compatible / if 0xC0 CGB only) */
    address = 0x0143;
    if(pread(fd, &byte, 1, address) == -1)
    {
        perror("Reading CGB status");
        close(fd);
        exit(EXIT_FAILURE);
    }
    c->gen_type = get_cgb(byte);

    /* Get SGB ? -0x0146- (useless for now I think) */


    /* Get cartridge type */
    address = 0x0147;
    if(pread(fd, &byte, 1, address) == -1)
    {
        perror("Reading cartridge type");
        close(fd);
        exit(EXIT_FAILURE);
    }
    c->mbc_type = get_mbc(byte);
    if(c->mbc_type == UNKNOWN_MBC)
    {
        fprintf(stderr, "Error, cartridge type is UNKNOWN.\n");
        exit(EXIT_FAILURE);
    }

    /* Get ROM Banks and size */
    address = 0x0148;
    if(pread(fd, &byte, 1, address) == -1)
    {
        perror("Reading ROM banks");
        close(fd);
        exit(EXIT_FAILURE);
    }
    if(get_rom_banks_size(byte, c)) // Add error status ?
    {
        exit(EXIT_FAILURE);
    }

    /* Get RAM banks and size */
    address = 0x0149;
    if(pread(fd, &byte, 1, address) == -1)
    {
        perror("Reading RAM banks");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if(get_ram_banks_size(byte, c)) // Add error status ?
    {
        exit(EXIT_FAILURE);
    }

    /* 0x014a : Destination code -> OSEF (?) */
    /* 0x014b : Old licensee code -> OSEF (?) */
    /* 0x014b : Mask ROM version number -> OSEF (?) */


    /* Get header checksum */
    address = 0x014d;
    if(pread(fd, &byte, 1, address) == -1)
    {
        perror("Reading header checksum");
        close(fd);
        exit(EXIT_FAILURE);
    }
    c->header_checksum = byte;

    /* Copy CARTRIDGE */
    c->rom = malloc(c->rom_size);
    if(pread(fd, c->rom, c->rom_size, 0) == -1)
    {
        perror("Copying rom");
        close(fd);
        exit(EXIT_FAILURE);
    }

    /* 0x014e - 0x14f : GLOBAL CHECKSUM -> OSEF (?) */

    return c;
}





cartridge* load_test_cart(char *path, cartridge* c)
{
    /* Open cart */
    int fd = open(path, O_RDONLY);
    if(fd == -1)
    {
        perror("Open ROM");
        exit(EXIT_FAILURE);
    }

    
    /* Copy CARTRIDGE */
    c->rom = malloc(32768);
    if(pread(fd, c->rom, 32768, 0) == -1)
    {
        perror("Copying rom");
        close(fd);
        exit(EXIT_FAILURE);
    }

    /* 0x014e - 0x14f : GLOBAL CHECKSUM -> OSEF (?) */

    return c;
}











e_mbc get_mbc(uint8_t byte)
{
    
    printf("Read banks : %02x\n", byte);
    e_mbc e;
    switch (byte) {
        case 0x00 :
            e = ROM_ONLY;
            break;
        case 0x01 :
            e = MBC1;
            break;
        case 0x02 :
            e = MBC1_RAM;
            break;
        case 0x03 :
            e = MBC1_RAM_BATTERY;
            break;
        case 0x05 :
            e = MBC2;
            break;
        case 0x06 :
            e = MBC2_BATTERY;
            break;
        case 0x08 :
            e = ROM_RAM;
            break;
        case 0x09 :
            e = ROM_RAM_BATTERY;
            break;
        case 0x0b :
            e = MMM01;
            break;
        case 0x0c :
            e = MMM01_RAM;
            break;
        case 0x0d :
            e = MMM01_RAM_BATTERY;
            break;
        case 0x0f :
            e = MBC3_TIMER_BATTERY;
            break;
        case 0x10 :
            e = MBC3_TIMER_RAM_BATTERY;
            break;
        case 0x11 :
            e = MBC3;
            break;
        case 0x12 :
            e = MBC3_RAM;
            break;
        case 0x13 :
            e = MBC3_RAM_BATTERY;
            break;
        case 0x19 :
            e = MBC5;
            break;
        case 0x1a :
            e = MBC5_RAM;
            break;
        case 0x1b :
            e = MBC5_RAM_BATTERY;
            break;
        case 0x1c :
            e = MBC5_RUMBLE;
            break;
        case 0x1d :
            e = MBC5_RUMBLE_RAM;
            break;
        case 0x1e :
            e = MBC5_RUMBLE_RAM_BATTERY;
            break;
        case 0x20 :
            e = MBC6;
            break;
        case 0xfc :
            e = POCKET_CAMERA;
            break;
        case 0xfd :
            e = BANDAI_TAMA5;
            break;
        case 0xfe :
            e = HuC3;
            break;
        case 0xff :
            e = HuC1_RAM_BATTERY;
            break;
        default:
            e = UNKNOWN_MBC;
            break;
    }

    return e;

}


e_cgb get_cgb(uint8_t byte)
{
    e_cgb e;
    switch (byte) {
        case 0x80 :
            e = CGB;
            break;
        case 0xC0 :
            e = CGB_DMG;
            break;
        default:
            e = DMG;
            break;
    }
    return e;
}


int get_rom_banks_size(uint8_t byte, cartridge *c)
{
    // Get ROM Size (32 KiB * (1 << value)
    c->rom_size = 0x8000 * (1 << byte);
    switch (byte)
    {
        case 0x0 :
            c->rom_banks = 2;
            break;
        case 0x1 :
            c->rom_banks = 4;
            break;
        case 0x2 :
            c->rom_banks = 8;
            break;
        case 0x3 :
            c->rom_banks = 16;
            break;
        case 0x4 :
            c->rom_banks = 32;
            break;
        case 0x5 :
            c->rom_banks = 64;
            break;
        case 0x6 :
            c->rom_banks = 128;
            break;
        case 0x7 :
            c->rom_banks = 256;
            break;
        case 0x8 :
            c->rom_banks = 512;
            break;
        // -- See docs : Never seen officially the next 3 --
        case 0x52 :
            c->rom_banks = 72;
            break;
        case 0x53 :
            c->rom_banks = 80;
            break;
        case 0x54 :
            c->rom_banks = 96;
            break;
    }
    return 0;
}


int get_ram_banks_size(uint8_t byte, cartridge *c)
{

    // If MBC type does not include RAM in name -> RAM = 0
    // if(
    //     c->mbc_type != MBC1_RAM &&
    //     c->mbc_type != MBC1_RAM_BATTERY &&
    //     c->mbc_type != ROM_RAM &&
    //     c->mbc_type != ROM_RAM_BATTERY &&
    //     c->mbc_type != MMM01_RAM &&
    //     c->mbc_type != MMM01_RAM_BATTERY &&
    //     c->mbc_type != MBC3_TIMER_RAM_BATTERY &&
    //     c->mbc_type != MBC3_RAM &&
    //     c->mbc_type != MBC3_RAM_BATTERY &&
    //     c->mbc_type != MBC5_RAM &&
    //     c->mbc_type != MBC5_RAM_BATTERY &&
    //     c->mbc_type != MBC5_RUMBLE_RAM &&
    //     c->mbc_type != MBC5_RUMBLE_RAM_BATTERY &&
    //     c->mbc_type != MBC7_SENSOR_RUMBLE_RAM_BATTERY &&
    //     c->mbc_type != HuC1_RAM_BATTERY)
    // {
    //     c->ram_banks = 0;
    //     c->ram_size = 0;
    // }
    // else
    // {
        switch (byte)
        {
            case 0x0:
                c->ram_banks = 0;
                c->ram_size = 0;
                break;
            case 0x2:
                c->ram_banks = 0x1;
                c->ram_size = 0x2000;
                break;
            case 0x3:
                c->ram_banks = 4;
                c->ram_size = 0x8000;
                break;
            case 0x4:
                c->ram_banks = 16;
                c->ram_size = 0x20000;
                break;
            case 0x5:
                c->ram_banks = 8;
                c->ram_size = 0x10000;
                break;
        }
    //}

    return 0;
}