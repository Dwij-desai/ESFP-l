#include <stdio.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[20];
    char std[20];
    char semester[20];
    char subject[20];
    int exam_fee;
} students[50];

int main()
{
    int n, i;
    
    printf("Enter how many records you want to store: ");
    scanf("%d", &n);

    printf("Enter rollno, name, class, semester, subject, and exam fee:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %s %s %s %s %d", &students[i].rollno, students[i].name, students[i].std, students[i].semester, students[i].subject, &students[i].exam_fee);
    }

    printf("\nStudent Records:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].std, students[i].semester, students[i].subject, students[i].exam_fee);
    }

    int search_id;
    printf("Find the student record by ID:\n");
    printf("Enter student ID: ");
    scanf("%d", &search_id);

    for (i = 0; i < n; i++)
    {
        if (students[i].rollno == search_id)
        {
            printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].std, students[i].semester, students[i].subject, students[i].exam_fee);
            break;
        }
    }

    if (i == n)
    {
        printf("Student with ID %d not found.\n", search_id);
    }

    return 0;
}
