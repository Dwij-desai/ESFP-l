#include <stdio.h>

int main() 
{
    printf("Multiplication Table\n");
    int n = 5;
    int table[5][5];

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    printf(" ");
    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", i);
    }

    printf("\n-----------------\n");
    for (int i = 1; i <= n; i++) 
    {

        printf("%d| ", i);
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", table[i - 1][j]);
        }
        printf("\n");

    }
    
    return 0;
}