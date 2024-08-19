#include<stdio.h>
#define MAX_SIZE 100
int main()
{
    int arr[MAX_SIZE];
    int size;
    int i, j, temp;

    printf("Enter the size : ");
    scanf("%d",&size);
    printf("Enter elemenys: ");

    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<size; i++)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size - i - 1; j++)
            {
                if (arr[j] < arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

        printf("descending order: ");
        for (i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }

    return 0;
}