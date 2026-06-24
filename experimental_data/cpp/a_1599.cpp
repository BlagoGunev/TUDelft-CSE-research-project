#undef local

//#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()

#define allr(v) v.rbegin(),v.rend()

#define fori(i,n) for(ll i=0;i<n;i++)

#define ford(i,n) for(ll i = n-1;i >= 0;i--)

#define pb push_back

#define ll long long int

#define mod 998244353

#define pi pair<int,int>

#define pll pair<ll,ll>

#define mp make_pair

#define fi first

#define se second

#ifdef local

#define debug(x) cout<<#x<<" = "<<x<<endl

#define debug2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define debug3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl

#define debug4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl

#define debugV(v) cout <<#v<<" = ";fori(i,(int) v.size()) {cout << v[i] << " ";} cout << endl << endl;

#define printVector(v) {fori(i,(int) v.size()) {cout << v[i] << " ";} cout << "\n";}

#else

#define debug(x) 1

#define debug2(x,y) 1

#define debug3(x,y,z) 1

#define debug4(x,y,z,q) 1

#define debugV(v) 1

#define printVector(v) {fori(i,(int) v.size()) {cout << v[i] << " ";} cout << "\n";}

#endif

std::mt19937 rng((unsigned int) std::chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template<typename T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(int ttt)

{

	int n;

	cin >> n;

	vector<int> a(n);

	fori(i,n) cin >> a[i];

	string s;

	cin >> s;

	sort(all(a));

	vector<pi> res;

	int fwd = 0,bck = 0;

	int whereMn,whereNxt;

	if(s[0]=='L')

	{

		whereMn = 0;

		whereNxt = 1;

		res.pb(mp(fwd++,0));

	}

	else

	{

		whereMn = 1;

		whereNxt = 0;

		res.pb(mp(fwd++,1));

	}

	for(int i = 1;i < n;i++)

	{

		if(s[i] != s[i-1])

		{

			res.pb(mp(fwd++,whereNxt));

			whereNxt = 1-whereNxt;

		}

		else

		{

			res.pb(mp(--bck,1-whereMn));

			whereMn = 1 - whereMn;

			whereNxt = (s[i]=='L' ? 1 : 0);

		}

	}

	for(auto p:res)

	{

		cout << a[-bck + p.fi] << " " << (p.se==0 ? "L" : "R" ) << "\n";

	}

}

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int ttt;

    ttt = 1;

    //cin >> ttt;

    fori(i,ttt) solve(i);

}