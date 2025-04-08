#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "../headers/gameboy.h"
#include "../headers/cartridge.h"
#include "../headers/memory.h"
#include "../headers/memory_constants.h"
#include "../headers/tests/test_cpu_arithmetic.h"
#include "../headers/tests/test_cpu_control_flow.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage : ./gb ROM_FILE\n");
        exit(EXIT_FAILURE);
    }

    // Init gameboy
    gameboy *gb = malloc(sizeof(gameboy));
    reset_gameboy(gb, argv[1]);
    
    // // Load cart
    // cartridge *c = malloc(sizeof(cartridge));
    // load_cart(argv[1], c);

    //run_gameboy(gb);

    // --- Test cpu_arithmetic ---
    test_add_r8(gb);
    test_sub_r8(gb);
    free(gb);

    // --- Test cpu_control_flow.c ---
    control_test_suite();
    return 0;
}