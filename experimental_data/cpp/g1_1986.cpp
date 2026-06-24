#include<bits/stdc++.h>
#include<fstream>
#include<random>

using namespace std;

#define endl '\n'
#define PII pair<int,int>
#define F(i,a,b) for(register int i=a;i<=b;++i)
#define PLL pair<long long,long long>
#define lowbit(x) (x&(-x))
 
mt19937_64 rng(random_device{}());
long long myRand(long long l,long long r) {
    uniform_int_distribution<long long> uid(l,r);
    return uid(rng);
}
 
const int key=1337;
const int N=1e5+100;
const int MAXN = 2010;
const long long INF=(1ll<<60);
const long long inf=(1ll<<30);
const int mod1=myRand(8e8,1e9);
const int mod2=998244353;
const int mod=1e9+7;

vector<int>g[N];

int n,num[N];
map<int,int>st[N];

void solve()
{
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		int gd=__gcd(num[i],i),x=i/gd,now=num[i]/gd;
		for(auto k:g[now])
		{
			ans+=st[k][x];
		}
		for(auto k:g[now])
		{
			st[x][k]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(auto k:g[num[i]])
		{
			st[k].clear();
		}
	}
	cout<<ans<<endl;
}

int main()
{
	for(int i=1;i<=1e5;i++)
	{
		for(int j=i;j<=1e5;j+=i)
		{
			g[j].push_back(i);
		}
	}
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}