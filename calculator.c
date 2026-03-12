#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

int ListClasses()
{
    DIR *dir;
    struct dirent *entry; // sets up struct for directory

    dir = opendir("./Classes"); // checks if any classes exists
    if (dir == NULL) 
    {
        printf("Could not find any Classes");
        return 1;
    }

    char name[50];
    int hasclasses = 0;

    while ((entry = readdir(dir)) != NULL) // gets the name of each class
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
        closedir(dir);
        return 1;
    }
    
    closedir(dir);
    return 0;
}

void InitClass(FILE *f)
{
    int credits;
    int topics;
    printf("\nHow many Credit Hours does class give? ");  // gets the credit hours and number of topics 
    scanf("%d", &credits);
    printf("\nHow many topics are being graded? ");
    scanf("%d", &topics);
    fprintf(f, "%d\n%d\n", credits, topics);

    char topicname[10][50];
    int weight;
    for (int i = 0; i < topics; i++) // using topic number loops through to get name for each topic and stores it
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
        fprintf(f,"#%s \n",topicname[i]); // uses stored names and writes topics with # as a prefix for identification
    }
    fclose(f);
}

void AddGrades()
{
    DIR *dir = opendir("./Classes");
    if (dir == NULL)
    {
        printf("\n\nNo Classes folder found making one right now.\n\n"); // makes class folder if it doesnt exist

        #ifdef _WIN32
            mkdir("./Classes");
        #else    // difference in how mkdir works on windows and mac
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
    char name[50];
    int tester = 0;
    char filename[100];
    do
    {
        printf("\nWhich Class's grades would you like to update?\n"); // Gets name for class and loops if name is typed incorrectly
        scanf(" %[^\n]", name);
        sprintf(filename, "./Classes/%s.txt", name);
        FILE *f = fopen(filename, "r");
        if (f == NULL)
        {
            printf("Could not find Class try again");
            continue;
        }
        else
        {
            tester++;
            fclose(f);
        }
    }
    while (!tester);

    FILE *f = fopen(filename, "r");
    char line[256]; // variable for getting data
    int topics;
    fgets(line, sizeof(line), f); // skips line 1
    fgets(line, sizeof(line), f); // gets topic number from line 2
    topics = atoi(line);

    char topicnames[topics][100]; // gets names of each topic
    for (int i = 0; i < topics; i++)
    {
        fgets(line, sizeof(line), f);
        line[strcspn(line, " 0123456789")] = 0;
        strcpy(topicnames[i], line + 1);
    }

    printf("\n=== \033[1;34mTopics\033[0m ===\n");
    for (int i = 0; i < topics; i++ )
    {
        printf("- %s\n", topicnames[i]);
    }
    
    /// ==================
    /// ASK FOR WHICH TOPIC FIRST BEFORE ADDING APPENDING GRADES
    /// ==================
    fclose(f);

    int grade_amt;
    printf("\nHow many grades would you like to add?\n");
    scanf(" %d", &grade_amt);

}

void AddClass()
{
    DIR *dir = opendir("./Classes");
    if (dir == NULL)
    {
        printf("\n\nNo Classes folder found making one right now.\n\n"); // makes class folder if it doesnt exist

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
    printf("What is the name of the class you want to add?\n"); //gets name of new class
    scanf(" %[^\n]", newclass);

    char filename[100];
    sprintf(filename, "./Classes/%s.txt", newclass);

    FILE *check = fopen(filename, "r");
    if (check != NULL)
    {
        printf("Class already exists please try again"); // checks if there if class already exists
        return;
    } 
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