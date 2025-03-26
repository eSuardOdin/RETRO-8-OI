
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "../headers/cartridge.h"

int load_cart(char *path, cartridge* c)
{
    struct stat st;
    uint16_t address;
    uint8_t byte;

    // Open cart
    int fd = open(path, O_RDONLY);
    if(fd == -1)
    {
        perror("Open ROM");
        exit(EXIT_FAILURE);
    }

    // Get stats to debug
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    // Get title
    address = 0x134;
    if(pread(fd, c->title, 16, address) == -1)
    {
        strerror(errno);
        perror("Reading title");
        close(fd);
        exit(EXIT_FAILURE);
    }
    

    // Get gen (if 0x80 -> CGB but retro compatible / if 0xC0 CGB only)
    address = 0x0143;
    if(pread(fd, &byte, 1, address) == -1)
    {
        perror("Reading CGB status");
        close(fd);
        exit(EXIT_FAILURE);
    }
    c->gen_type = get_cgb(byte);

    // Get SGB ? -0x0146- (useless for now I think)


    // Get cartridge type
    address = 0x0146; 
    if(pread(fd, &byte, 1, address) == -1)
    {
        perror("Reading cartridge type");
        close(fd);
        exit(EXIT_FAILURE);
    }
    c->cart_type = get_mbc(byte);
    if(c->cart_type == UNKNOWN_MBC)
    {
        fprintf(stderr, "Error, cartridge type is UNKNOWN.\n");
        exit(EXIT_FAILURE);
    }

    // Get ROM Banks
    address = 0x0148; 
    if(pread(fd, &byte, 1, address) == -1)
    {
        perror("Reading ROM banks");
        close(fd);
        exit(EXIT_FAILURE);
    }
    c->rom_banks = get_rom_banks(byte);

    // Get ROM Size (32 KiB * (1 << rom_banks))
    c->rom_size = 0x8000 * (1 << c->rom_banks);
    printf("##################################\n");
    printf("%s\n\tCGB : %d\n\tMBC : %d\n\tRom Size : %d | Rom Banks : %d\n", c->title, c->gen_type, c->cart_type, c->rom_size, c->rom_banks);
    printf("##################################\n");
    
    return 0;
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


uint16_t get_rom_banks(uint8_t byte)
{
    switch (byte)
    {
        case 0x0 :
            return 2;
        case 0x1 :
            return 4;
        case 0x2 :
            return 8;
        case 0x3 :
            return 16;
        case 0x4 :
            return 32;
        case 0x5 :
            return 64;
        case 0x6 :
            return 128;
        case 0x7 :
            return 256;
        case 0x8 :
            return 512;
        // -- See docs : Never seen officially the next 3 --
        case 0x52 :
            return 72;
        case 0x53 :
            return 80;
        case 0x54 :
            return 96;    
    }
}