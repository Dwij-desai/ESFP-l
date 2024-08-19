#include <stdio.h>

struct employee
{
    int id;
    char name[20], designation[20], department[20];
    float salary;
} N[5];

int main()
{
    int i;

    printf("======Employee Details======\n");
    printf("Id Name Designation Department Salary\n");
    for (i = 0; i < 4; i++)
    {
        scanf("%d %s %s %s %f", &N[i].id, &N[i].name, &N[i].department, &N[i].designation, &N[i].salary);
    }

    printf("\n");
    printf("======Employee Details======\n");
    printf("Id Name Designation Department Salary\n");
    for (i = 0; i < 4; i++)
    {
        printf("\n%d %s %s %s %f", N[i].id, N[i].name, N[i].department, N[i].designation, N[i].salary);
    }
}
