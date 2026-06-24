#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct segtree{
    struct node{
        int x = 0;
 
        void apply(int l, int r, int y){
            x = y;
        }
    };
 
    int n;
    vector <node> seg;
 
    node unite(node a, node b){
        node res;
        res.x = a.x + b.x;
        return res;
    }
 
    void push(int l, int r, int pos){
        
    }
 
    void pull(int pos){
        seg[pos] = unite(seg[pos * 2], seg[pos * 2 + 1]);
    }
 
    void build(int l, int r, int pos){
        if (l == r){
            return;
        }
 
        int mid = (l + r) / 2;
        build(l, mid, pos * 2);
        build(mid + 1, r, pos * 2 + 1);
        pull(pos);
    }
 
    template<typename M>
    void build(int l, int r, int pos, vector<M> &v){
        if (l == r){
            seg[pos].apply(l, r, v[l]);
            return;
        }
 
        int mid = (l + r) / 2;
        build(l, mid, pos * 2, v);
        build(mid + 1, r, pos * 2 + 1, v);
        pull(pos);
    }
 
    node query(int l, int r, int pos, int ql, int qr){
        push(l, r, pos);
        if (l >= ql && r <= qr){
            return seg[pos];
        }
        
        int mid = (l + r) / 2;
        node res{};
        if (qr <= mid) res = query(l, mid, pos * 2, ql, qr);
        else if (ql > mid) res = query(mid + 1, r, pos * 2 + 1, ql, qr);
        else res = unite(query(l, mid, pos * 2, ql, qr), query(mid + 1, r, pos * 2 + 1, ql, qr));
        
        pull(pos);
        return res;
    }
 
    template <typename... M>
    void modify(int l, int r, int pos, int ql, int qr, M&... v){
        push(l, r, pos);
        if (l >= ql && r <= qr){
            seg[pos].apply(l, r, v...);
            return;
        }
 
        int mid = (l + r) / 2;
        if (ql <= mid) modify(l, mid, pos * 2, ql, qr, v...);
        if (qr > mid) modify(mid + 1, r, pos * 2 + 1, ql, qr, v...);
 
        pull(pos);
    }
 
    segtree (int _n){
        n = _n;
        seg.resize(4 * n + 1);
        build(1, n, 1);
    }
 
    template <typename M>
    segtree (int _n, vector<M> &v){
        n = _n;
        seg.resize(4 * n + 1);
        if (v.size() == n){
            v.insert(v.begin(), M());
        }
        build(1, n, 1, v);
    }
 
    node query(int l, int r){
        return query(1, n, 1, l, r);
    }
 
    node query(int x){
        return query(1, n, 1, x, x);
    }
 
    template <typename... M>
    void modify(int ql, int qr, M&...v){
        modify(1, n, 1, ql, qr, v...);
    }
};


void Solve() 
{
    int n, q; cin >> n >> q;
    
    vector <int> p(n);
    for (auto &x : p) cin >> x;
    
    segtree seg(n);
    
    long long sum = 0;
    long long inv = 0;
    
    for (auto x : p){
        inv += seg.query(x, n).x;
        int pp = 1;
        seg.modify(x, x, pp);
    }
    
    for (int i = 0; i < n; i++){
        sum += abs(p[i] - i - 1);
    }
    
    while (q--){
        int x, y; cin >> x >> y;
        x--; y--;
        sum -= abs(p[x] - x - 1);
        sum -= abs(p[y] - y - 1);
        
        int mn = min(p[x], p[y]);
        int mx = max(p[x], p[y]);
        
        int bw = 0;
        for (int i = x + 1; i < y; i++){
            bw += (p[i] > mn) && (p[i] < mx);
        }
        bw = 2 * bw + 1;
        
        if (p[x] > p[y]){
            inv -= bw;
        } else {
            inv += bw;
        }
        
        swap(p[x], p[y]);
        sum += abs(p[x] - x - 1);
        sum += abs(p[y] - y - 1);
        
        cout << (sum - inv) << "\n";
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
  //  cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}