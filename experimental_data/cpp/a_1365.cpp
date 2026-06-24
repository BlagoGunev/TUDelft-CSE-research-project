#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf=0x3f3f3f3f;
const ll mint=0x7fffffff;
const ll linf=1000000000000000000LL;
const ll mod=998244353LL;
const double eps=1e-3;

const int N=100020;

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[100][100];

int main(void)
{
    //ios::sync_with_stdio(false);
    
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    
    for(int _=read();_>0;_--)
    {
        int n=read(),m=read();
        int tn=n,tm=m;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]=read();
            }
        }
        for(int i=0;i<n;i++)
        {
            int aa=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1) aa=1;
            }
            tn-=aa;
        }
        for(int i=0;i<m;i++)
        {
            int aa=0;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]==1) aa=1;
            }
            tm-=aa;
        }

        if(min(tn,tm)%2==1) printf("Ashish\n");
        else printf("Vivek\n");
    }
    
    return 0;
}