#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <random>
#include <set>

typedef int ll;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())

using namespace std;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
    ll query(int l, int r){ // [l, r]
        return query(r + 1) - query(l);
    }
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

const int N = 1e6 + 3;

int n, a[N], ans[N], pos[N];

FT fenwick(2 * N + 3);

void solve(){
    cin >> n;
    
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pos[a[i]] = i;
        ans[i] = 0;
    }
    // shuffle(a + 1, a + 1 + n, mt);

    for(int i = 1; i <= 2 * n; ++i){
        fenwick.s[i] = 0;
    }

    for(int i = 1; i <= n; ++i){
        if(a[i] >= i){
            fenwick.update(a[i], 1);
        }
    }

    for(int i = 1; i <= n; ++i){
        int new_a = a[i];
        if(a[i] <= i) new_a += n;

        if(a[i] == i){
            fenwick.update(i, -1);
            fenwick.update(i + n, 1);
        }
        else{
            fenwick.update(new_a, -1);
            
            // int new_pos = pos[i];
            // if(pos[i] <= i) new_pos += n;
            fenwick.update(i + n, 1);
        }

        if(i == a[i]){
            ans[a[i]] = 0;
        }
        else{
            ans[a[i]] = new_a - i;
            ans[a[i]] -= fenwick.query(new_a);
        }
    }


    for(int i = 1; i <= n; ++i){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}