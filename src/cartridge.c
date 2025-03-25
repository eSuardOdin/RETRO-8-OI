
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "../headers/cartridge.h"

int load_cart(char *path, cartridge* c)
{
    uint16_t address; 
    // Open cart
    int fd = open(path, O_RDONLY);
    if(fd == -1)
    {
        perror("Open ROM");
        exit(EXIT_FAILURE);
    }

    // Get title
    address = 0x134;
    for(int i = 0; i < 16; i++)
    {
        if(pread(fd, c->title, 16, address) == -1)
        {
            perror("Reading title");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    printf("%s\n", c->title);
    return 0;
}