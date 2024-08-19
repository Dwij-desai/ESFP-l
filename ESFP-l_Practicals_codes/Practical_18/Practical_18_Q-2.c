#include <stdio.h>
int main() 
{
    FILE *file1 = fopen("C:\\ICT\\SEM-1\\ESFP\\code\\Practical-18\\file1.txt","r");

    if (file1 == NULL) 
    {
        printf("Error opening file1.txt for reading.\n");
        return 1;
    }

    FILE *file2 = fopen("file2.txt", "w");
    FILE *file3 = fopen("file3.txt", "w");

    if (file2 == NULL || file3 == NULL) 
    {
        printf("Error opening file2.txt or file3.txt for writing.\n");
        return 1;
    }

    int num;
    while (fscanf(file1, "%d", &num) == 1) 
    {
        if (num % 2 == 0) 
        {
            fprintf(file3, "%d ", num);
        } 
        else 
        {
            fprintf(file2, "%d ", num);
        }
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
    file2 = fopen("file2.txt", "r");
    file3 = fopen("file3.txt", "r");

    if (file2 == NULL || file3 == NULL) 
    {
        printf("Error opening file2.txt or file3.txt for reading.\n");
        return 1;
    }

    printf("Contents of ODD number in file2: ");
    while (fscanf(file2, "%d", &num) == 1) 
    {
        printf("%d ", num);
    }

    printf("\n");
    printf("Contents of EVEN number in file3: ");
    while (fscanf(file3, "%d", &num) == 1) 
    {
        printf("%d ", num);
    }
    printf("\n");

    fclose(file2);
    fclose(file3);

    return 0;
}