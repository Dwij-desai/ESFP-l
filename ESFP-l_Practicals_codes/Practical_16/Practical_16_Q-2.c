#include <stdio.h>
int main()
{
    int N = 10;
    int k = 5;
    int candies = N;
    int *ptrCandies = &candies;

    while (1)
    {
        int order;

        printf("Enter the number of candies to order (0 to exit): ");
        scanf("%d", &order);

        if (order < 0 || order > *ptrCandies)
        {
            printf("INVALID INPUT\n");
            printf("NUMBER OF CANDIES LEFT: %d\n", *ptrCandies);
            break;
        }

        printf("NUMBER OF CANDIES SOLD: %d\n", order);

        *ptrCandies -= order;

        if (*ptrCandies < k)
        {
            *ptrCandies = N;
            printf("JAR REFILLED\n");
        }
    
        printf("NUMBER OF CANDIES AVAILABLE: %d\n", *ptrCandies);
        if (*ptrCandies == 0)
        {
            printf("JAR IS EMPTY\n");
            break;
        }
    }
    return 0;
}