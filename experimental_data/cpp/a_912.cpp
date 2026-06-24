#include<stdio.h>
int main()
{
 long long int a,b,x,y,z,s=0,a1,b1,a2,b2;
 scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&z);
 a1=2*x+y;
 b1=y+3*z;
 a2=a1-a;
 b2=b1-b;
 if(a2>0)
  s+=a2;
 if(b2>0)
  s+=b2; 
 printf("%lld",s);
 return 0;
}