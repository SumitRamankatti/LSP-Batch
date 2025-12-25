#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        perror("opendir failed");
        return 1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (entry->d_name[0] != '.')
            printf("%s\n", entry->d_name);
    }

    closedir(dp);
    return 0;
}
