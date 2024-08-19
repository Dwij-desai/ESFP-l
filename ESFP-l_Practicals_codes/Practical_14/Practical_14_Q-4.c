#include <stdio.h>
int main() 
{
    int matrix[4][4];
    int sum_diagonal1 = 0;
    int sum_diagonal2 = 0;

    printf("Input 4x4 Matrix :\n");
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < 4; i++) 
    {
        sum_diagonal1 += matrix[i][i];
        sum_diagonal2 += matrix[i][3 - i];
    }

    printf("\nBoth diagonal array element addition is=%d\n", sum_diagonal1 + sum_diagonal2);
    return 0;
}