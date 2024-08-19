#include <stdio.h>
int main() 
{
    int matrix[4][4];
    int transpose[4][4];

    printf("Input 4x4 Matrix \n");
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("\nTransposed Array:\n");
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            printf("%d ", transpose[i][j]);
        }

        printf("\n");
    }
    
    return 0;
}