#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pa pair<int,int>
#define ll long long
#define inf 1000000000
#define mod 1000000007
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[300005];
ll ans, b, w;
int main()
{
    int n = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
        if(i & 1)
        {
            b += a[i] / 2;
            w += a[i] - a[i] / 2;
        }
        else
        {
            w += a[i] / 2;
            b += a[i] - a[i] / 2;
        }
    }
    cout << min(b, w) << endl;
    return 0;
}