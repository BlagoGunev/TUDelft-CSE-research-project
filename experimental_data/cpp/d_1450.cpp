#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double
#define str string

#define pb push_back
#define pf push_front
#define pob pop_back()
#define pof pop_front()

#define in insert

#define fi first
#define se second

#define size size()

#define begin begin()
#define end end()
#define back back()
#define front front()
#define rend rend()
#define rbegin rbegin()

#define ret return

#define ull unsigned long long

#define all(a) a.begin , a.end

#define gcd __gcd

#define lcm(a , b) (a * b) / gcd(a , b)

#define friopen freopen ("odd.in", "r", stdin); freopen("odd.out", "w", stdout);

using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const ll mod = 1e9 + 7 , mod2 = 998244353 , N = 5e6 , inf = 1e18;
const ld esp = 0.0000001 , Pi = 3.1415926535897932384626433832795;

void kol_a()
{
	ll n , i , j , v = 0;
	cin >> n;
	ll a[n + 12] = {} , d[n + 12] = {} , ans[n + 12] = {};
	for (i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		d[a[i]] ++;
		while(d[v + 1]) v ++;
	}
	ans[1] = (v == n);
	if (d[1])
	{
		ll l = 1 , r = n;
		for (i = n ; i > 1 ; i --)
		{
			ans[i] ++;
			ll x = n - i + 1;
			d[x] --;
			if (!d[x] && d[x + 1] && (a[l] == x || a[r] == x))
			{
				l += (a[l] == x);
				r -= (a[r] == x);
			}
			else break;
		}
	}
	for (i = 1 ; i <= n ; i ++) cout << ans[i];
	cout << '\n';
}

main()
{
	//friopen
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll _ = 1;
	
	cin >> _;
	
    while(_ --) kol_a();
}


/*



*/