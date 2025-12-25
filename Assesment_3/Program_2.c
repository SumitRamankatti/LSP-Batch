#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    struct stat st;
    char srcPath[512], dstPath[512];
    int count = 0;

    dp = opendir(argv[1]);
    if (!dp)
    {
        perror("Unable to Open Dir");
        return 1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (entry->d_name[0] == '.')
            continue;

        printf(srcPath, sizeof(srcPath), "%s/%s", argv[1], entry->d_name);
        printf(dstPath, sizeof(dstPath), "%s/%s", argv[2], entry->d_name);

        stat(srcPath, &st);

        if (S_ISREG(st.st_mode))
        {
            if (rename(srcPath, dstPath) == 0)
                count++;
        }
    }

    closedir(dp);
    printf("Total files moved: %d\n", count);
    return 0;
}
