#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<ctime>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const double inf=0x3fffffff;
const double eps=1e-9;
int a[100005];
//bool fg[100005];
int main()
{
    int n,m,k,i,j;
    int ans=inf,ans2;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    int tmp;
    for(i=k;i>0;--i)
    {
        tmp=0;
        for(j=i;j<=n;j+=k)
        {
            tmp+=a[j];
        }
        if(tmp<=ans)
        {
            ans=tmp;
            ans2=i;
        }
    }
    printf("%d\n",ans2);
    return 0;
}