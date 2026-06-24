#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;



#define int long long 

#define ld  long double

#define vi vector<int>

#define vpi vector<pair<int,int>>

#define vvi vector<vector<int>>

#define ss second 

#define ff first

#define inf (int)1e18

#define rz resize

#define pii pair<int,int>

#define rep(i,a,b) for(int i=a;i<b;i++)

#define pb push_back

#define all(x) x.begin(),x.end()





template<typename T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>

using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ook order_of_key

#define fbo find_by_order



void __print(int x) {cerr << x;}

void __print(long x) {cerr << x;}

void __print(unsigned x) {cerr << x;}

void __print(unsigned long x) {cerr << x;}

void __print(unsigned long long x) {cerr << x;}

void __print(float x) {cerr << x;}

void __print(double x) {cerr << x;}

void __print(long double x) {cerr << x;}

void __print(char x) {cerr << '\'' << x << '\'';}

void __print(const char *x) {cerr << '\"' << x << '\"';}

void __print(const string &x) {cerr << '\"' << x << '\"';}

void __print(bool x) {cerr << (x ? "true" : "false");}



#ifndef ONLINE_JUDGE

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)

#else

#define dbg(x...)

#endif

 

template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

template <typename T1, typename T2>

istream &operator>>(istream &istream, pair<T1, T2> &p){return (istream >> p.first >> p.second);}

template <typename T>

istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}

template <typename T1, typename T2> 

ostream &operator<<(ostream &ostream, const pair<T1, T2> &p){return (ostream << p.first << " " << p.second);}

template <typename T> 

ostream &operator<<(ostream &ostream, const vector<T> &c){for (auto &it : c)cout << it << " ";return ostream;}

template <typename T>void print(T &&t) { cout << t << "\n"; }

template <typename T, typename... Args>void print(T &&t, Args &&...args){cout << t << " ";print(forward<Args>(args)...);}

template <typename T> int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }



const ld PI = 3.141592653589793238;

const int mod_9= 998244353;

const int mod=1e9+7;

const int N=3e5+10;

const ld eps=1e-11;

const int lim=505;







void solve(){

    

    int n,k;

    cin >> n >> k; 

    

    string s;

    cin >> s;

    

    vi pref(n+1);

    for(int i=0;i<n;i++){

        pref[i+1]=pref[i]+(s[i]=='1');

    } 

    

    dbg(pref);

    vi dp(n+1);

    int ans=pref[n];

    

    for(int i=1;i<=n;i++){

        int cost=(s[i-1]=='1'?0:1);

        dp[i]=cost+pref[i-1]; // starting range from this index

        if(i>=k){

            dp[i]=min(dp[i],cost+dp[i-k]+pref[i-1]-pref[i-k]); // using previous garland 

        }

        ans=min(ans,dp[i]+pref[n]-pref[i]);

    } 

    

    cout << ans << '\n';

 

 

         

}

 

int32_t main(){

    

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL); 

    



   

    int t=1;

    cin >> t;

    while(t--){

        solve();

    }

    

    

    return 0;

}