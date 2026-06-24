#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef tuple<ll,ll,ll> tll;

class DSU{
    private:
        vector<int> link;
        vector<int> size;
 
    public:
    DSU(int n){
        link.resize(n);
        size.resize(n);
        for(int i = 0; i < n ; i++) link[i] = i;
        for(int i = 0; i < n ; i++) size[i] = 1;
    }
 
    int find(int x){
        while(x != link[x]) x = link[x];
        return x;
    }
 
    bool same(int a, int b){ return find(a) == find(b); }
 
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(size[a] < size[b]) swap(a,b);
        size[a] += size[b];
        link[b] = a;
    }
};

ll mstCost(vector<tll> &edges, const ll &n, const ll &c, const int &mask){
    DSU uf(n);
    ll cnt = 0, cost = __builtin_popcount(mask)*c;
    for(auto [w,a,b] : edges){
        if(uf.same(a, b) || (mask&((1<<a)|(1<<b))) == 0)
            continue;
        uf.unite(a, b);
        cost += w;
        cnt++;
    }
    if(cnt < n-1)
        return 1e9;
    return cost;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n,c; cin >> n >> c;
    vector<tll> edges;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ll x; cin >> x;
            if(x)
                edges.emplace_back(x,i,j);
        }
    }
    sort(edges.begin(),edges.end());
    ll ans = 1e9;
    for(int i = 0 ; i < (1<<n) ; i++){
        ans = min(ans,mstCost(edges, n, c, i));
    }
    cout << ans << '\n';
}