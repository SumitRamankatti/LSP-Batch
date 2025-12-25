#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 100

int main(int argc, char *argv[])
{
    int fd;
    char buffer[BUF_SIZE];
    ssize_t bytes;
    int total = 0;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Unable to open File");
        return 1;
    }

    while ((bytes = read(fd, buffer, BUF_SIZE)) > 0)
    {
        printf("%s",buffer);
        total += bytes;
    }

    printf("\nTotal bytes read: %d\n", total);

    close(fd);
    return 0;
}
