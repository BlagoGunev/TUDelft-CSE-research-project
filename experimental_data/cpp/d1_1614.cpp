//#define LOCAL
#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
#define all(x) (x).begin(), (x).end()
#define VI vector<int>
#define VLL vector<ll>
#define pll pair<ll, ll>
#define double long double
//#define int long long
using namespace std;
const int N = 1e6 + 100, M = 2e7 + 100;
const int inf = 1e9;
//const ll inf = 1e18
const ll mod = 998244353;//1e9 + 7
const double eps = 1e-10;

#ifdef LOCAL
void debug_out(){cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
	cerr << " " << to_string(H);
	debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int n, m, a[N];
int pri[M / 2], pnum = 0;
bool np[M];

int factor[N];
int cnt[N];
int fnum, fcur;

int vi[M], hav;
ll mx;
int tot;
ll f[M];

void ddfs(int x)
{
	if(x > fnum)
	{
		if(fcur != tot)
			mx = max(mx, f[fcur] - 1LL * hav * fcur);
		return;
	}
	int bf = fcur;
	for(int i = 0; i <= cnt[x]; i++)
	{
		ddfs(x + 1);
		fcur *= factor[x];
	}
	fcur = bf;
}

void dfs(int x)
{
	if(x > fnum)
	{
		++vi[fcur];
		return;
	}
	int bf = fcur;
	for(int i = 0; i <= cnt[x]; i++)
	{
		dfs(x + 1);
		fcur *= factor[x];
	}
	fcur = bf;
}


void doit(int x, int op)
{
	int xx = x;
	fnum = 0;
	for(int i = 1; i <= pnum && pri[i] <= x / pri[i]; i++)
	{
		if(x % pri[i])
			continue;
		factor[++fnum]  = pri[i];
		cnt[fnum] = 0;
		while(x % pri[i] == 0)
			++cnt[fnum], x /= pri[i];
	}
	if(x > 1)
	{
		factor[++fnum] = x;
		cnt[fnum] = 1;
	}
	if(op == 0)
	{
		fcur = 1, dfs(1);
	}
	else
	{
		tot = xx;
		fcur = 1;
		ddfs(1);
	}
}


void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		doit(a[i], 0);
	}
	ll ans = 0;
	for(int i = 1; i <= 2e7; i++)
	{
		if(!vi[i])
			continue;
		if(i == 1)
			f[i] = n;
		else
		{
			f[i] = 1LL * vi[i] * i;
			mx = 0;
			hav = vi[i];
			doit(i, 1);
			f[i] += mx;
		}
		ans = max(ans, f[i]);
	}
	cout << ans << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 2e7;
	for(int i = 2; i <= n; i++)
	{
		if(!np[i])
		{
			pri[++pnum] = i;
		}
		for(int j = 1; j <= pnum && i <= n / pri[j]; j++)
		{
			np[i * pri[j]] = 1;
			if(i % pri[j] == 0)
				break;
		}
	}
	sol();
}