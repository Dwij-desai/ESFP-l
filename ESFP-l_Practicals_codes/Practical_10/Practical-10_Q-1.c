

#include <stdio.h>

int main()
{
        int in1,i,in2;
        int j=0,a=0;
        
        printf("Enter the number of inputs:\n");
        scanf("%d",&in1);
        
        for(i=0;i<in1;i++)
        {
                j=0;
                printf("Enter the %d time inputs:-\n",i+1);
                scanf("%d",&in2);

                for(;;)
                {
                        a=in2%10;//This is to get ever decimal one-by-one of number 'in2' writen.

                        in2=(in2-a)/10; //This is the detacter for when to brack.

                        j=j+a;//This is to add all decimals one-by-one (Total of entire digit).

                        if(in2 == 0)//To end the fuction to end the program when we reach '0.' digits.
                        {
                                break;
                        }

                }

                printf("\tsum=%d \n\n",j);

        }

        return 0;
}