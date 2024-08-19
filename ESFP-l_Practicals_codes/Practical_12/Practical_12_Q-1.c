#include <stdio.h>

int main() 
{
    int numbers[10];
    int sum = 0;

    printf("Enter 10 numbers: ");

    for (int i = 0; i < 10; i++) 
    {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    float average = (float)sum / 10;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
        
    return 0;
}