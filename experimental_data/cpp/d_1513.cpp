//#pragma comment(linker, "/stack:200000000")							

#pragma GCC optimize("Ofast")

//#pragma GCC target("abm,mmx,avx,tune=native")

//#pragma GCC optimize("unroll-loops")

 

#include <bits/stdc++.h>                                                               

//#include <ext/pb_ds/assoc_container.hpp> // ????? ????. 

//#include <ext/pb_ds/tree_policy.hpp> // ???????? ????? tree_order_statistics_node_updat 

//#include <ext/pb_ds/detail/standard_policies.hpp>

#define int long long

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

                    	

const int N = 3e5+5, K = 5e3, LG = 17;

using namespace std;         	

const ll mod = 1e9 + 7;//998244353;

int n, m, k;

int a[N];

int l[N], r[N];

int p[N];

int get(int a){

	return a == p[a]?a:p[a] = get(p[a]);

}

void solve(){

	cin >> n >> k;

	for(int i = 1; i <= n; i++){

		cin >> a[i];

		p[i] = i;

	}

	a[0] = 1;

	stack < int > q;

	q.push(0);

	for(int i = 1; i <= n; i++){

		while(q.size() > 1 && a[q.top()]%a[i] == 0){

			q.pop();

		}

		l[i] = q.top() + 1;

		q.push(i);

	}

	q = stack<int>();

	a[n + 1] = 1;

	q.push(n + 1);

	vector < int > ord;

	for(int i = n; i > 0; i--){

		ord.pb(i);

		while(q.size() > 1 && a[q.top()]%a[i] == 0){

			q.pop();

		}

		r[i] = q.top() - 1;

		q.push(i);

	}

	sort(all(ord), [](int i, int j){return a[i] < a[j];});

	int res = 0;

	for(int i: ord){

		if(a[i] >= k)break;

		for(int j = i + 1; j <= r[i]; j++){

			int x = get(j);

			int y = get(i);

			if(x == y){

				break;				

			}

			if(rand()&1)swap(x,y);

			p[x] = y;			

			res += a[i];

		}		

		for(int j = i - 1; j >= l[i]; j--){

			int x = get(j);

			int y = get(i);

			if(x == y)

				break;

			if(rand()&1)swap(x,y);

			p[x] = y;

			res += a[i];

		}

	}

	for(int i = 1; i < n; i++){

		int x = get(i);

		int y = get(i + 1);

		if(x != y){

			res += k;

			if(rand()&1)

				swap(x,y);

			p[x] = y;

		}

	}

	cout << res << '\n';	

}



main(){

    ios_base::sync_with_stdio(0);

	cin.tie(0);cout.tie(0);    

	int t = 1;

	cin >> t;

	while(t--){

		solve();

	}

}