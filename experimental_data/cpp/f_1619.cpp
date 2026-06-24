//#pragma comment(linker, "/stack:200000000")						

#pragma GCC optimize("Ofast") 

//#pragma GCC optimize("Ofast")

//#pragma GCC target("abm,mmx,avx,tune=native")

//#pragma GCC optimize("unroll-loops")

 

#include <bits/stdc++.h>                                                               

//#include <ext/pb_ds/assoc_container.hpp> // ????? ????. 

//#include <ext/pb_ds/tree_policy.hpp> // ???????? ????? tree_order_statistics_node_updat 

//#include <ext/pb_ds/detail/standard_policies.hpp>

//#define int long long

#define ll long long

#define ull unsigned long long

#define ld long double

#define rep(i, l, r) for (int i = l; i <= r; i++)

#define repb(i, r, l) for (int i = r; i >= l; i--)

#define sz(a) (int)a.size()

#define fi first

#define se second

#define all(x) x.begin(),x.end()

#define pb push_back  

#define mp(a, b) make_pair(a, b)

#define ret(a) {cout << a; exit(0);}

 

using namespace std;



mt19937 mrand(random_device{}()); 

int rnd(int x) { return mrand() % x;}



ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}



typedef pair < int , int > pii ;                                            

typedef pair < long long  , long long > pll ;

                    	

const int N = 2e5+5, K = 1e6, LG = 17;

using namespace std;         	

const ll mod = 1e9 + 7;//998244353;

int a[N];

void solve(){

	int n, m, k;

	cin >> n >> m >> k;

	int x = n % m;

	for(int i = 1; i <= n; i++)

		a[i] = 0;

	int ov = (n + m - 1)/m;

	for(int j = 1; j <= k; j++){

		int need = (n + m - 1)/m * x;

		vector < bool > was(n + 1);

		vector < int > vc;

		int mn = a[1];

		for(int i = 1; i <= n; i++){

			mn = min(mn, a[i]);

		}

		for(int i = 1; i <= n; i++){

			if(a[i] == mn && need > 0){

				a[i]++;

				vc.pb(i);

				was[i] = 1;

				need--;

				if(vc.size() == ov){

					 cout << vc.size() << ' ';

					 for(int x: vc)

					 	cout << x << ' ';

					 cout << '\n';

					 vc.clear();

				}		

			}

		}

		for(int i = 1; i <= n&&need > 0; i++){

			if(was[i])

				continue;

			if(need > 0){

				vc.pb(i);

				was[i] = 1;

				need--;

				a[i]++;

				if(vc.size() == ov){

					 cout << vc.size() << ' ';

					 for(int x: vc)

					 	cout << x << ' ';

					 vc.clear();

					 cout << '\n';

				}		

			}

		}

		for(int i = 1; i <= n; i++){

			if(was[i])

				continue;

			vc.pb(i);

			if(vc.size() == n/m){

				 cout << vc.size() << ' ';

				 for(int x: vc)

				 	cout << x << ' ';

				 cout << '\n';                           

				 vc.clear();

			}					

		}

//		cerr << '\n';

	}

}                                                              	 	



main(){

	

    ios_base::sync_with_stdio(0);

	cin.tie(0);cout.tie(0);    



    int t = 1;

	cin >> t ;

	while(t--){

		solve();

	}

}