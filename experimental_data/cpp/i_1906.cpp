#include <bits/stdc++.h>
using namespace std;
const int S = 100005;
vector<int> g[S];
int dst[S], l[S], r[S], chk[S];
void clear() { for(int i=0;i<S;i++) g[i].clear();}
void addEdge(int s, int e) { g[s].push_back(e); }
int bfs(int n) {
    queue<int> q; int ret = 0;
    memset(dst, 0, sizeof dst);
    for(int i=1; i<=n;i++) if(l[i] == -1 && !dst[i]) {
        q.push(i); dst[i] = 1;
    }
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto i : g[v]) {
            if(r[i] == -1) ret = 1;
            else if(!dst[r[i]]) dst[r[i]] = dst[v] + 1, q.push(r[i]);
        }
    }
    return ret;
}
int dfs(int v) {
    if(chk[v]) return 0; chk[v] = 1;
    for(auto i : g[v]) {
        if(r[i] == -1 || !chk[r[i]] && dst[r[i]] == dst[v] + 1 && dfs(r[i])) {
            l[v] = i; r[i] = v; return 1;
        }
    }
    return 0;
}
int match(int n) {
    memset(l, -1, sizeof l); memset(r, -1, sizeof r);
    int ret = 0;
    while(bfs(n)) {
        memset(chk, 0, sizeof chk);
        for(int i=1;i<=n;i++) if(l[i] == -1 && dfs(i)) ret++;
    }
    return ret;
}
struct UnionFind {
    vector<int> root;
    UnionFind(int N) {
        root.resize(N);
        fill(root.begin(),root.end(),-1);
    }
    int Find(int n) {
        if(root[n]<0) return n;
        int r = Find(root[n]);
        root[n] = r;
        return r;
    }
    void Merge(int x, int y) {
        x = Find(x), y = Find(y);
        if(x==y) return;
        if(root[x]>root[y]) swap(x, y);
        root[x] += root[y];
        root[y] = x;
    }
};
array<int, 2> chain[100005];
array<int, 2> Edge[100005];
int ord[100005];
vector<int> adj[100005];
signed main() {
    //cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    int N;
    cin >> N;
    for(i=0;i<N-1;i++) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
        Edge[i] = {a, b};
    }
    int v = match(N+1);
    UnionFind UF(N+1);
    for(i=1;i<=N;i++) {
        if(l[i] != -1) UF.Merge(i, l[i]);
    }
    for(i=1;i<=N;i++) chain[i] = {-1,-1};
    int cnt = 0;
    for(i=1;i<=N;i++) {
        if(r[i] != -1) continue;
        int c = i;
        while(l[c] != -1) c = l[c];
        chain[UF.Find(i)] = {i, c};
        cnt++;
    }
    for(i=0;i<N-1;i++) {
        int a = Edge[i][0], b = Edge[i][1];
        if(UF.Find(a) != UF.Find(b)) {
            int ua = UF.Find(a), ub = UF.Find(b);
            ord[ub]++;
            adj[ua].push_back(ub);
        }
    }
    vector<int> vec;
    queue<int> q;
    for(i=1;i<=N;i++) {
        if(i == UF.Find(i) && ord[i] == 0) q.push(i);
    }
    /*for(i=1;i<=N;i++) {
        cout << i << " : ";
        for(int n : adj[i]) cout << n << ' ';
        cout << '\n';
    }*/
    while(!q.empty()) {
        int c = q.front();
        q.pop();
        vec.push_back(c);
        for(int n : adj[c]) {
            ord[n]--;
            if(ord[n] == 0) q.push(n);
        }
    }
    assert(vec.size() == cnt);
    cout << vec.size()-1 << '\n';
    for(i=0;i+1<vec.size();i++) cout << chain[vec[i]][1] << ' ' << chain[vec[i+1]][0] << '\n';
    //cout << chain.size() - 1 << '\n';
    //for(i=0;i+1<chain.size();i++) cout << chain[i][1] << ' ' << chain[i+1][0] << '\n';
}