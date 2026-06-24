#include <bits/stdc++.h>



using namespace std;

#define Karim53  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



void bomtakh() {

    Karim53

#ifdef gamed

    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#endif

}



typedef long long ll;

typedef unsigned long long ull;

#define yes cout<<"YES\n";

#define no cout<<"NO\n";

#define fi first

#define se second

#define pb push_back

#define All(x) (x).begin(),(x).end()

int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};

int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};



const ll N = 1e4 + 5;

int n, m, g, r;

int a[N];

int dis[N][1000];



void bfs() {

    for (auto &di: dis) {

        for (int &j: di) {

            j = 1e9;

        }

    }

    deque<pair<int, int>> dq;

    dq.emplace_back(0, 0);

    dis[0][0] = 0;

    while (!dq.empty()) {

        int v = dq.front().fi, t = dq.front().se;

        dq.pop_front();

        if (v) {

            int tot = a[v] - a[v - 1] + t % (r + g);

            if (tot <= g) {

                int ndis = a[v] - a[v - 1] + t, wait = 0;

                if (tot == g) wait = r;

                if (ndis + wait < dis[v - 1][(ndis + wait) % (r + g)]) {

                    dis[v - 1][(ndis + wait) % (r + g)] = ndis + wait;

                    if (wait) {

                        dq.emplace_back(v - 1, ndis + wait);

                    } else

                        dq.emplace_front(v - 1, ndis);

                }

            }

        }

        if (v < m - 1) {

            int tot = a[v + 1] - a[v] + t % (r + g);

            if (tot <= g) {

                int ndis = a[v + 1] - a[v] + t, wait = 0;

                if (tot == g) wait = r;

                if (ndis + wait < dis[v + 1][(ndis + wait) % (r + g)]) {

                    dis[v + 1][(ndis + wait) % (r + g)] = ndis + wait;

                    if (wait) {

                        dq.emplace_back(v + 1, ndis + wait);

                    } else

                        dq.emplace_front(v + 1, ndis);

                }

            }

        }

    }

    int ans = dis[m - 1][0] - r;

    for (int i = 0; i < g; ++i) {

        ans = min(ans, dis[m - 1][i]);

    }

    if (ans > 1e8)

        cout << -1;

    else

        cout << ans;

}



void solve() {

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {

        cin >> a[i];

    }

    sort(a, a + m);

    cin >> g >> r;

    bfs();

}





int main() {

    bomtakh();

    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

}