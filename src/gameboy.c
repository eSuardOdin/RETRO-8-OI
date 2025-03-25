#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include "../headers/gameboy.h"

void reset_gameboy(gameboy *gb)
{
    memset(gb, 0, sizeof(gameboy));
    gb->reg = malloc(sizeof(cpu_reg));
    gb->mem = malloc(sizeof(memory));
    // True program start
    gb->reg->pc = 0x0100;
}


