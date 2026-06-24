#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 69;
int seg[4 * N], lazy[4 * N];
int nn;

void updlz(int l, int r, int pos){
    seg[pos] += lazy[pos];
    if (l != r){
        lazy[pos * 2] += lazy[pos];
        lazy[pos * 2 + 1] += lazy[pos];
    }
    lazy[pos] = 0;
}

void upd(int l, int r, int pos, int ql, int qr, int x){
    if (lazy[pos]) updlz(l, r, pos);
    if (l >= ql && r <= qr){
        seg[pos] += x;
        if (l != r){
            lazy[pos * 2] += x;
            lazy[pos * 2 + 1] += x;
        }
    } else if (l > qr || r < ql){
        return;
    } else {
        int mid = (l + r) / 2;
        upd(l, mid, pos * 2, ql, qr, x);
        upd(mid + 1, r, pos * 2 + 1, ql, qr, x);
        
        seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
    }
}

int find(int l, int r, int pos){
    if (l == r) return l;
    
    int mid = (l + r) / 2;
    updlz(l, mid, pos * 2);
    updlz(mid + 1, r, pos * 2 + 1);
    
    if (seg[pos * 2] == 0) return find(l, mid, pos * 2);
    else if (seg[pos * 2 + 1] == 0) return find(mid + 1, r, pos * 2 + 1);
    else return nn + 1;
}

void Solve() 
{
    // start from 1, go to next occurence
    // the things in between make you extend the array more 
    // keep extending while you can, when you can't over for you 
    // you died at [1, x] 
    // now remove something from this prefix and replace such that it lasts us the longest time 
    // potential suspects of a bad interval are : [s, ...., e] where both f[s] = f[e] = 2 
    // next occur
    // [l, r] is good when i exists such that prv[i] < l and nx[i] > r 
    // [l, r] is bad when no such i exists 
    // i.e. for all people with prv[i] < l, nx[i] <= r holds 
    // sweepline on l, maintaining set of prv[i] < l, then check for prefix of such a set whether max(nx[pref]) < next guy 
    // changing element is essentially setting nx[pv[i]] = nx[i], pv[nx[i]] = pv[i]
    
    // define dp[i] = minimum number of changes such that i is a changing spot 
    // if (l, r) is good and r = maximum r such that good for l, dp[r + 1] = dp[l - 1] + 1
    // how to find this???
    // we want to find min.r such that [l, r] is bad for all l 
    // use 2 pointers  : does r only increase????
    // but suppose a[l] was distinct and it causes decrease in r? 
    // possible
    // we need to find minimum r such that [l, r] is bad 
    // only consider i s.t. pv[i] < l 
    // then if (i <= r) r = max(r, nx[i])
    // r ends up being such that max(nx[pref]) < other i 
    // increasing l : removes (l - 1) and maybe adds something more 
    // store a list of i, and the corresponding max(nx[pref])???
    // lets go down the other lane 
    // l, r satisfying pv[i] < l <= i and i <= r < nx[i] 
    // so when l enters interval, range add 1 to all r satisfying i <= r < nx[i] 
    // then its first 0 
    
    int n; cin >> n;
    nn = n;
    
    for (int i = 1; i <= 4 * n; i++){
        seg[i] = 0;
        lazy[i] = 0;
    }
    
    vector <int> a(n + 1);
    vector<vector<int>> b(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    
    vector <int> pv(n + 1, 0), nx(n + 1, n + 1);
    for (int i = 1; i <= n; i++){
        int sz = b[i].size();
        for (int j = 1; j < sz; j++){
            pv[b[i][j]] = b[i][j - 1];
            nx[b[i][j - 1]] = b[i][j];
        }
    }
    
    struct ok{
        int l, r, x;
    };
    
    vector<vector<ok>> c(n + 2);
    for (int i = 1; i <= n; i++){
        c[pv[i] + 1].push_back({i, nx[i] - 1, +1});
        c[i + 1].push_back({i, nx[i] - 1, -1});
    }
    
    vector<int> r(n + 1, n + 1);
    
    for (int i = 1; i <= n; i++){
        for (auto [l, r, x] : c[i]){
            upd(1, n, 1, l, r, x);
        }
        
        r[i] = find(1, n, 1);
        upd(1, n, 1, i, i, +1);
    }
    
    // (l, r) is good iff r[i] for all l <= i <= r is > r
    // use 2 pointers
    
    vector <int> limit(n + 1);
    multiset <int> rr; // stores values of r[i] 
    int p = 0;
    
    for (int i = 1; i <= n; i++){
        // can we extend to p + 1
        auto check = [&](int x){
            if (!rr.size()) return true;
            int mn = *(rr.begin());
            return mn > x;
        };
        
        while (p != n && check(p + 1)){
            p++;
            rr.insert(r[p]);
        }
        
        limit[i] = p;
        rr.erase(rr.find(r[i]));
    }
    
    vector <int> dp(n + 2, INF);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++){
        int go = limit[i] + 1;
        dp[i - 1] = min(dp[i - 1], dp[i]);
        dp[go] = min(dp[go], dp[i - 1] + 1);
    }
    
    cout << dp[n + 1] - 1 << "\n";
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