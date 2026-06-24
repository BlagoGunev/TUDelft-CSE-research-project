#include <bits/stdc++.h>

#include <unistd.h>

using namespace std;

using graph = vector<vector<int>>;

using v_i = vector<int>;

using v_b = vector<bool>;

using pii = pair<int,int>;

using ll = int64_t;



const int inf = 1e9;

const int mod = 1e9 + 7;



struct wedge{

    int u,v,ind;

    int64_t w;

};



using wgraph = vector<vector<wedge>>;

using item = pair<int64_t,int>;



void heap_prim(const wgraph &g,int start,vector<int64_t> &d,int64_t &ans,vector<pii> &path) {

    set<item> pq;

    d[start] = 0;

    pq.insert({d[start],start});

    while(!pq.empty()) {

        int u = pq.begin()->second;

        pq.erase(pq.begin());

        for(wedge w1: g[u]) {

            int to = w1.v;

            ll len = w1.w;

            if(len < d[to]) {

                pq.erase(make_pair(d[to],to));

                d[to] = len;

                pq.insert({d[to],to});

            }

        }

    }

}



struct dsu {

    vector<int> leader;

    vector<int> size;



    dsu(int n) {

        leader.resize(n);

        for(int i = 0;i < n;i++) leader[i] = i;

        size.resize(n,1);

    }

    int find(int u) {

        if (leader[u] == u) {

            return u;

        }

        int v = find(leader[u]);

        leader[u] = v;

        return v;

    }



    void join(int u,int v) {

        int lead_u = find(u);

        int lead_v = find(v);

        if(size[lead_u] > size[lead_v]) {

            leader[lead_v] = lead_u;

            size[lead_u] += size[lead_v];

        } else {

            leader[lead_u] = lead_v;

            size[lead_v] += size[lead_u];

        }

    }

};



bool cmp_wedge(wedge a,wedge b) {

    return a.w < b.w;

}



bool dfs_kuhn(const graph &g,int u,vector<int> &matching, vector<bool> &visited) {

    if(visited[u]) {

        return false;

    }

    visited[u] = true;

    for(int v:g[u]) {

        if(matching[v] == -1 || dfs_kuhn(g,matching[v],matching,visited)) {

            matching[v] = u;

            return true;

        }

    }

    return false;

}



void solve() {

    ll n;

    cin >> n;

    ll c = (2 * n) * (2 * n);

    ll k = c / n;

    if (n % 2 == 0) {

        cout << k - n << " " << k + n << " ";

        for (int i = 2;i < n;i+=2) {

            cout << k - i / 2 << " " << k + i / 2 << " ";

        }

    } else {

        cout << k - n << " " << k + n << " " << k << " ";

        for (int i = 3;i < n;i+=2) cout << k - (i + 1) / 2 << " " << k + (i + 1) / 2 << " ";

    }

    cout << "\n";

}



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    //string input;

    int t = 1;

    cin >> t;

    //getline(cin,input);

    //t = stoi(input);

    for (int i = 1;i <= t;i++) {

        //cout << "Game " << i << "\n";

        solve();

    }

    return 0;

}