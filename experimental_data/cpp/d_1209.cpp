#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define fd(i, l, r) for (int i = r; i >= l; i--)
#define ll long long
using namespace std;
const int maxn = 100050;
const ll mod = 1e9 + 7;
ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (!(ch >= '0' && ch <= '9'))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    };
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    };
    return x * f;
}
int n,k;
int f[maxn];
int findf(int x){
    return f[x]==x?x:f[x]=findf(f[x]);
}
int main()
{
    n=read();k=read();
    fo(i,1,n)f[i]=i;
    int ans = 0;
    int u,v;
    fo(i,1,k){
        u=read();v=read();
        u = findf(u);v=findf(v);
        if(u==v)ans++;
        else f[u] = v;
    }
    printf("%d",ans);
    return 0;
}