#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int ListClasses()
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir("./Classes");
    if (dir == NULL) 
    {
        printf("Could not find any Classes");
        return 1;
    }

    char name[50];
    int hasclasses = 0;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != '.')
        {
            if (!hasclasses)
            {
                printf("\n=== \033[1;31mClasses\033[0m ===\n");
                hasclasses = 1;
            }  
            strcpy(name, entry->d_name);
            strtok(name, ".");
            printf(" - %s\n", name);
        }
    }

    if (!hasclasses)
    {
        printf("\nNo Classes Found\n");
        return 1;
    }
    
    closedir(dir);
    return 0;
}

void InitClass(FILE *f)
{
    int credits;
    int topics;
    printf("\nHow many Credit Hours does class give? ");
    scanf("%d", &credits);
    printf("\nHow many topics are being graded? ");
    scanf("%d", &topics);
    fprintf(f, "%d\n%d\n", credits, topics);

    char topicname[10][50];
    int weight;
    for (int i = 0; i < topics; i++)
    {
        printf("\nWhat is the name of topic %d? ", i + 1);
        scanf(" %[^\n]", topicname[i]);
        printf("How much is %s weighted (Enter a Whole Number)", topicname[i]);
        scanf(" %d", &weight);
        fprintf(f,"#%s %d\n",topicname[i], weight);
    }
        fprintf(f,"Grades:\n");
        for (int i = 0; i < topics; i++)
        {
            fprintf(f,"#%s \n",topicname[i]);
        }
    fclose(f);
}

void AddGrades()
{
    DIR *dir = opendir("./Classes");
    if (dir == NULL)
    {
        printf("\n\nNo Classes folder found making one right now.\n\n");

        #ifdef _WIN32
            mkdir("./Classes");
        #else
            mkdir("./Classes", 0777);
        #endif
    }
    else
    {
        closedir(dir);
    }

    if (ListClasses())
    {
        printf("\nPlease Add Classes First\n");
        return;
    }
    printf("\nWhich Class's grades would you like to update?\n");

}

void AddClass()
{
    DIR *dir = opendir("./Classes");
    if (dir == NULL)
    {
        printf("\n\nNo Classes folder found making one right now.\n\n");

        #ifdef _WIN32
            mkdir("./Classes");
        #else
            mkdir("./Classes", 0777);
        #endif
    }
    else
    {
        closedir(dir);
    }

    ListClasses();
    char newclass[50];
    printf("What is the name of the class you want to add?\n");
    scanf(" %[^\n]", newclass);

    char filename[100];
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