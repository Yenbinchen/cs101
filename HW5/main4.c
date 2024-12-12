#include <stdio.h>
#include <stdlib.h>

int main()
{int i= 12345,h,k;
if(i<1000)
{h=i%10;
 i=h*1000+i-h;
 printf("%d",i);}
 
 else{h=i%10;
 k=i/1000;
 if(k>10){
     k%=10;}
     i=i+(999*abs(h-k));
     printf("%d",i);
 
 }
       
       return 0;
}
