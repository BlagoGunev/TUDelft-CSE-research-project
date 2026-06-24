#include<bits/stdc++.h>

using namespace std;

#pragma region Debugger

void __print(int x) {cerr << x;}

void __print(long x) {cerr << x;}

void __print(long long x) {cerr << x;}

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

 

template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

#else

#define debug(x...)

#endif

#pragma endregion Debugger

#define int long long

#define INF 1e18

#define MOD 1000000007 //1e9+7

#define mod 998244353

#define el '\n'

#define pb push_back

#define F first

#define S second

#define all(x) x.begin(), x.end()

#define mem1(a)           memset(a,-1,sizeof(a))

#define mem0(a)           memset(a,0,sizeof(a))

#define ppc               __builtin_popcount

#define ppcll             __builtin_popcountll

#define sz(x)             (int)((x).size())

#define ceil(x,y)         x/y + (x%y!=0)

#define sortall(x) sort(all(x))

#define PI 3.1415926535897932384626

#define rep(i,x,y)  for(int i = x;i<y;i++)

#define gsortall(x) sort(all(x),greater<int>())

void solve(){

    int n;cin>>n;

    int ans = 0;

    int s = 1;

    int x = 1;

    while(n-x>=0){

        n-=x;

        s = 2*s + 1;

        x = (s*(s+1))/2;

        ++ans;

    }

    cout<<ans<<el;

}

int32_t main(){

ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int t = 1;

cin>>t;

while(t--) solve();

return 0;

}