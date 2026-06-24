/*

/\

/\\

\//

\/

---->>

/\

/\\

\//

\/

*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long int ;

const ll MOD = 1e9 + 7 ;

const double eps = 1e-09;

const double pi = 3.1415926535 ;

// #include<ext/pb_ds/assoc_container.hpp>

// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;

// using namespace __gnu_pbds;

#define speedup ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

#define LFT p<<1 , l , (l+r)>>1

#define RGH p<<1|1 , ((l+r)>>1)+1 , r

#define pb push_back

#define INDEX order_of_key

#define AT find_by_order

#define nptr nullptr

#define pf push_front

#define ppb pop_back

#define ppf pop_front

#define pll pair<ll,ll>

#define pii pair<int,int>

#define pil pair<int,ll>

#define endl '\n'

#define coutpair(p) cerr << p.first << " " << p.second << endl ;

//#define size(x) (x).size()

#define all(x) (x).begin() , (x).end()

#define deb(x) cerr << #x << " " << x << endl ;

#define debl(x) cerr << #x << " " << x << " " ;

#define log(x) (31^__builtin_clz(x))

#define F first

#define S second

//template <typename T>

// using ordered_set =  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ;

//mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

//struct chash {

// 	const uint64_t C = ll(2e18 * acos((long double) - 1)) + 71;

// 	const int RANDOM = rng();

// 	ll operator()(ll x) const {

// 		return __builtin_bswap64((x ^ RANDOM) * C);

// 	}

// };

//template<class K, class V> using umap = gp_hash_table<K,	 V, chash>;



bool inrange(ll x, ll y, ll n  , ll m  ) { return x < n && x >= 0 && y < m && y >= 0 ; }

template<typename T > 

ll mxself(T & i , T j ) { i = max(i, j) ; return i ; }

template<typename T > 

ll mnself(T & i , T j ) { i = min(i, j) ; return i ; }

void PRE_EXEC()

{

	speedup ;

//#ifndef ONLINE_JUDGE

//	freopen("input.in" , "r" , stdin )  ;

//	freopen("output.out" , "w", stdout) ;

//#endif

}

/*------------------------------------------------------------

--------------------------------------------------------------*/



ll n ; 		

ll x[3] ,y[3] ;

ll cen() 

{

	for(ll i =0 ;i < 3 ;i++) {

		for(ll j =0 ;j < 3 ;j++) 

		{

			for(ll k =0  ;k < 3 ;k++) 

			{

				if(i == k || j == k || i ==j ) continue ;

				if(x[i] == x[j] &&  y[i]== y[k] ) 

				{

					return  i ;

				}

			}

		}

	}

throw ;

}

int main()

{

	PRE_EXEC();

 	ll t; cin >> t; 

 	while(t--)

 	{

 		cin >> n ;

 		for(ll i= 0 ;i < 3 ;i++) 

 		{

 			cin >> x[i] >> y[i] ;

 		}

 		ll dx , dy ; cin >> dx >> dy ;

 		ll i = cen() ; 

 		if((x[i] == 1|| x[i] == n ) && (y[i] == 1 || y[i] == n))

 		{

 			cout << ((x[i] == dx || y[i] == dy ) ? "YES" : "NO") << endl ;

 			continue ;

 		}

 		cout <<( (dx % 2 == x[i] % 2 || dy % 2 == y[i] % 2 ) ? "YES" : "NO") << endl;

 		

 	}

  	return 0;

}



/*------------------------------------------------------

https://codeforces.com/problemset/problem/1737/C

------------------------------------------------------*/