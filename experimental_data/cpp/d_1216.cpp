#include <bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ll long long
using namespace std;
inline int read()
{
    int f=1,x=0;
    char ch;
    do
    {
        ch=getchar();
        if(ch=='-')
            f=-1;
    }while(ch<'0'||ch>'9');
    do
    {
        x=x*10+ch-'0';
        ch=getchar();
    }while(ch>='0'&&ch<='9');
    return f*x;
}
const int N=2e5;

int n;
int a[N+1];
ll y,z;
int minn=2147483647;
int maxx=0;

inline int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        minn=min(a[i],minn);
    }

    for(int i=1;i<=n;i++)
    {
        a[i]-=minn;
        if(a[i]==0)
            continue;
        if(z)
            z=gcd(z,a[i]);
        else
            z=a[i];
        maxx=max(a[i],maxx);
    }
    for(int i=1;i<=n;i++)
        y+=(maxx-a[i])/z;

    printf("%lld %d\n",y,z);
    return 0;
}