#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>#include <unistd.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int fd;
    
    fd = open(argv[1], O_RDONLY);

        if (fd == -1) {
        perror("Unable to open file");
        return 1;
    }

    printf("File opened successfully!\n");
    printf("File descriptor: %d\n", fd);

    close(fd);

    return 0;
}

