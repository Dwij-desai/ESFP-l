#include <stdio.h>

int main() 
{
    int T;
    scanf("%d", &T);
    while (T--) 
    {
        int joker[5];
        for (int i = 0; i < 5; i++)
        {
            scanf("%d", &joker[i]);
        }

        int order;
        scanf("%d", &order);
        if (order == 1) 
        {
            for (int i = 0; i < 4; i++) 
            {
                for (int j = 0; j < 4 - i; j++) 
                {
                    if (joker[j] > joker[j + 1]) 
                    {
                        int temp = joker[j];

                        joker[j] = joker[j + 1];
                        joker[j + 1] = temp;

                    }
                }
            }
        }

        else if (order == 2) 
        {
            for (int i = 0; i < 4; i++) 
            {
                for (int j = 0; j < 4 - i; j++) 
                {
                    if (joker[j] < joker[j + 1]) 
                    {
                        int temp = joker[j];
                        joker[j] = joker[j + 1];
                        joker[j + 1] = temp;
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++) 
        {
            printf("%d ", joker[i]);
        }

        printf("\n");
    }
    return 0;
}