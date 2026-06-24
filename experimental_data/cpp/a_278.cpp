#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
    int n,x,y,dp[1001];
int main()
{
    int sum=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
       scanf("%d",&x);  
       dp[i+1]=dp[i]+x;
       sum+=x;
    }    
    scanf("%d%d",&x,&y);
    if(x<y);
    else
    {
       int tmp=x; x=y; y=tmp;
    }
    int tp1=dp[y]-dp[x];
    int tp2=sum-tp1;
    printf("%d\n",min(tp1,tp2));
    return 0;   
}