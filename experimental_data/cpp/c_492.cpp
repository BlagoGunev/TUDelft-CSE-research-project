#include <bits/stdc++.h>

using namespace std;

// Input macros
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define si(n) scanf("%d",&n)
#define sii(n, m) scanf("%d%d",&n,&m)
#define siii(n, m, x) scanf("%d%d%d",&n,&m,&x)
#define sc(n) scanf(" %c",&n)
#define sd(n) scanf("%lf",&n)
#define read(s) freopen(s, "r", stdin)
#define write(s) freopen(s, "w", stdout);
#define endl '\n'

// Useful constants
#define INF (ll)1e17
#define EPS 1e-9

// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd

// Traversal macros
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,n) for (int i = n-1; i >= 0; i--)
#define forall(i,a,b,x) for (int i = a; i < b; i+=x)
#define foreach(v, c) for (typeof(c.begin()) v = c.begin(); v != c.end(); v++)

// Useful container manipulation
#define all(a) a.begin(), a.end()
#define in(a, b) (b.find(a) != b.end())
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define f first
#define s second
#define parseInt(x) atoi(x.c_str())
#define parseLong(x) atol(x.c_str())
#define charToInt(x) x - '0'
#define intToChar(x) x + '0'
#define toString(x) dynamic_cast< std::ostringstream & >( \
( std::ostringstream() << std::dec << x ) ).str()

// Printing
#define print(a,s) {forn(i, s) { if (i > 0) cout << " "; cout << a[i];} puts("");}

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<long long, long long> llll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int> > vii;
typedef vector<pair<long long, long long> > vll;

int n, r, avg, a, b;
ii c[100001];

int main()
{
	siii(n, r, avg);
	
	ll sum = 0;
	forn(i, n)
	{
		sii(a, b);
		c[i] = mp(b, a);
		sum += a;
	}

	sort(c, c+n);

	ll res = 0;
	forn(i, n)
	{
		if ((double)sum/n + EPS > avg)
			break;
		ll term = sum + (r - c[i].s);
		if ((double)term/n + EPS < avg)
		{
			sum += (r - c[i].s);
			res += (ll)c[i].f * (r - c[i].s);
			continue;
		}

		ll low = c[i].s;
		ll high = r;
		ll ans = -1;

		while(low <= high)
		{
			ll mid = low + (high-low)/2;

			ll val = sum + (mid-c[i].s);
			if ((double)val/n + EPS > avg)
			{
				ans = mid;
				high = mid-1;
			}
			else
				low = mid+1;
		}

		sum += (ans - c[i].s);
		res += (ll)c[i].f * (ans - c[i].s);
	}

	cout << res << endl;
}