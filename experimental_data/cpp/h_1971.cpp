#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define no do { cout << "No" << endl; return; } while(0)
#define yes do { cout << "Yes" << endl; return; } while (0)
#define lowbit(x) ((x) & -(x))

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

template<typename T> ostream & operator << (ostream &out,const set<T>&obj){out<<"set(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<*it;out<<")";return out;}
template<typename T1,typename T2> ostream & operator << (ostream &out,const map<T1,T2>&obj){out<<"map(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<it->first<<": "<<it->second;out<<")";return out;}
template<typename T1,typename T2> ostream & operator << (ostream &out,const pair<T1,T2>&obj){out<<"<"<<obj.first<<", "<<obj.second<<">";return out;}
template<typename T> ostream & operator << (ostream &out,const vector<T>&obj){out<<"vector(";for(auto it=obj.begin();it!=obj.end();it++) out<<(it==obj.begin()?"":", ")<<*it;out<<")";return out;}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> l(n + 1), r(n + 1);
    vector<vector<int>> a(3 + 1, vector<int>(n + 1));
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            int v;
            cin >> v;
            if (v < 0) {
                l[-v].push_back(j);
            } else {
                r[v].push_back(j);
            }
            a[i][j] = v;
        }
    }
    vector<vector<int>> g(n * 2 + 1);
    auto add = [&](int u, int v) -> void {
        g[u].push_back(v);
    };
    auto x = [&](int u) -> int {
        return u * 2 - 1;
    };
    auto y = [&](int u) -> int {
        return u * 2;
    };
    auto add2 = [&](int s, int t) -> void {
        if (t < 0) {
            add(s, x(-t));
        } else {
            add(s, y(t));
        }
    };
    for (int i = 1; i <= n; i++) {
        for (int j : r[i]) { //-1
            for (int k = 1; k <= 3; k++) {
                if (a[k][j] == i) {
                    for (int k2 = 1; k2 <= 3; k2++) {
                        if (k != k2) add2(x(i), a[k2][j]);
                    }
                    break;
                }
            }
        }
        
        for (int j : l[i]) { //1
            for (int k = 1; k <= 3; k++) {
                if (a[k][j] == -i) {
                    for (int k2 = 1; k2 <= 3; k2++) {
                        if (k != k2) add2(y(i), a[k2][j]);
                    }
                    break;
                }
            }
        }
    }
    vector<vector<int>> vg(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++) {
        for (int v : g[i]) {
            vg[v].push_back(i);
        }
    }
    vector<int> vis(n * 2 + 1), seq;
    function<void(int)> dfs1 = [&](int u) -> void {
        if (vis[u]) return;
        vis[u] = 1;
        for (int v : vg[u]) dfs1(v);
        seq.push_back(u);
    };
    for (int i = 1; i <= n * 2; i++) dfs1(i);
    
    vector<int> scc(n * 2 + 1);
    function<void(int, int)> dfs2 = [&](int u, int c) -> void {
        if (scc[u]) return;
        scc[u] = c;
        for (int v : g[u]) dfs2(v, c);
    };
    for (int i = n * 2 - 1; i >= 0; i--) dfs2(seq[i], seq[i]);
    
    for (int i = 1; i <= n; i++) {
        if (scc[x(i)] == scc[y(i)]) no;
    }
    yes;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
	cin >> t;
    
    while (t--) {
    	solve(); 
	}
}