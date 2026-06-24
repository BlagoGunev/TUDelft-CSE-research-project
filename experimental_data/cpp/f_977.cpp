#include<bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
#define clr_1(x) memset(x,-1,sizeof(x))
#define clrmax(x) memset(x,0x3f3f3f3f,sizeof(x))
#define mod 1000000007
#define INF 0x3f3f3f3f
#define LL long long
#define pb push_back
#define pbk pop_back
#define ls(i) (i<<1)
#define rs(i) (i<<1|1)
using namespace std;
const int N=2e5+10;
int a[N],uni[N],n,m,now[N],pre[N],last,maxn,t,p,ans[N],num[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        uni[i]=a[i];
    }
    sort(uni+1,uni+n+1);
    m=unique(uni+1,uni+n+1)-uni-1;
    last=maxn=1;
    for(int i=1;i<=n;i++)
    {
        t=lower_bound(uni+1,uni+m+1,a[i])-uni;
        if(num[t]<1)
        {
            now[t]=i;
            num[t]=1;
        }
        p=lower_bound(uni+1,uni+m+1,a[i]-1)-uni;
        if(p>m || uni[p]!=a[i]-1)
            continue;
        if(num[t]<num[p]+1)
        {
            now[t]=i;
            num[t]=num[p]+1;
            pre[i]=now[p];
        }
        if(num[t]>maxn)
        {
            last=i;
            maxn=num[t];
        }
    }
    printf("%d\n",maxn);
    for(int i=maxn;i>=1;i--)
    {
        ans[i]=last;
        last=pre[last];
    }
    for(int i=1;i<=maxn;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}