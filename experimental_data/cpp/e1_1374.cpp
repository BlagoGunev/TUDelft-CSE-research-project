#include <bits/stdc++.h>



using namespace std;



#define out(x) cout << #x << '=' << x << endl

#define out2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl 

#define no cout << "No" << endl; return

#define yes cout << "Yes" << endl; return

#define outvec(a) for (int v : a) { cout << v << ' '; } cout << endl

#define lowbit(x) (x & -x)

#define gcd __gcd

#define bitcount __builtin_popcount



#define pb push_back

#define fr front()

#define bk back()

#define tp top()

#define fi first

#define se second



using ll = long long;

using pii = pair<int, int>;





void solve() {

	int n, k;

	cin >> n >> k;

	vector<int> all;

	vector<int> alice;

	vector<int> bob;

	for (int i = 1; i <= n; i++) {

		int t, a, b;

		cin >> t >> a >> b;

		if (a && b) {

			all.pb(t); 

		} else if (a) {

			alice.pb(t);

		} else if (b) {

			bob.pb(t);

		}

	}

	sort(all.begin(), all.end());

	sort(alice.begin(), alice.end());

	sort(bob.begin(), bob.end());

	vector<ll> preall(all.size() + 1);

	for (int i = 1; i <= all.size(); i++) {

		preall[i] = preall[i - 1] + all[i - 1];

	}

	vector<ll> prealice(alice.size() + 1);

	for (int i = 1; i <= alice.size(); i++) {

		prealice[i] = prealice[i - 1] + alice[i - 1];

	}

	vector<ll> prebob(bob.size() + 1);

	for (int i = 1; i <= bob.size(); i++) {

		prebob[i] = prebob[i - 1] + bob[i - 1];

	}

	ll ans = 0x3f3f3f3f3f3f3fLL;

	for (int i = 0; i <= min((int) all.size(), k); i++) {

		int a = k - i;

		int b = k - i;

		if (a >= prealice.size() || b >= prebob.size()) {

			continue;

		}

		ans = min(ans, preall[i] + prealice[a] + prebob[b]);

	}

	if (ans == 0x3f3f3f3f3f3f3fLL) ans = -1;

	cout << ans << endl;

}



int main(void) {

    ios::sync_with_stdio(false);

    cin.tie(0); cout.tie(0);

    int t = 1;

    //cin >> t;

    

    while (t--) {

    	solve();

	}

}