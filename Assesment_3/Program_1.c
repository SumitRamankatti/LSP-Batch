#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int srcfd, dstfd;
    char buffer[BUF_SIZE];
    ssize_t bytes;
    struct stat st;

    srcfd = open(argv[1], O_RDONLY);
    if (srcfd < 0)
    {
        perror("Source open failed");
        return 1;
    }

    fstat(srcfd, &st);

    dstfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, st.st_mode);
    if (dstfd < 0)
    {
        perror("Destination open failed");
        close(srcfd);
        return 1;
    }

    while ((bytes = read(srcfd, buffer, BUF_SIZE)) > 0)
        write(dstfd, buffer, bytes);

    chmod(argv[2], st.st_mode);

    close(srcfd);
    close(dstfd);

    printf("File copied successfully\n");
    return 0;
}
