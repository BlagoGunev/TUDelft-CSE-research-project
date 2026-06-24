#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static const int MAXN = 300000;

struct Fenwick {
    int n;
    vector<long long> fenw;
    Fenwick(int n) : n(n), fenw(n+1,0LL) {}
    void update(int i, long long delta) {
        for(; i<=n; i+=(i & -i)) {
            fenw[i] += delta;
        }
    }
    long long query(int i) const {
        long long s = 0;
        for(; i>0; i-=(i & -i)) {
            s += fenw[i];
        }
        return s;
    }
    long long rangeSum(int L, int R) const {
        if(R<L) return 0LL;
        return query(R) - query(L-1);
    }
};

vector<int> adj[MAXN+1];
int inT[MAXN+1], outT[MAXN+1], eulerList[MAXN+1];
int depthArr[MAXN+1], subSize[MAXN+1];
int timer;

void dfs(int u, int parent, int depth) {
    depthArr[u] = depth;
    subSize[u] = 1;
    inT[u] = ++timer;
    eulerList[timer] = u;
    for(auto &nx : adj[u]){
        if(nx==parent) continue;
        dfs(nx,u,depth+1);
        subSize[u] += subSize[nx];
    }
    outT[u] = timer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        for(int i=1;i< n;i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(n==1){
            cout << 0 << "\n";
            continue;
        }
        timer=0;
        dfs(1,-1,0);

        long long Tdist=0;
        static int par[MAXN+1];
        {
            queue<int>q;
            q.push(1);
            par[1] = -1;
            vector<bool> visited(n+1,false);
            visited[1]=true;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(auto &nx : adj[u]){
                    if(!visited[nx]){
                        visited[nx]=true;
                        par[nx]=u;
                        q.push(nx);
                    }
                }
            }
        }
        for(int v=2; v<=n; v++){
            int p = par[v];
            long long s = subSize[v];
            Tdist += s*( (long long)n - s );
        }

        vector<int> D(n);
        for(int i=1;i<=n;i++){
            D[i-1] = depthArr[i];
        }
        sort(D.begin(), D.end());
        long long prefix=0LL, TdepthAbs=0LL;
        for(int j=0; j<n; j++){
            TdepthAbs += (long long)D[j]* j - prefix;
            prefix += D[j];
        }

        Fenwick fenw(n); 
        vector<long long> countOfGreater(n+1,0LL), countOfLess(n+1,0LL);

        {
            fenw = Fenwick(n); 
            int p = n;
            for(int u=n; u>=1; u--){
                while(p>u){
                    int idxIn = inT[p];
                    fenw.update(idxIn, 1LL);
                    p--;
                }
                long long cnt = fenw.rangeSum(inT[u], outT[u]);
                countOfGreater[u] = cnt;
            }
        }

        {
            fenw = Fenwick(n);
            int p = 1;
            for(int u=1; u<=n; u++){
                while(p< u){
                    int idxIn = inT[p];
                    fenw.update(idxIn, 1LL);
                    p++;
                }
                long long cnt = fenw.rangeSum(inT[u], outT[u]);
                countOfLess[u] = cnt;
            }
        }

        long long badPairs=0LL;
        for(int u=1; u<=n; u++){
            badPairs += countOfGreater[u];
            badPairs += countOfLess[u];
        }

        long long nC2 = (long long)n*(n-1)/2;
        long long sumG = Tdist - TdepthAbs - nC2;
        long long ans = sumG + badPairs;
        cout << ans << "\n";
    }
    return 0;
}