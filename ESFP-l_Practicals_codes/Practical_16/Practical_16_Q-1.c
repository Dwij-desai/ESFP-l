#include <stdio.h>
int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int *pa = &a;
    int *pb = &b;
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    
    printf("Swapped values: %d %d\n", a, b);
    return 0;
}