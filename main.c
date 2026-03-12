#include <stdio.h>
#include "calculator.h"

int main(void)
{
    int choice;

    do
    {
        printf("\n=== \033[1;32mMENU\033[0m ===");
        printf("\nOption 1: Add a Grade");
        printf("\nOption 2: Add a Class");
        printf("\nOption 3: Exit the Program");
        printf("\nChoose an option (1 - 3): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                AddGrades();
                break;
            case 2:
                AddClass();
                break;
            case 3:
                printf("Exiting Calculator Bye Bye !\n");
                break;
            default:
            printf("Invalid option try again\n");

        }
    }
    while (choice != 3);
}