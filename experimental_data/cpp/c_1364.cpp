#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf=1000000;
const ll mint=0x7fffffff;
const ll linf=1000000000000000000LL;
const ll mod=998244353LL;
const double eps=1e-3;

const int N=1000000;

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main(void)
{
    //ios::sync_with_stdio(false);
    
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    
    int n=read();
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) a[i]=read();
    queue<int> q;
    int mx=0,pos=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=mx) b[i]=inf;
        else
        {
            b[i]=mx;
            mx++;
            for(;pos<i;pos++)
            {
                if(mx==a[i]) break;
                if(b[pos]==inf) 
                {
                    b[pos]=mx;
                    mx++;
                }
            }

            if(mx<a[i])
            {
                printf("-1");
                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    
    return 0;
}