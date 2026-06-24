#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp> 

#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

using namespace std;

#define getbit(n, i) (((n) & (1LL << (i))) != 0) 

#define setbit0(n, i) ((n) & (~(1LL << (i)))) 

#define setbit1(n, i) ((n) | (1LL << (i))) 

#define togglebit(n, i) ((n) ^ (1LL << (i))) 

#define lastone(n) ((n) & (-(n))) 

char gap = 32;

#define int long long

#define ll long long 

#define lll __int128_t

#define pb push_back

typedef tree<

int,

null_type,

less<int>,

rb_tree_tag,

tree_order_statistics_node_update>

ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll hashPrime = 1610612741;

vector<int> adj[200005];

void solve() {

    int n, m, a, b, c;

    cin >> n >> m >> a >> b >> c;

    int p[m + 1];

    p[0] = 0;

    for(int i = 1; i <= m; i++) cin >> p[i];

    sort(p + 1, p + m + 1);

    for(int i = 2; i <= m; i++) p[i] += p[i - 1];

    for(int i = 1; i <= n; i++) adj[i].clear();

    for(int i = 1; i <= m; i++) {

        int u, v; cin >> u >> v;

        adj[u].push_back(v);

        adj[v].push_back(u);

    }



    vector<int> vis1(n + 1, 0), vis2(n + 1, 0), vis3(n + 1, 0);



    queue<int> q;

    q.push(a);

    vis1[a] = 1;

    while(!q.empty()) {

        int temp = q.front();

        q.pop();

        for(auto x: adj[temp]) {

            if(vis1[x]) continue;

            vis1[x] = vis1[temp] + 1;

            q.push(x);

        }

    }



    q.push(b);

    vis2[b] = 1;



    while(!q.empty()) {

        int temp = q.front();

        q.pop();

        for(auto x: adj[temp]) {

            if(vis2[x]) continue;

            vis2[x] = vis2[temp] + 1;

            q.push(x);

        }

    }



    q.push(c);

    vis3[c] = 1;



    while(!q.empty()) {

        int temp = q.front();

        q.pop();

        for(auto x: adj[temp]) {

            if(vis3[x]) continue;

            vis3[x] = vis3[temp] + 1;

            q.push(x);

        }

    }



    int minans = LONG_LONG_MAX;



    for(int i = 1; i <= n; i++) {

        int temp1 = vis1[i] - 1;

        int temp2 = vis2[i] - 1;

        int temp3 = vis3[i] - 1;



        if(temp1 + temp2 + temp3 <= m) {

            minans = min(minans, p[temp1 + temp2 + temp3] + p[temp2]);

        }

    }



    cout << minans << "\n";

}

signed main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t; cin >> t;

    while(t--) {

        solve();

    }

    return 0;

}