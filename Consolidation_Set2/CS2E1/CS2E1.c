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
void get_name(char* name);
bool string_compare(char* name1, char* name2);

int main(void)
{
    struct Students student[5] = {{"John", 17, 80}, {"Lea", 18, 95},
    {"Billy", 25, 78}, {"Lina", 20, 89}, {"Alex", 23, 56}};
    
    char name[30];

    display_students(student);
    printf("\n");

    highest_grade(student);
    printf("\n");

    youngest_student(student);
    printf("\n");

    get_name(name);
    printf("You are looking for %s\n", name);

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

void get_name(char* name)
{
    printf("Who are you looking for ? ");
    scanf("%29s", name);
}

bool string_compare(char* name1, char* name2)
{
    int count = 0;

    while(name1[count] != '\0' || name2[count] != '\0')
    {
        if(name1[count] != name2[count])
        {
            return false;
        }
        count++;
    }
    return true;
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