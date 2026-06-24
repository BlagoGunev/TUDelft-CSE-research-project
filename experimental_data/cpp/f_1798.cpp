#include <bits/stdc++.h>

#define sz(a) ((int)((a).size()))
#define all(x) (x).begin(),(x).end()

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
ll n, m, k, q, x, y, z;
const ll MOD = 1e9+7; //998244353
vector<ll> a;
ll u, M;
vector<ll> v;
int dp[203][203][203];
tuple<int, int, int, int> p[203][203][203];

bool dfs(int i, int j, int r) {
    if(j == M) {
        if(r == 0) return 1;
        return 0;
    }
    if(i == u) return 0;
    if(dp[i][j][r] != -1) return dp[i][j][r];
    int v1 = dfs(i+1, j, r);
    int v2 = dfs(i+1, j+1, (r+a[v[i]])%M);
    if(v1) {
        p[i][j][r] = {i+1, j, r, 0};
    } else if(v2) {
        p[i][j][r] = {i+1, j+1, (r+a[v[i]])%M, 1};
    }
    return dp[i][j][r] = max({v1, v2, 0});
}

int solve() {
    cin>>n>>k;
    a.resize(n);
    vector<pair<ll, int>> s(k);
    for(ll &v: a) cin>>v;
    for(int i = 0; i < k; ++i) {
        cin>>x;
        s[i] = {x, i};
    }
    sort(all(s));
    vector<vector<ll>> ans(k);
    vector<bool> taken(n, false);
    for(int i = 0; i < k-1; ++i) {
        v.clear();
        u = 0;
        M = s[i].first;
        for(int j = 0; j < n; ++j) {
            if(!taken[j]) {
                v.push_back(j);
                u++;
            }
            if(u == 2*M-1) break;
        }
        for(int i = 0; i <= u; ++i) {
            for(int j = 0; j <= M; ++j) {
                for(int k = 0; k <= M; ++k) {
                    dp[i][j][k] = -1;
                    p[i][j][k] = {-1, -1, -1, -1};
                }
            }
        }
        dfs(0, 0, 0);
        int j = 0, k = 0, r = 0, take = 0;
        while(true) {
            auto pa = p[j][k][r];
            auto [jj, kk, rr, take] = pa;
            if(jj == -1) break;
            if(take) {
                ans[s[i].second].push_back(a[v[j]]);
                taken[v[j]] = true;
            }
            j = jj, k = kk, r = rr;
        }
    }
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        if(!taken[i]) {
            sum += a[i];
            ans[s[k-1].second].push_back(a[i]);
        }
    }
    ll m = s[k-1].first;
    sum = m - sum%m;
    ans[s[k-1].second].push_back(sum);
    cout<<sum<<'\n';
    for(int i = 0; i < k; ++i) {
        for(ll t: ans[i]) cout<<t<<" ";
        cout<<'\n';
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TT = 1;
    for (int tc = 1; tc <= TT; ++tc) {
        if (solve()) {
            break;
        }
        #ifdef MAYANK_LAPTOP
            cout<<"============================"<<endl;
        #endif
    }
    #ifdef MAYANK_LAPTOP
        cerr<<endl<<"Completed in "<<clock()*1.0/CLOCKS_PER_SEC<<" sec"<<endl;
    #endif
    return 0;
}