#include <stdio.h>

int main() 
{
    int marks[50];
    int frequency[11] = {0};

    printf("Enter the marks of 50 students:\n");
    for (int i = 0; i < 50; i++) 
    {
        scanf("%d", &marks[i]);

        int group = marks[i] / 10;

        if (group >= 0 && group <= 10) 
        {
            frequency[group]++;
        }

    }

    printf("Group range frequency:\n");

    for (int i = 0; i <= 10; i++) 
    {
        printf("%d %d to %d %d\n", i + 1, i * 10, i * 10 + 9, frequency[i]);
    }
    return 0;
}