#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define pa pair<int,int>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const double eps=0.000000001;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[100005],b[100005],c[100005];
void solve()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	bool f=0;
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++)
	{
		c[i]=b[i]-a[i];
		if (c[i]<0) {puts("NO");return;}
		if (c[i])
		{
			if (f&&c[i]!=c[i-1]) {puts("NO");return;}
			f=1;
		}
	}
	puts("YES");
}
int main()
{
	int T=read();
	while (T--) solve();
	return 0; 
}