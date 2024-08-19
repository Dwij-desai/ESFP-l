#include <stdio.h>

int main()
{
        int in1,i,in2;
        int j=0; 
        int a,n,first,last;
        
        printf("\bEnter the number of inputs:\n");
        scanf("%d",&in1);

       
        
        for(i=0;i<in1;i++)
        {
          //  j=0;
             printf("\bEnter the %d time inputs:-\n",i+1);
            scanf("%d",&in2);
            
            last=in2%10;
            
            while(in2>10)
            {
                in2=in2/10;
                first=in2;
            }
            
            printf("\t %d \n",first);
            printf("\t %d \n",last);
            
            
        }
        printf("\n\bEnding code...");

        return 0;
}
