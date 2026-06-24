#include<stdio.h>
int main()
{
    bool flag;
    long i,n,m;
    while(~scanf("%ld %ld",&n,&m))
    {
      flag=1;
      while(flag)
      {
         for(i=1;i<=n;i++)
         {
            if(i<=m)
             m-=i;
            else
             {flag=0;break;}
         }
      }
      printf("%ld\n",m);
    }
    return 0;
}