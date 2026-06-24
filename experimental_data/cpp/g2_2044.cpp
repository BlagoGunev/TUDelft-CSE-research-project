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
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1);
    vector<array<int, 20>> t(n + 1);
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        t[i][0] = r;
        g[r].push_back(i);
        g[i].push_back(r);
        d[r]++;
        d[i]++;
    }
    for (int b = 1; b < t[0].size(); b++) {
        for (int i = 1; i <= n; i++) {
            t[i][b] = t[t[i][b - 1]][b - 1];
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (--d[v] == 1) q.push(v);
        }
    }
    vector<int> f(n + 1);
    int h = 0;
    vector<vector<int>> cycle;
    for (int i = 1; i <= n; i++) {
        if (f[i]) continue;
        if (d[i] > 1) {
            vector<int> ord;
            int now = i;
            while (!f[now]) {
                f[now] = 1;
                ord.push_back(now);
                for (int v : g[now]) {
                    if (!f[v] && d[v] > 1) now = v;
                }
            }
            for (int u : ord) {
                int num = 0;
                function<void(int, int)> dfs = [&](int u, int f) -> void {
                    for (int v : g[u]) {
                        if (v == f) continue;
                        dfs(v, u);
                    }
                    num++;
                };
                for (int v : g[u]) {
                    if (d[v] == 1) {
                        num = 0;
                        dfs(v, u);
                        h = max(h, num);
                    }
                }
            }
            cycle.push_back(ord);
        }
    }
    
    cout << h + 2 << endl;
    
    /*
    
    vector<int> cnt(n + 1);
    auto jump = [&](int u, int k) -> int {
        for (int i = t[u].size() - 1; i >= 0; i--) {
            if (k >> i & 1) u = t[u][i];
        }
        return u;
    };
    for (int i = 1; i <= n; i++) cnt[jump(i, h)]++;
    */
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