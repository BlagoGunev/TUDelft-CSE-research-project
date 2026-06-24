#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
/*int a[maxn];
ll pre[maxn];

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        double ans=0;
        pre[0]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        for(int i=1;i<=n-k+1;i++) ans+=(pre[i+k-1]-pre[i-1]);
        printf("%.6f\n",ans/(n-k+1));
    }
    return 0;
}

pair<int,int> a[maxn],b[maxn];

int main()
{
    int n,w;
    while(~scanf("%d%d",&n,&w))
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i].first),a[i].second=i;
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
        {
            b[i].first=(a[i].first+1)/2;
            b[i].second=a[i].second;
        }
        for(int i=1;i<n;i++)
        {
            if(a[i+1].first!=a[i].first&&b[i+1].first<b[i].first) b[i+1].first++;
        }
        for(int i=1;i<=n;i++) w-=b[i].first;
        if(w>=0)
        {
            for(int i=n;i>0&&w;i--)
            {
                if(w>=a[i].first-b[i].first) w-=a[i].first-b[i].first,b[i]=a[i];
                else
                {
                    b[i].first+=w;
                    w=0;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(b[j].second==i)
                    {
                        printf("%d ",b[j].first);
                        break;
                    }
                }
            }
            printf("\n");
        }
        else puts("-1");
    }
    return 0;
}
ll a[maxn],pre[maxn],suf[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        pre[0]=0;
        for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),pre[i]=pre[i-1]+a[i];
        suf[n+1]=0;
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
        bool flag=0;
        int pos=-1;
        for(int i=1;i<n;i++)
        {
            ll tmp=suf[i+1]-pre[i];
            if(tmp==0) flag=true;
            if(tmp%2) continue;
            tmp/=2;
            if(tmp<0)
            {
                pos=lower_bound(a+1,a+i+1,-tmp)-a;
                if(a[pos]==-tmp) flag=true;
            }
            else
            {
                pos=lower_bound(a+i+2,a+n+1,tmp)-a;
                if(a[pos]==tmp) flag=true;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}*/
int a[36];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int pos=0,m=n;
        while(n)
        {
            a[++pos]=n%10;
            n/=10;
        }
        a[pos]++;
        int ret=1;
        for(int i=1;i<pos;i++) ret*=10;
        printf("%d\n",a[pos]*ret-m);
    }
    return 0;
}