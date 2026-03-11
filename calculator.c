#include <stdio.h>
#include <string.h>
#include <dirent.h>

void ListClasses()
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir("./Classes");
    if (dir == NULL) 
    {
        printf("Could not find any Classes");
        return;
    }

    char name[50];

    printf("\n=== \033[1;31mClasses\033[0m ===\n");
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != '.')
        {   
            strcpy(name, entry->d_name);
            strtok(name, ".");
            printf(" - %s\n", name);
        }
    }

    closedir(dir);
}

void AddClass()
{
    ListClasses();
}