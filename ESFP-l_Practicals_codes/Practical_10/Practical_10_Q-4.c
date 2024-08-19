#include<stdio.h>
int main()
{
 int water,pulp,req_water,req_pulp,coconutA,coconutB,total_coconut,cases;

 int y;

 printf("\nEnter the number of testcases :- ");
 scanf("%d",&cases);

 for(y=1;y<=cases;y++)
    {
        printf("\nTestcase number - %d",y);

        printf("\nEnter the amount of coconut water in a coconut of Type A :- ");
        scanf("%d",&water);

        printf("\nEnter the amount of coconut pulp in a coconut of Type B :- ");
        scanf("%d",&pulp);

        printf("\nEnter the amount of coconut water, nutritionist advised to consume in a week :- ");
        scanf("%d",&req_water);
        
        printf("\nEnter the amount of coconut pulp, nutritionist advised to consume in a week :- ");
        scanf("%d",&req_pulp);

        coconutA = req_water / water ;
        coconutB = req_pulp / pulp ;
        total_coconut = coconutA + coconutB;

        printf("\nSo, number of type A coconuts needed to in a week are = %d\n",coconutA);
        printf("\nSo, number of type B coconuts needed to in a week are = %d\n",coconutB);
        printf("\n\nSo, number of coconuts needed to in a week are = %d\n",total_coconut);
    }
 return 0;
} 

