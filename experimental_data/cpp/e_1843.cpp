/* IN THE NAME OF GOD */
/* |\/| /-\ |\| | |\/| /-\ */

#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)x.size()
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define mr make_pair
//#define int long long
#define pii pair<int, int>
typedef long double ld;
typedef long long ll;

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const int inf = 1e9 + 1;

int l[N], r[N], x[N], ps[N];

int32_t main(){
    ios_base:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, q;
		cin >> n >> m;
		for(int i = 1; i <= m; i++)
			cin >> l[i] >> r[i];
		cin >> q;
		for(int i = 1; i <= q; i++)
			cin >> x[i];
		int L = 0, R = q + 1;
		while(R - L > 1){
			int mid = (L + R) / 2;
			memset(ps, 0, sizeof ps);
			for(int i = 1; i <= mid; i++)
				ps[x[i]] = 1;
			for(int i = 1; i <= n; i++)
				ps[i] += ps[i - 1];
			bool f = 0;
			for(int i = 1; i <= m; i++){
				if(ps[r[i]] - ps[l[i] - 1] > (r[i] - l[i] + 1) / 2){
					f = 1;
					break;
				}
			}
			if(f)
				R = mid;
			else
				L = mid;
		}
		if(R == q + 1)
			cout << "-1\n";
		else
			cout << R << endl;
	}
}