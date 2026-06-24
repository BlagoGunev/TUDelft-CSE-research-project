#include <bits/stdc++.h>
#pragma G++ optimize (2)
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f, mod=1000000007, log_2=20;
int a[100100], b[100100];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}

inline void print(int x)
{
    if (x>=10)  print(x/10);
    putchar(x%10+'0');
}

int main()
{
    int n; n=read();
    ll ans=0; 
    for (int i=1; i<=n; i++)
        a[i]=read(), b[i]=read();
    sort(a+1, a+n+1); sort(b+1, b+n+1);
    for (int i=1; i<=n; i++) ans+=(max(a[i], b[i])+1);
    printf("%lld\n",ans);
    return 0;
}