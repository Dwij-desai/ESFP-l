#include <stdio.h>

int main()
{
    const int hardness = 50, tensile_strength = 5600;  const float carbon = 0.7;
    //        (i)              (iii)                                (ii)
    int h, t;                    float c;
    //h=hardness t=tensile      //c=carbon
    printf("Enter the hardness and the tensile strength of the steel:\t");
    scanf("%d%d", &h, &t);

    printf("Enter the carbon content in that steel:\t");
    scanf("%f", &c);

    if (h>hardness || t>tensile_strength || c<carbon)
    {

        if (h>hardness && c<carbon)
        {
           printf("The grade of the steel is 9."); 
        }

        else if (c<carbon && t>tensile_strength)
        {
           printf("The grade of the steel is 8."); 
        }

        else if (h>hardness && t>tensile_strength)
        {
           printf("The grade of the steel is 7."); 
        }

        else
        {
            printf("The grade of the steel is 6.");
        }

    }

    else if(h>hardness && t>tensile_strength && c<carbon)
    {
        printf("The grade of the steel is 10.");
    }

    else
    {
        printf("The grade of the steel is 5.");
    }    

    return 0;
}