#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    struct stat st;
    char path[512];

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        perror("opendir failed");
        return 1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
        lstat(path, &st);

        printf("%s : ", entry->d_name);

        if (S_ISREG(st.st_mode))
            printf("Regular File");
        else if (S_ISDIR(st.st_mode))
            printf("Directory");
        else if (S_ISLNK(st.st_mode))
            printf("Link");
        else if (S_ISFIFO(st.st_mode))
            printf("FIFO");
        else if (S_ISSOCK(st.st_mode))
            printf("Socket");
        else if (S_ISCHR(st.st_mode))
            printf("Character Device");
        else if (S_ISBLK(st.st_mode))
            printf("Block Device");

        printf("\n");
    }

    closedir(dp);
    return 0;
}
