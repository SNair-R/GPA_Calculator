#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

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

void InitClass(FILE *f)
{
    int credits;
    int topics;
    printf("\nHow many Credit Hours does class give? ");
    scanf("%d", &credits);
    printf("\nHow many topics are being graded? ");
    scanf("%d", &topics);
}

void AddClass()
{
    DIR *dir = opendir("./Classes");
    if (dir == NULL)
    {
        printf("No Classes folder found making one right now.\n");
        mkdir("./Classes");
    }
    else
    {
        closedir(dir);
    }

    ListClasses();
    char newclass[50];
    printf("What is the name of the class you want to add?\n");
    scanf("%s", newclass);

    char filename[50];
    sprintf(filename, "./Classes/%s.txt", newclass);

    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Could not add class\n");
        return;
    }
    printf("\nClass %s added successfully !\n", newclass);

    InitClass(f);
    return;
}