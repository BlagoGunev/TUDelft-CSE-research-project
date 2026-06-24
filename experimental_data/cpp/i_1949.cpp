#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
// using vll = vector<pll>;
#define fi first
#define se second
#define sz(c)  ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, m, n)  for (int i = m, nnnn = (n); i < nnnn; ++i)
#define pb  push_back
#define mp  make_pair
#define NIL 0
#define int128 __int128_t

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif

const ll mod = 1000000007;

void solve(){
	int n;
    cin >> n;
    array<ll, 3> arr[n];
    forn(i, 0, n) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    vector<vector<int>> adj(n);
    forn(i, 0, n) {
        bool yes = true;
        forn(j, 0, n) {
            if (i == j) continue;
            ll dx = abs(arr[i][0] - arr[j][0]), dy = abs(arr[i][1] - arr[j][1]), r = arr[i][2] + arr[j][2];
            if (dx * dx + dy * dy == r * r) {
                adj[i].pb(j);
            }
        }
    }

    int vis[n];
    memset(vis, 0, sizeof(vis));
    function<void(int, int, int)> dfs;
    bool pos;
    int d1, d2;
    dfs = [&](int u, int p, int d) {
        if (d % 2 == 0) d1++;
        else d2 ++;
        for(auto v : adj[u]) {
            if (v == p) continue;
            if (vis[v] == 0) {
                if (vis[u] == 2) {
                    vis[v] = 1;
                } else {
                    vis[v] = 2;
                }
                dfs(v, u, d+1);
            } else if (vis[u] == vis[v]) {
                pos = false;
            }
        }
    };
    forn(i, 0, n) {
        if (vis[i] == 0) {
            pos = true;
            d1 = 0;
            d2 = 0;
            vis[i] = 1;
            dfs(i, i, 0);
            if (pos && d1 != d2) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;

    int t = 1;
    // cin >> t;
    forn (i, 0, t) {
        // std::cout << "Case #" << i+1 << ": ";
        solve();
		cout << '\n';
    }
}