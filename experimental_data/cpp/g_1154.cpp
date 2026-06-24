# pragma GCC optimize("Ofast")
# pragma GCC optimization ("unroll-loops")
# include "bits/stdc++.h"
std::pair<int,int> DR[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define rc(s) return cout << s,0
# define rcg(s) cout << s;exit(0)
# define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define db(x) cerr << #x << " = " << x << '\n'
# define pb push_back
# define mp make_pair
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())
# define int ll
using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# define LOCAL
# define sim template < class c
# define ris return * this
# define dor > debug & operator <<
# define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
*this << "[";
for (auto it = d.b; it != d.e; ++it)
*this << ", " + 2 * (it == d.b) << *it;
ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define show(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
int gcd(int a, int b)
{
if(b) return gcd(b,a%b);
return a;
}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int n,a[1 << 20];
map<int,vector<int>>m;
pair<int,pair<int,int>>mn;

bitset<10000005>occ;

int32_t main(){_
	//freopen("input","r",stdin);
	cin >> n;
	mn = mp(1e18,mp(0,0));
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		m[a[i]].pb(i);
		occ[a[i]] = 1;
	}
	for(int i = 1;i <= 10000000;i++)
	{
		//debug() << show(i);
		int cnt = 0;
		pair<int,int>p;
		for(int j = i;j <= 10000000;j += i)
		{
			if(cnt == 2) break;
			if(!occ[j]) continue;
			if(cnt == 0)
			{
				if(sz(m[j]) == 1)
				{
					cnt++;
					p.first = m[j].back();
				}
				else
				{
					cnt = 2;
					p = mp(m[j][0],m[j][1]);
				}
			}
			else
			{
				p.second = m[j][0];
				cnt++;
			}
		}
		if(cnt == 2) mn = min(mn,mp((a[p.first] * a[p.second]) / gcd(a[p.first],a[p.second]),p));
	}
	auto ans = mn.second;
	cout << min(ans.first,ans.second) << ' ' << max(ans.first,ans.second);
	return 0;
}