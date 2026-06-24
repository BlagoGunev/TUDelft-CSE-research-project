#include "bits/stdc++.h"

#define sz(x) ((int)(x).size())

#define rep(i,b,c) for(int i=b;i<=c;i++)

#define rev(i,b,c) for(int i=b;i>=c;i--)

#define all(v) v.begin(),v.end()

#define clr(a,b) memset((a), (b), sizeof(a))

#define mp make_pair

using namespace std;

typedef long long ll; typedef pair<int, int> ii; typedef vector<int> vi; typedef vector<ii> vii;

const ll inf = INT_MAX/2,infl = LLONG_MAX/2;//2^18 = 262144 , 2^20 ~ 1e7, //262143 -- 1e5 + 1

const int N = ((int)2e5 + 10), K = 10000-1, mod = int(1e9) + 7;

const double eps = 1e-9;

inline void in(){

	ios_base::sync_with_stdio(0); cin.tie(0);

#ifdef Srinu73

	freopen("input.txt", "r", stdin);

#endif

}

template <class T> T modexp(T a, T b, T c){ T ans = 1; while (b){ if (b & 1)ans = (ans*a) % c; a = (a*a) % c; b >>= 1; }return ans; }

template <class T> T C(T n, T r){ r = min(r, n - r); T ans = 1; for (T i = 1; i <= r; i++){ ans *= (n - r + i); ans /= i; }return ans; }

ii a[K],dp[K];

vector<pair<ii, int> >v;

int main()

{

	in();

	int n, w, h;

	cin >> n >> w >> h;

	rep(i, 0, n - 1)cin >> a[i].first >> a[i].second;

	rep(i, 0, n - 1){

		if (a[i].first > w && a[i].second > h) v.push_back({ a[i], i });

	}

	sort(all(v));

	n = sz(v);

	rep(i, 0, n - 1)dp[i].first = 1, dp[i].second = v[i].second;

	rep(i, 1, n - 1){

		auto cur = v[i];

		rep(j, 0, i - 1){

			if (cur.first.first > v[j].first.first && cur.first.second > v[j].first.second && dp[i].first < dp[j].first + 1)

				dp[i].first = dp[j].first + 1;

		}

	}

	int mark = -1, ma = 1;

	rep(i, 0, n - 1){

		if (dp[i].first >= ma) mark = i, ma = dp[i].first;

	}

	vi ans;

	int cur = ma;

	rev(i, n-1 , 0){

		if (dp[i].first == cur){

			if (ans.empty()) {

				ans.push_back(dp[i].second); cur--; continue;

			}

			int tp = ans.back();

			int curr = dp[i].second;

			if (a[curr].first < a[tp].first && a[curr].second < a[tp].second){

				cur--; ans.push_back(curr);

			}

		}

	}

	cout << sz(ans) << "\n";

	reverse(all(ans));

	for (int x : ans) cout << x + 1 << " ";

}