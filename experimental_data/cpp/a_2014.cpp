#include<bits/stdc++.h>
#define int long long
#define psbk push_back
#define fst first
#define scd second
#define umap unordered_map
#define pqueue priority_queue
#define vc vector
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
constexpr int inf = 0x3f3f3f3f;
int n, k, a[55];
void solve()
{
	cin >> n >> k;
	int nw = 0, ans = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i] >= k)
		{
			nw += a[i];
		}
		if(!a[i] && nw)
		{
			nw--, ans++;
		}
	}
	cout << ans << endl;
}
signed main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		solve();
	}
	return 0;
}