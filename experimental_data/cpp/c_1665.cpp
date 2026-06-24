// Code by Apurva Patil(rustee_95)

#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

#define ll long long int

#define rep(i,n) for(ll i=0;i<n;i++)

#define all(x) (x).begin(), (x).end()

#define pb push_back

#define vll vector<ll>

#define vi vector<int>

#define scan(vvv,nnn) for(ll i=0; i<nnn; i++) cin>>vvv[i];

#define print(vvv,nnn) for(ll i=0; i<nnn; i++) cout<<vvv[i]<<" ";

#define scout(vvv) cout<<vvv<<endl

#define ff first

#define ss second

#define iendl "\n", cout<<flush



using namespace std;



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



#ifndef ONLINE_JUDGE

#include "db.cpp"

#else

#define dbg(x)

#endif



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



// Input Operatirons Pair, Vector

template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a) {in >> a.ff >> a.ss; return in;}

template<class T>istream& operator>>(istream &in, vector<T> &a) {for (auto &i : a) {in >> i;} return in;}



// Output Operations Pair Vector

template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a) {os << a.ff << " " << a.ss; return os;}

template<class T>ostream& operator<<(ostream &os, vector<T> &a) {for (int i = 0 ; i < a.size() ; i++) {if (i != 0) {os << ' ';} os << a[i];} return os;}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



const ll INF = 1e18;

const ll mod = 1000000007;

const int N = 200005;



void solve() {

	int n;

	cin >> n;

	vi v(n - 1);

	cin >> v;

	map<int, int> mpp;

	rep(i, n - 1) {

		mpp[v[i]]++;

	}

	vi t;

	for (auto it : mpp) {

		t.pb(it.ss);

	}

	t.pb(1);

	sort(all(t));

	reverse(all(t));

	int nn = t.size();

	int start = nn, end = n;

	int ans = 0;

	function<bool(int)> check = [&](int tot) {

		int cnt = 0;

		for (int i = 0; i < nn; i++) {

			cnt += max(0, t[i] - tot + i);

		}

		tot -= nn;

		return cnt <= tot;

	};

	while (start <= end) {

		int mid = start + end;

		mid /= 2;

		if (check(mid)) {

			ans = mid;

			end = mid - 1;

		}

		else {

			start = mid + 1;

		}

	}

	cout << ans << endl;



}

/*



*/

int main() {

	fast;

#ifndef ONLINE_JUDGE

	freopen("err.txt", "w", stderr);

#endif

	ll testcase = 1;

	cin >> testcase;

	while (testcase--) {

		solve();

	}

	return 0;

}