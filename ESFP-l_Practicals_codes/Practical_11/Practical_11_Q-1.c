
//   1.
#include <stdio.h>
int main()
{
    int i, j;

    for (i = 1; i <= 5; i++)
    {

        for (j = i; j <= 5; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}

//   2.

#include <stdio.h>
int main()
{
    int i, j;

    for (i = 5; i >= 1; i--)
    {

        for (j = 1;j <= i; j++)
        {
            printf("%d", j);
        }

        printf("\n");
    }
    return 0;
}



//   3.
#include <stdio.h>
int main()
{
    int i, j;

    for (i = 1; i <= 5; ++i)
    {

        for (j = 1; j <= i; ++j)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}



//  4.
#include <stdio.h>
int main()
{
    int i, j;

    for (i = 1; i <= 5; i++)
    {

        for (j = 1; j <= i; j++)
        {
            printf("%d",j);
        }

        printf("\n");
    }
    return 0;
}

//   5.
#include <stdio.h>
int main() 
{

    for (int i = 1; i <= 5; i++) 
    {
        for (int j = (5-i); j > 0; j--) 
        {
            printf(" ");
        }

        for (int k = 1; k <= i; k++)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}

//    6.
#include <stdio.h>
int main() 
{

    for (int i = 1; i <= 5; i++) 
    {
        for (int j = (5-i); j > 0; j--) 
        {
            printf(" ");
        }

        for (int k = 1; k <= i; k++)
        {
            printf("%d",k);
        }

        printf("\n");
    }

    return 0;
}

//   7.
#include <stdio.h>
int main() 
{
    int rows = 5;
    int space, star;

    for (int i = 1; i <= rows; i++) 
    {

        for (space = 1; space <= rows - i; space++) 
        {
            printf(" ");
        }

        for (star = 1; star <= 2 * i - 1; star++) 
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

//    8.
#include <stdio.h>
int main() 
{
    int rows = 5;
    int space, star;

    for (int i = 1; i <= rows; i++) 
    {

        for (space = 1; space <= rows - i; space++) 
        {
            printf(" ");
        }

        for (star = 1; star <= 2 * i - 1; star++) 
        {
            printf("%d",star);
        }

        printf("\n");
    }

    return 0;
}

//   9.
#include <stdio.h>
int main() 
{
    int rows = 5;
    int space, star;

    for (int i = rows; i >= 1; i--) 
    {
        for (space = 1; space <= rows - i; space++) 
        {
            printf(" ");
        }
        for (star = 1; star <= 2 * i - 1; star++) 
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

//   10.
#include <stdio.h>
int main() 
{
    char current_char = 'A';

    for (int i = 1; i <= 5; i++) 
    {

        for (int j = 0; j < i; j++) 
        {
            printf("%c ", current_char++);
        }

        printf("\n");
    }
    return 0;
}

//   11.
#include<stdio.h>
int main() 
{
    char current_char = 'A';

    for (int i = 1; i <= 5; i++) 
    {

        for (int j = 0; j < i; j++) 
        {
            printf("%c", current_char);
        }

        printf("\n");

        current_char++;

    }

    return 0;
}

//    12.
#include <stdio.h>
int main() 
{
    char current_char = 'E';

    for (int i = 1; i <= 5; i++) 
    {

        for (int j = 0; j < i; j++) 
        {
            printf("%c", current_char);
        }

        printf("\n");
        current_char--;

    }

    return 0;
}
