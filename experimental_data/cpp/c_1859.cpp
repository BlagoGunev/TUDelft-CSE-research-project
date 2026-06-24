#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i =(a); i < (b); ++i)
#define re(i, n) FOR(i, 1, n)
#define ford(i, a, b) for(int i = (a); i >= (b); --i)
#define rep(i, n) for(int i = 0;i <(n); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll inf = 1e18;
const int maxn = 5005;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		ll ans = 0ll;
		for (int i = 0; i <= n; i++)
		{
			vi in;
			ll loc = 0ll;
			ll dupa = 0ll;
			for (int j = 0; j < i; j++) in.push_back(j+1);
			for (int j = i; j < n; j++) in.push_back(n - j + i);
			rep(i, n) 
			{
				loc += in[i] * (i+1);
				dupa = max(dupa, in[i] * (i+1));
			}
			ans = max(ans, loc - dupa);
		}
		cout << ans << '\n';
	}
}