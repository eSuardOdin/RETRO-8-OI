#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "../headers/gameboy.h"
#include "../headers/cartridge.h"
#include "../headers/memory.h"
#include "../headers/memory_constants.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage : ./gb ROM_FILE\n");
        exit(EXIT_FAILURE);
    }

    // Init gameboy
    gameboy *g = malloc(sizeof(gameboy));
    reset_gameboy(g);
    
    // Load cart
    cartridge *c = malloc(sizeof(cartridge));
    load_cart(argv[1], c);
    return 0;
}