#include <stdio.h>

int main() 
{
    int numbers[10];
    int evenCount = 0;
    int oddCount = 0;

    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++) 
    {
        
        scanf("%d", &numbers[i]);
        if (numbers[i] % 2 == 0) 
        {
            evenCount++;
        } 
        else 
        {
            oddCount++;
        }

    }

    printf("Count of even numbers: %d\n", evenCount);
    printf("Count of odd numbers: %d\n", oddCount);

    return 0;
}