#include<cstdio>
#include<cmath>
#include<string.h>
#include<string>

long a;

int main()
{
 long n,i,j,cnt,mn,ind,tmp;
 
   while(scanf("%ld",&n)!=EOF) 
   {
     mn=1<<28; ind=0;
     scanf("%ld",&tmp);
     for(i=1;i<n;i++)
      {
        scanf("%ld",&a); if(tmp>a) ind=i; tmp=a;                
      }
  //  if(ind>0) ind--;
    printf("%ld\n",ind);                             
                               
   } 
    
    
return 0;    
}