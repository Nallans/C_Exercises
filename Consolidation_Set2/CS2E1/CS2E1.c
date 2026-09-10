#include <stdio.h>
#include <stdbool.h>

struct Students
{
    char name[30];
    int age, grade;
};

void display_students(struct Students* student);
void highest_grade(struct Students* student);
void youngest_student(struct Students* student);

int main(void)
{
    struct Students student[5] = {{"John", 17, 80}, {"Lea", 18, 95},
    {"Billy", 25, 78}, {"Lina", 20, 89}, {"Alex", 23, 56}};

    display_students(student);
    printf("\n");

    highest_grade(student);
    printf("\n");

    youngest_student(student);
    printf("\n");

    return(0);
}

void display_students(struct Students* student)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Student : %s, Age %d, Grade : %d\n",
        student[i].name, student[i].age, student[i].grade);
    }
}

void highest_grade(struct Students* student)
{
    int highest = 0, index = 0;
    
    for(int i = 0; i < 5; i ++)
    {
        if(student[i].grade > highest)
        {
            highest = student[i].grade;
            index = i;
        }
    }
    printf("%s has the highest grade with %d / 100\n",
        student[index].name, student[index].grade);
}

void youngest_student(struct Students* student)
{
    int youngest = 100, index = 0;

    for(int i = 0; i < 5; i++)
    {
        if(student[i].age < youngest)
        {
            youngest = student[i].age;
            index = i;
        }
    }
    printf("%s is the youngest student at %d years old.\n",
        student[index].name, student[index].age);
}

/*
CS2E1 — Student Records

Create a structure representing a student.

Each student has:

a name
an age
a grade

Store 5 students.

Then:

Display all students.
Find the student with the highest grade.
Find the youngest student.
Ask for a name and search for that student.
*/