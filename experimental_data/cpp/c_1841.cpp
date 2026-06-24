#include <bits/stdc++.h>

#ifdef LOCAL
#define debug(x) cerr << (#x) << ": " << x << endl
#else
#define debug(x) ;
#endif

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n)-1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define print_pvector(v)                                  \
    for (int i = 0; i < n; i++)                           \
    {                                                     \
        cout << v[i].first << " " << v[i].second << "\n"; \
    }
using namespace std;

//for ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template <typename T>
using vt = vector<T>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

mt19937 rnd(0);

const int BIG = 1e9, LG = 30;
const ll INF = 1e18;
ll pw(ll a ,ll b){
    if(b==0)return 1;
    ll res= pw(a,b/2);
    res*=res;
    return (b%2?a*res:res);
}
ll util(int ind,string &s,int mx,int changed,vector<vector<vector<ll>>> &dp){
    if(ind==-1)return 0;
    if(dp[ind][mx][changed]!=-1)return dp[ind][mx][changed];
    ll vl=(pw(10,s[ind]-'A')) * ((s[ind]-'A') < mx?-1:1);
    ll res=vl+util(ind-1,s,max(mx,s[ind]-'A'),changed,dp);
    if(!changed){
        for(int i=0;i<5;i++){
            ll nv=(pw(10,i)) *(i<mx?-1:1);
            res=max(res,nv+util(ind-1,s,max(mx,i),1,dp));
        }
    }
    return dp[ind][mx][changed]=res;
}
void solve(){
    string s;cin>>s;
    int n=s.size();
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(6,vector<ll>(2,-1)));
    cout<<util(n-1,s,0,0,dp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--){
        solve();
        cout<<"\n";
    }
    return 0;
}