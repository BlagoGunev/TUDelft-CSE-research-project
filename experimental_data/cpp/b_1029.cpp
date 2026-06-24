#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
#define out(a) printf("%d",a)
#define writeln printf("\n")
const int N=2e5+50;
const int MOD=1e9+7;
const int base=233;
using namespace std;
int n;
int last,now,ans;
int a[N];
int read()
{
    int s=0,t=1; char c;
	while (c<'0'||c>'9'){if (c=='-') t=-1; c=getchar();}
	while (c>='0'&&c<='9'){s=s*10+c-'0'; c=getchar();}
	return s*t;
}
ll readl()
{
    ll s=0,t=1; char c;
	while (c<'0'||c>'9'){if (c=='-') t=-1; c=getchar();}
	while (c>='0'&&c<='9'){s=s*10+c-'0'; c=getchar();}
	return s*t;
}
int gcd(int a,int b)
{
	return b==0?a:b%a;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	  a[i]=read();
	   last=0; ans=1;
	for (int i=1;i<n;i++)
	 if (2*a[i]>=a[i+1]) continue;
	 else {
	   ans=max(ans,i-last);
	   last=i;
	}
	ans=max(ans,n-last);
	  out(ans);
	return 0;
}