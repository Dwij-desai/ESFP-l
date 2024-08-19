#include <stdio.h>
#include <string.h>

int sortNames(char *names[], int n) 
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (strcmp(names[j], names[j + 1]) > 0) 
            {
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n;
    printf("Enter Number of student names: ");
    scanf("%d", &n);

    char *studentNames[n];
    printf("Enter %d student names:\n", n);

    for (int i = 0; i < n; i++) 
    {
        char name[50];
        scanf("%s", name);
        studentNames[i] = strdup(name);
    }

    sortNames(studentNames, n);
    printf("Names in alphabetical ascending order:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%s\n", studentNames[i]);
        free(studentNames[i]);
    }
    return 0;
}