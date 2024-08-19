#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 
char tolower1(char a) 
{ 
    int i; 
    char Alfa[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    char alfa[] = "abcdefghijklmnopqrstuvwxyz";
    
    for (i = 0; i < 26; i++) 
    { 
        if (a == Alfa[i]) 
        { 
            a = alfa[i]; 
            break; 
        } 
    } 
    return a; 
} 
int vovelcheck(char a) 
{ 
    char vo[5] = "aeiou"; 
 
    for (int i = 0; i < 5; i++) 
    { 
        if (vo[i] == a) 
        { 
            return 1; 
        } 
    } 
    return 0; 
} 
void main() 
{ 
    char in[1000][100]; 
    char out[1000][100]; 
    char com = '0'; 
    int d = 1, t, temp = 0; 
    int ot = 0; 
    char T = 'T'; 
    char space = ' '; 
    char alfa[] = "abcdefghijklmnopqrstuvwxyz"; 
    int loop = 1; 
 
    for (int i = 0; i < t; i++) 
    { 
        gets(in[d]); 
 
        t = in[d][0] == com ? i : i + 5; 
        d++; 
    } 
    for (int i = 0; i < d - 1; i++) 
    { 
        for (int j = 0; j < strlen(in[i]); j++) 
        { 
            in[i][j] = tolower1(in[i][j]); 
        }
    } 
    for (int i = 0; i < d - 1; i++) 
 
    { 
 
        for (int j = 0; j < strlen(in[i]); j++) 
        { 
 
            if (j == 0) 
            { 
 
                strncat(out[i], &T, 1); 
 
                if (vovelcheck(in[i][j]) == 0) 
                { 
                    j += 1; 
                } 
                strncat(out[i], &in[i][j], 1); 
 
                // j+= temp == 4?2:0; 
            } 
            else if (in[i][j] == ' ') 
            { 
                strncat(out[i], &space, 1); 
 
                strncat(out[i], &T, 1); 
 
                if (vovelcheck(in[i][j + 1]) == 0) 
                { 
                    j += 2; 
                } 
                else 
                { 
                    j++; 
                } 
 
                strncat(out[i], &in[i][j], 1); 
                // j+= temp == 4?2:0; 
            } 
 
            else 
            { 
                strncat(out[i], &in[i][j + ot], 1); 
            } 
        } 
    } 
    for (int i = 0; i < d; i++) 
    {
         printf("%s", out[i]); 
        printf("\n"); 
    } 
}
