#include <stdio.h>

int main()
{
    
    int OK; int St=100;     int Si;
    //Si=number of stock demanded by user        //St=total number of stock 
    
    printf("Enter the amount of Stock demanded:\t");
    scanf("%d",&Si);

    printf("\nNow,Enter '1' if credit is OK and '0' if credit is not OK:\t");
    scanf("%d",&OK);

    switch(OK)
    {

        case 0:
            printf("\vAs your credit is not OK,The stock can not be supplyed.");
        break;

        case 1:
            if(Si<St)
                {
                    printf("\vYour %d quantities of computer will be sumpplyed.",Si);
                }
            else
                {
                    int d=Si-St;
                    printf("\vSorry,the stock is less than your ordered quantity.\n");
                    printf("Right now we have 100 quantities of computer available so\n"); 
                    printf("we will supply the remaining %d quantities of computer when we restock.\v",d);
                }    
        break;

        default:
        return 0;
        break;

    }

   return 0;
}