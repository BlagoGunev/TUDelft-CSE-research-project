#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ld long double
int read()
{
	char x=getchar();int ans=0,flag=1;
	while(!isdigit(x)) if (x=='-') flag=-1,x=getchar();else x=getchar();
	while(isdigit(x)) ans=ans*10+x-'0',x=getchar();
	return ans*flag;
}
int prime[100005],cnt;
bool is_prime[100005];
int gcd(int x,int y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
void check()
{
	for (int i=2;i<=100000;i++)
	{
		if (!is_prime[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt;j++)
		{
			if (i*prime[j]>=100000) break;
			is_prime[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
}
vector<int> v,qwq[15];
void dfs(int dep,int sum,int cnt,bool flag)
{
	if (!flag) qwq[sum].push_back(cnt);
	if (dep==v.size()) return;
	dfs(dep+1,sum+1,cnt*v[dep],0);
	dfs(dep+1,sum,cnt,1);
}
signed main()
{
	check();
	int T=read();
	while(T--)
	{
		int x=read(),y=read();
		int GCD=gcd(x,y);
		y/=GCD;
		for (int i=0;i<15;i++)
			qwq[i].clear();
		v.clear();
		int xr=x/GCD+y,xl=x/GCD;
		int ans1=xl,ans2=xr;
		for (int i=1;i<=cnt;i++)
		{
			if (y==1) break;
			int tmp=0;
			while(y%prime[i]==0)
			{
				tmp++;
				y/=prime[i];
			}
			if (tmp)
			{
				v.push_back(prime[i]);
			}
		}
		if (y!=1) v.push_back(y);
		dfs(0,0,1,0);
		for (int i=1;i<=v.size();i++)
		{
			for (int j=0;j<qwq[i].size();j++)
			{
				if (i&1)
				{
					ans1-=xl/qwq[i][j];
					ans2-=xr/qwq[i][j];
				}
				else
				{
					ans1+=xl/qwq[i][j];
					ans2+=xr/qwq[i][j];
				}
			}
		}
		cout<<ans2-ans1<<endl;
	}
	return 0;
}