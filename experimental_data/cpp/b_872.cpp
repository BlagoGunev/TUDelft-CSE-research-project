#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>
#define rep(i,x,y) for(register int i = x;i <= y;++i)
#define repd(i,x,y) for(register int i = x;i >= y;--i)
using namespace std;
typedef long long ll;
template<typename T>void read(T&x)
{
	x = 0;char c;int sign = 1;
	do { c = getchar();if(c == '-') sign = -1; }while(c < '0' || c > '9');
	do { x = x * 10 + c - '0'; c = getchar();	}while(c <= '9' && c >= '0');
	x *= sign;
}

const int N = 1e5 + 500,inf = 1e9+7;
int n,k;
int a[N];
int ans;

int main()
{
	read(n);read(k);
	if(k >= 3)
	{
		int x;
		ans = -inf;
		rep(i,1,n)
			read(x),ans = max(ans,x);
		printf("%d",ans);
	}
	else if(k == 2)
	{
		ans = -inf;
		int x = inf;
		rep(i,1,n)
			read(a[i]);
		rep(i,1,n)
			x = min(x,a[i]),ans = max(ans,x);
		x = inf;
		repd(i,n,1)
			x = min(x,a[i]),ans = max(ans,x);
		printf("%d",ans);
	}
	else
	{
		int x;
		ans = inf;
		rep(i,1,n)
			read(x),ans = min (ans,x);
		printf("%d",ans);
	}
	return 0;
}