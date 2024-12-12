#include <stdio.h>

#include <math.h>

int main()
{
   int x=1;
   int sign =1;
   double PI =4.0f;
   
   for(int x=3;;x+=2)
       {sign*=-1;
       PI+=sign*(4.0/x);
       if(fabs(PI-3.14159)<=0.00005)
       {printf("PI %.5f\n", PI);
       {printf("x= %d",x-2);
       break;}
       }
       }
       
       
       return 0;
}
