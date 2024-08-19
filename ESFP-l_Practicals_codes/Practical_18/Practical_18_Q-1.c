#include <stdio.h>
#include <stdlib.h>
int main() 
{
    FILE *file;
    char ch;
    file = fopen("C:/ICT/SEM-1/ESFP/code/Practical-18/student.txt", "r");
    if (file == NULL) 
    {
        printf("File not found or unable to open the file.\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) 
    {
        putchar(ch);
    }
    fclose(file);
    return 0;
}