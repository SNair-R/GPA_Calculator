#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef struct
{
    int credits;
    float grade;
} ClassData;

int ListClasses();
void AddClass();
void InitClass(FILE *f);
void AddGrades();
ClassData CalcGrade(char filename[]);
void CalcGPA();
void DeleteClass();

#endif // CALCULATOR_H