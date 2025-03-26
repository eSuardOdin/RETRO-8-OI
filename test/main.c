#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char title[17];
    int fd = open(argv[1], O_RDONLY);

    pread(fd, title, 16, 0x134);
    printf("%s\n", title);
    return 0;
}

