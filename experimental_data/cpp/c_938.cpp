#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 35000
int t,x,n,m;
int main()
{
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&x);
  if(x==0)printf("1 1\n");
  else if(x==1)printf("-1\n");
  else
  {
   bool flag=0;
             for(int i=1;i*i<=x;i++)
   {  
    if((x%i==0)&&((i&1)==((x/i)&1)))
    {
     n=(i+x/i)/2;
                    int tmp=n-i;
                    if(tmp==0)continue;
                    m=n/tmp;
                    if(n>=m&&tmp==(n/m))
     {
                        printf("%d %d\n",n,m);
                        flag=1;
                        break;
                    }  
                }  
            }
   if(!flag)
    printf("-1\n");
  }
 }
}