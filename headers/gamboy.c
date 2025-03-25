#include "gameboy.h"
#include <string.h>

void reset_gameboy(gameboy *gb)
{
    memset(gb, 0, sizeof(gameboy));
    gb->reg->pc = 0x0100;
}


int load_cart(char *path)
{
    
}