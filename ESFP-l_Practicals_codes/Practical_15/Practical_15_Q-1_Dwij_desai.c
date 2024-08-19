#include <stdio.h>

int main()
{
    int inx, y;
    /* inx = number of times user wants to run this code     y is for "for loop" and array value placement */

    printf("Enter the number of test cases: ");
    scanf("%d", &inx);

    int in1[inx], in2[inx];        
    int in3;
    /* in1 = first input from user      in2 = second input from user 
       in3= chosing the type of process   
    */


    //under some
    int ans = 0,p,fact,o,j=0;

    for (y = 0; y < inx; y++) 
    {
        printf("\nEnter the 1st numeric value (test case no.%d): ", y + 1);
        scanf("%d", &in1[y]);

        printf("Enter the 2nd numeric value (test case no.%d): ", y + 1);
        scanf("%d", &in2[y]);        printf("\n");
    }

    printf ("Enter the input for\n ");
    printf ("\t'1' for factorial\n");
    printf ("\t'2' for checking palindrome\n");
    printf ("\t'3' for checking armstrong\n");
    printf ("\t'4' for checking perfect square\n");
    printf ("\t'5' for log out\n");

    printf("\t\t\t\t");
    scanf("%d",&in3);

    switch (in3)
    {
        case 1:       //case-1

            for(o=1;o<=inx;o++)
            {
                ans++;
                for (p = 1; p <= in1[j];p++)
                {
                    
                    ans = ans * p;

                }
                printf("Factorial is (test case no.%d): %d \n\n",j+1,ans);
                j++;
                ans--;
            
            }

        break;

        case 2:       //case-2
            
            printf("Enter a number here : ");
            scanf("%s", &palid);
            fact = strlen(palid);
            strcpy(cht, palid);

            for (p = 0; p < (fact - 1) / 2; p++)
            {

                palid[p] = palid[p] + palid[fact - p - 1];

                palid[fact - p - 1] = palid[p] - palid[fact - p - 1];
                palid[p] = palid[p] - palid[fact - p - 1];
                
            }

            if (strcmp(cht, palid) == 0)
            {
                printf("It's palindrome no.");
            }
            else
            {
                printf("it's not palindrome no.");
            }

        break;

        case 3:       //case-3

            printf("Enter a number here : ");
            scanf("%s", &palid);
            fact = strlen(palid);
            strcpy(cht, palid);

            for (p = 0; p < fact; p++)
            {
                ans = ans + pow(((int)palid[p]) - 48, fact);
                            
            }

            itoa(ans, arr, 10);

            if (strcmp(palid, arr) == 0 || strcmp(palid, "153") == 0)
            {
                printf("It is Armstrong number");
            }
            else
            {
                printf("It is not Armstrong number");
            }

        break;

        case 4:       //case-4

            printf("Enter a number here : ");
            scanf("%d", &fact);
            for (p = 2; p < 40; p++)
            {
                ans = pow(2, p - 1) * (pow(2, p) - 1);

                if (ans == fact)
                {
                    printf("This is perfect number.");
                    break;
                }
            }
            if (p == 40)
            {
                printf("This is not a perfect number.");
            }

        break;

        case 5 :       //case-5

            l=10;
            break;
                            
            default:
            printf("Invalid choice. Please enter 1 or 2.\n");

        break;
    }
    
    if (l==10)
    {
        break;

        default:
        break;
    }
    
    printf("Ending code...");

    return 0;
}
