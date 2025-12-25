#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 100
int main(int argc, char *argv[])
{
    int fd,iRet;
    char buffer[BUF_SIZE];
    ssize_t bytes;

    fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (fd < 0)
    {
        perror("Unable to open file");
        return 1;
    }

    iRet=read(fd,buffer,sizeof(buffer));
    bytes = write(fd, buffer, sizeof(buffBUF_SIZEer));BUF_SIZE
    printf("Bytes written: %ld\n", bytes);

    close(fd);
    return 0;

    iRet=read(fd,buffer,sizeof(buffer));
    bytes = write(fd, buffer, sizeof(buffBUF_SIZEer));BUF_SIZE
    printf("Bytes written: %ld\n", bytes);
    return 0;
}

