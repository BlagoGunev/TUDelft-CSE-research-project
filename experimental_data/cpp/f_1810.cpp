#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct segtree{
    struct node{
        int x = 0;
        int need = INF;
 
        void apply(int l, int r, int y, int z){
            x = y;
            need = z;
        }
    };
 
    int n;
    vector <node> seg;
 
    node unite(node a, node b){
        auto res = b;
        if (a.x >= b.need){
            res.x += 1;
            res.need = INF;
        } else if (a.x + 1 == b.need){
            res.need = a.need;
        } else {
            res.need = INF;
        }
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
    int n, m, q; cin >> n >> m >> q;
    
    const int K = 30;
    int lim = n + 1;
    
    while (lim % K != 0){
        lim++;
    }
    lim += K;
    
    vector <int> f(lim, 0);
    vector <int> a(n);
    multiset <int> ms;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        f[a[i]]++;
        ms.insert(a[i]);
    }

    segtree seg(lim / K);
    
    auto calc = [&](int i){
        int l = i * K;
        int r = (i + 1) * K - 1;

        int v = 0;
        for (int j = l; j <= r; j++){
            v = (v + m - 1) / m + f[j];
        }
        
        int need = v + 1;
        for (int j = r; j >= l; j--){
            need -= f[j];
            if ((need - 1) >= INF / m){
                need = INF;
                break;
            }
            need = (need - 1) * m + 1;
        }
        
        int v2 = need - 1;
        for (int j = l; j <= r; j++){
            v2 = (v2 + m - 1) / m + f[j];
        }
        
        assert(v2 == v);
        v2 = need;
        for (int j = l; j <= r; j++){
            v2 = (v2 + m - 1) / m + f[j];
        }
        assert(v2 != v || need == INF);

        seg.modify(i + 1, i + 1, v, need);
    };
    
    for (int i = 0; i < (lim / K); i++){
        calc(i);
    }
    
    while (q--){
        int p, x; cin >> p >> x;
        --p;
        
        f[a[p]]--;
        ms.erase(ms.find(a[p]));
        calc(a[p] / K);
        
        a[p] = x;
        
        f[a[p]]++;
        ms.insert(a[p]);
        calc(a[p] / K);
            
        int mx = *(--ms.end());
        int full = mx / K;
        int st = full * K;
    
        int dp = 0;
        if (full != 0){
            dp = seg.query(1, full).x;
        }
        for (int i = st; ; i++){
            dp = (dp + m - 1) / m + f[i];
            if (i >= mx && dp == 1){
                cout << i << "\n";
                break;
            }
            assert(i < lim);
        }
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
    
    cin >> t;
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