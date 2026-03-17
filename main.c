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
        printf("\nOption 3: Calculate Your GPA");
        printf("\nOption 4: Delete a Class");
        printf("\nOption 5: Exit the Program");
        printf("\nChoose: option (1 - 5): ");
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
                CalcGPA();
                break;
            case 4:
                DeleteClass();
                break;
            case 5:
                printf("Exiting Calculator Bye Bye !\n");
                break;
            default:
            printf("Invalid option try again\n");

        }
    }
    while (choice != 5);
}