#include <stdio.h>

int main()
{
    int in1,in2,in3;
    //in1=testcases    in2=trip length   in3=time length of music

    printf("\nfEnter the number of testcase:-\t");
    scanf("%d",&in1);

    int y,x;
    //y=for loop integer   x=equation(to find number for music replay)

    for(y=1;y<=in1;y++)
    {

        printf("Enter the trip length:-\t");
        scanf("%d",&in2);

        printf("Enter the music length(in min):-\t");
        scanf("%d",&in3);

        x=in2/in3;

        printf("Here is the number of times you can play full song = %d\n",x);

    }

    return 0;
}