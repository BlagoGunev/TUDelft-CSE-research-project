#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){

    int n, m, k; // n is elements, m is place in line, k is number of people to control

    cin >> n >> m >> k;

    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];



    if (k >= (m - 1)){

        int ans = 0;

        for (int i = 0; i < m; i++){

            ans = max(ans, a[i]);

            ans = max(ans, a[n - 1 - i]);

        }

        cout << ans << '\n';

        return;

    }



    int lp = k;

    int rp = n - 1;

    int invols = m - k - 1;

    int best = 0;

    int cb = INT_MAX;

    vector<int> sols;

    sols.clear();

    for (int i = 0; i <= k; i++){

        best = 0;

        cb = INT_MAX;

        for (int j = 0; j <= invols; j++){

            best = max(a[lp + j], a[rp - (invols - j)]);

            cb = min(cb, best);

        }

        lp--;

        rp--;

        sols.push_back(cb);

    }



    cout << *max_element(begin(sols), end(sols)) << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}