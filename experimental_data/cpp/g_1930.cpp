#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define log(x) (63^__bulitin_clzll(x))
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
int mod = 998244353;

int add(int x, int y) {
    x += y;
    if(x < 0) x += mod;
    return x % mod;
}


struct sgtree {

    struct Node {
        int value = 0, left = -1, right = -1, lx, rx, len, mid;
        Node(int a, int b) {
            lx = a, rx = b;
            len = rx - lx + 1;
            mid = (lx + rx) / 2;
        }
    };

    vector<Node> st;
    sgtree(int sz) {
        st.clear();
        st.push_back(Node(0, sz));
    }

    void create(int node) {
        if(st[node].left != -1) return;
        st.push_back(Node(st[node].lx, st[node].mid));
        st[node].left = st.size() - 1;
        st.push_back(Node(st[node].mid + 1, st[node].rx));
        st[node].right = st.size() - 1;
    }

    void update(int l, int r, int val, int node = 0) {
        if(st[node].lx > r || st[node].rx < l) return;
        if(st[node].lx >= l && st[node].rx <= r) {
            st[node].value = add(st[node].value, val);
            return;
        }
        create(node);
        update(l, r, val, st[node].left);
        update(l, r, val, st[node].right);
    }

    int get(int i, int node = 0) {
        if(node == -1) return 0;
        if(st[node].lx == st[node].rx) return st[node].value;
        if(st[node].mid >= i) return add(st[node].value, get(i, st[node].left));
        else return add(st[node].value, get(i, st[node].right));
    }

};

void solve() {
    int n;
    cin >> n;
    vector<int> u(n), v(n);
    vector<vector<int>> adj(n);

    for(int i = 0; i < n - 1; ++i) {
        cin >> u[i] >> v[i];
        --u[i], --v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    vector<int> maxPath(n, 0), maxSub(n, 0), par(n, 0);
    iota(maxSub.begin(), maxSub.end(), 0);

    function<void(int, int)> dfs = [&](int node, int p) {
        par[node] = p;
        maxPath[node] = max(node, maxPath[p]);

        for(auto &next : adj[node]) {
            if(next == p) {
                swap(next, adj[node].back());
                adj[node].pop_back();
                break;
            }
        }

        for(auto next : adj[node]) {
            dfs(next, node);
            maxSub[node] = max(maxSub[node], maxSub[next]);
        }

        sort(adj[node].begin(), adj[node].end(), 
            [&](int u, int v) {
                return maxSub[u] < maxSub[v];          
            }    
        );
    };
    dfs(0, 0);

    vector<int> head(n), in(n), out(n);
    iota(head.begin(), head.end(), 0);
    int timer = 0;

    function<void(int)> calc = [&](int node) {
        in[node] = timer++;
        for(auto next : adj[node]) {
            if(next == adj[node].back()) head[next] = head[node];
            calc(next);
        }
        out[node] = timer - 1;
    };
    calc(0);

    vector<int> dp(n, 0);
    sgtree st(n);

    dp[0] = 1;
    for(int node = 1; node < n; ++node) {
        if(maxPath[par[node]] > node) continue;
        dp[node] = dp[maxPath[par[node]]];
        int result = st.get(in[node]);
        dp[node] = add(dp[node], result);
        st.update(in[node], out[node], -result);

        if(maxSub[node] == node) {
            int curNode = node;
            curNode = par[head[curNode]];
            st.update(in[curNode], out[curNode], dp[node]);
        }
    }

    cout << dp[n - 1] << endl;
    return;
}   

main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) solve();

}

//chain : 1 4 2 3
//p : 1 3 2 4