#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

#define maxn 5010

char buf[maxn];
int dp[maxn], vis[maxn], g[maxn], can[maxn];

void lemon()
{
	dp[0]=0;
	rep(i,1,5000)
	{
		memset(vis,0,sizeof vis);
		rep(k,1,i) vis[dp[max(k-2,0)]^dp[max(i-k-1,0)]]=1;
		int z=0; while (vis[z]) z++;
		dp[i]=z;
	}
	scanf("%s",buf+1); int n=strlen(buf+1);
	if (n<=2)
	{
		cout<<"Second"<<endl;
		return;
	}
	rep(i,2,n-1)
		if (buf[i-1]==buf[i+1])
			can[i]=1;
	
	int combo=0;
	rep(i,2,n)
		if (!can[i])
		{
			g[combo]++;
			combo=0;
		}
		else  combo++;
	
	int final=0;
	rep(i,1,5000) if (g[i]%2) final^=dp[i];
	if (!final) 
	{
		cout<<"Second"<<endl;
		return;
	}
	cout<<"First"<<endl;
	
	combo=0;
	rep(i,2,n)
		if (!can[i])
		{
			rep(k,1,combo) 
				if ((final^dp[combo]^dp[max(k-2,0)]^dp[max(combo-k-1,0)])==0)
				{
					cout<<i-combo+k-1<<endl;
					return;
				}
			combo=0;
		}
		else  combo++;
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("E.in","r",stdin);
	#endif
	lemon();
	return 0;
}