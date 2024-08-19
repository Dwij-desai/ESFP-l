#include <stdio.h>
int determineWinner(int SP, int SQ, int SR) 
{
    if (SP < SQ && SP < SR) 
    {
        return 0;
    } 
    else if (SQ < SP && SQ < SR) 
    {
        return 1;
    } 
    else 
    {
        return 2;
    }
}

int main() 
{
    int T;

    scanf("%d", &T);

    while (T--) 
    {
        int SP, SQ, SR;
        
        scanf("%d %d %d", &SP, &SQ, &SR);
        
        int winnerCode = determineWinner(SP, SQ, SR);

        if (winnerCode == 0) 
        {
            printf("Draw\n");
        } 
        else if (winnerCode == 1) 
        {
            printf("Bob\n");
        } 
        else 
        {
            printf("Alice\n");
        }
    }
    return 0;
}