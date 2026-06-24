///
///   ♪ Hashire sori yo ♪
///   ♪ Kaze no you ni  ♪
///   ♪ Tsukimihara wo  ♪
///   ♪ PADORU PADORU   ♪
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	if(k > (n+1)/2) {cout << "-1\n"; return;}
	Loop(i,0,n) {
		Loop(j,0,n)
			cout << (i==j && (i&1) == 0 && i/2 < k? 'R': '.');
		cout << '\n';
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}