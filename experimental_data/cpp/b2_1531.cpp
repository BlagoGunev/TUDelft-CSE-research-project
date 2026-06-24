#include <bits/stdc++.h>

using namespace std;

#define hotel trivago

#define vi vector<int>

#define pii pair<int, int>

#define fi first

#define se second

#define int long long

#define all(x) x.begin(),x.end()

#define rall(x) x.rbegin(), x.rend()

#define mie(a) *min_element(all(a))

#define mae(a) *max_element(all(a))

#define l4d(type) std::numeric_limits<type>::max()



template <class T>

inline void in(vector<T>&v) {

    for (auto&i:v)cin>>i;

}

template<typename T1>T1 gcd(T1 a,T1 b)

{return(b==0)?a:gcd(b,a%b);}





signed main(void) {

	ios_base::sync_with_stdio(0);

	cout.tie(0); cin.tie(0);

	

	int n; cin >> n;

	int res = 0;

	map<int, int> st;

	map<pii, int> cnt;

	

	while (n--) {

		int a, b; cin >> a >> b;

		if (a>b)swap(a,b);

		if (!(a-b)) {

			res += st[a]; st[a]++;

		}

		else {

			res += st[a]+st[b]-cnt[{a,b}];

			st[a]++; st[b]++; cnt[{a,b}]++;

		}

	}

	cout << res;

	return-0; 

}