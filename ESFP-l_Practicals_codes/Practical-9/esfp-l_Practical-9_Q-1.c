//Topic:-question-1


//sub-topic:- No.1

#include<stdio.h> 
int main() 
{ 
   int  i=1; 
   while (i<=10) //We don't need to terminate while loop.
   { 
      printf ("\n %d",i);

      i=++i; //and we need to give an increment. 
   } 
   //here return 0; is not mentioned.
   return 0;
}


/////////////////////////////////////////////////////////////////////////

//sub-topic:- No.2

#include<stdio.h>
int main()
{
   int x=4;

   while (x<=4 && x>=-10) //the condition was not right here.
   {
      x=x-1;
      printf ("\n %d", x);
      --x;
   }
   //here return 0; is not mentioned.
   return 0;
}

/////////////////////////////////////////////////////////////////////////



//sub-topic:- No.3

#include<stdio.h>

int main()
{
   int x=4, y, z;

   y=-x;
   z=x--;//space is not needed between '-' in decrement.

   printf ("\t%d\t%d\t%d", x,y,z);

   return 0;
}



//sub-topic:- No.4

#include<stdio.h>
int main()
{
   int x=4,y=3,z;

   z=x-(--y);//if we need subtraction after decrement of y, then use brackets.

   printf ("\t%d\t%d\t%d", x,y,z);

   return 0;
}



//sub-topic:- No.5

#include<stdio.h>

int main()
{

   char a; char b;

   while ('a'<'b')
   {
      printf("\n Malayalam is palindrome");
   }

   return 0;
}




//sub-topic:- No.6

#include<stdio.h>

   int main()
   {
      int i=0;

      while (i<=10)
      {

         printf("\n %d", i);

         i=i+1;
      }

      return 0;
   }



//sub-topic:- No.7

#include<stdio.h>
   int main()
   {
      float a=1.1;

      while (a>=1.1)
      {
         printf ("\n %f", a);

         a=a-0.1;
      }

      return 0;
   }



//sub-topic:- No.8

#include<stdio.h>
   int main()
   {
      int x=4,y=0;

      while (x>=0)
      {

         if (x==y)
         {
            continue;
         }
         else
         {
            printf ("\n%d\t%d",x,y);
         }

         x--;
         y++;
      }

      return 0;
   }



//sub-topic:- No.9

#include<stdio.h> 

int main() 
{ 
   int  x=4,y=0,z; 
   while (x>=0) 
   { 
      if (x==y) 
      {
         break;
      }

      else 
      {
         printf ("\n %d\t%d",x,y); 
      }

      x--; 
      y++; 
   }

   return 0; 
}
 



//sub-topic:- No.10

#include<stdio.h> 
int main() 
{ 
   int i; 
   for (i=0;i<=10;i++) 
   { 
      printf ("\nHello");   
   } 
   return 0; 
}
 



//sub-topic:- No.11

#include<stdio.h> 
int main() 
{ 
   int i; 

   for (i=1;i<=5;i++);

   printf ("\n %d",i);

  return 0; 
} 

/////////////////////////////////////////////////////////////////////////

//sub-topic:- No.12

#include<stdio.h> 
int main() 
{ 
   int i=1,j=1; 
   for (;;) 
   { 
      if (i>5)
      { 
         break; 
      }

      else 
      {
         j+=1; 
         printf ("\n %d", j); 
      }
      i+=j; 
   }
   return 0; 
} 

////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////

//sub-topic:- No.13

#include <stdio.h>
int main() 
{ 
   int true=0,false; 

   while (true) 
   { 
      false=1;

      printf("\n%d",false);
   }
   return 0; 
}

////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////

//sub-topic:- No.14
#include <stdio.h>
int main() 
{ 
   int a=32; 
    
   do 
   { 
      printf("%d",a); 
      a++;

   }while(a<=30);
      
   return 0; 
}

/////////////////////////////////////////////////////////////////////////

//sub-topic:- No.15

#include <stdio.h>
int main() 
{ 
   int a=10; 
     
   do 
   {
      printf("%d ", a); 
      a++; 

      if(a > 15)
      { 
      break; 
      }

   }while(1); 
   return 0; 
}



//sub-topic:- No.16

#include <stdio.h> 
   int  main() 
   { 
      int i=0; 

      for (;i<10;i++); 
      printf("\thi"); 

      return 0; 

   }



//sub-topic:- No.17

# include <stdio.h> 
   void main() 
   { 
      int k=0; 
      for (;k<3; k++) 
      {
         printf("\tHello"); 
      }

   } 



//sub-topic:- No.18

#include<stdio.h> 
int main() 
{ 
   int i,j; 

   for(i=1;i<=5;i++)    
   { 
   
      for(j=1;j<=i;j++)  
      { 
         printf("$"); 
      } 
   
      printf("\n"); 
   }
   return 0; 
}
