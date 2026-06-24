#include <bits/stdc++.h>

using namespace std;



using ll = long long;



using vi = vector<int>;

#define pb push_back

#define all(x) begin(x), end(x)

#define sz(x) (int) (x).size()



using pi = pair<int,int>;

#define f first

#define s second

#define mp make_pair



void setIO(string name = "") {

	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io

	if (sz(name)) {

		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output

		freopen((name + ".out").c_str(), "w", stdout);

	}

}



int main() {

  setIO();

  int tt;

  cin >> tt;

  while (tt--) {

    int n;

    cin >> n;

    vector<int> a(n);

    for (auto& t : a)

      cin >> t;

    const ll MOD = int(1e9) + 7;

    ll x = *min_element(all(a));

    ll cnt = count(all(a), x);

    if (cnt < 2) {

      cout << 0 << '\n';

      continue;

    }

    bool bad = false;

    for (auto t : a)

      if ((t & x) != x) {

        bad = true;

        break;

      }

    if (bad) {

      cout << 0 << '\n';

      continue;

    }

    ll fact = 1;

    for (int i = 2; i <= n - 2; i ++)

      fact = (fact * (ll)i) % MOD;

    ll ans = (cnt * (cnt - 1)) % MOD;

    ans = (ans * fact) % MOD;

    ans %= MOD;

    cout << ans << '\n';

  }

}