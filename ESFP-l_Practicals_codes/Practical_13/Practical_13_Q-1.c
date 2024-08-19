#include <stdio.h>

int main() 
{
    int size, match;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arrey[size];
    printf("Enter %d array elements separated by spaces: ", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arrey[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &match);
    for (int i = 0; i < size; i++) 
    {
        if (arrey[i] == match) 
        {
            printf("Value found in array list.\n");
            break;
        }
        else
        {
            printf("Value not found in array list.\n");
        }
    }
    return 0;
}