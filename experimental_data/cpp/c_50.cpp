#include <iostream>
#include <math.h>
using namespace std;
struct node
{
    int a,b;
};
node leftdown,rightup;
node sum[4],sum1[4];
void work(int a,int b,int n)
{
    int i;
    if(n==0) 
    {
        for(i=0;i<4;i++)
        {
            sum[i].a=a;
            sum[i].b=b;
        }
        leftdown.a=a;
        rightup.a=a;
        leftdown.b=b;
        rightup.b=b;
        return ;
    }
    if(a<leftdown.a) leftdown.a=a;
    if(a>rightup.a) rightup.a=a;
    if(b<leftdown.b) leftdown.b=b;
    if(b>rightup.b) rightup.b=b;
    if((sum[0].b-sum[0].a)<(b-a))
    {
        sum[0].b=b;
        sum[0].a=a;
    }
    if((sum[1].b+sum[1].a)<(b+a))
    {
        sum[1].b=b;
        sum[1].a=a;
    }
    if((sum[2].b-sum[2].a)>(b-a))
    {
        sum[2].b=b;
        sum[2].a=a;
    }
    if((sum[3].b+sum[3].a)>(b+a))
    {
        sum[3].b=b;
        sum[3].a=a;
    }
}
int main()
{
    int n;
    int a,b,i,ans;
    int mysum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            work(a,b,i);
        }
        leftdown.a--;
        leftdown.b--;
        rightup.a++;
        rightup.b++;
        sum1[0].a=leftdown.a;
        sum1[0].b=rightup.b;

        sum1[1].a=rightup.a;
        sum1[1].b=rightup.b;

        sum1[2].a=rightup.a;
        sum1[2].b=leftdown.b;

        sum1[3].a=leftdown.a;
        sum1[3].b=leftdown.b;

        mysum=2*(rightup.a-leftdown.a)+2*(rightup.b-leftdown.b);

        ans=0;
        for(i=0;i<4;i++)
        {
            ans=ans+abs(sum[i].a-sum1[i].a)+abs(sum[i].b-sum1[i].b)-1;
        }
        printf("%d\n",mysum-ans);
    }
}