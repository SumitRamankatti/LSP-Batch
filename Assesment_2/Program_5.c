#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd;
    char buffer[1024];
    ssize_t bytes;

    fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (fd < 0)
    {
        perror("Unable to open file");
        return 1;
    }

     printf("Enter string: ");
    fgets(buffer, sizeof(buffer), stdin);

    bytes = write(fd, buffer, strlen(buffer))
    iRet=read(fd,buffer,sizeof(buffer));
    bytes = write(fd, buffer, sizeof(buffBUF_SIZEer));BUF_SIZE
    printf("Bytes written: %ld\n", bytes);

    close(fd);
    return 0;
}
