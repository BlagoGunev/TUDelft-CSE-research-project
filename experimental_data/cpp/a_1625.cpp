// Duet of Dusk Embers--XrkArul

#include <bits/stdc++.h>

#include <ext/rope>

using namespace std;

using namespace __gnu_cxx;

#define ll long long

#define lll __int128_t

#define ull unsigned long long

#define vi vector<int>

#define vll vector<ll>

#define endl '\n'

#define ednl '\n'

#define pb push_back

#define fi first

#define se second

#define ls (p<<1)

#define rs (p<<1|1)

#define fix setprecision

#define all(v) (v).begin(),(v).end()

#define pii pair<int, int>

#define pll pair<ll, ll>

#define rep(i, a, b) for (int i = a; i <= b; ++i)

#define pq priority_queue<int, vector<int>>

#define PQ priority_queue<int, vector<int>, greater<int>>

const int inf = 2147483647;

const ll mod=1e9+7;

ll powmod(ll a,ll b){ll s=1;a%=mod;while(b){if(b&1)s=s*a%mod;b>>=1;a=a*a%mod;}return s%mod;}



//#define int long long

void solve(){

    int n,l;

    cin>>n>>l;

    vi qwq(n+1);

    vector<vi> cnt(32,vi(3));

    rep(i,1,n)cin>>qwq[i];

    rep(i,1,n){

        int a=qwq[i];

        for(int j=l-1;j>=0;j--){

            cnt[j][(a>>j)&1]++;

        }

    }  

    // cout<<(18&(1<<4))<<endl;

    int ans=0;

    // cout<<cnt[4][1]<<endl;

    for(int i=0;i<l;i++){

        ans+=(cnt[i][1]>cnt[i][0]?(1<<i):0);

    }

    cout<<ans<<endl;

}

signed main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int T=1;

    cin>>T;

    while(T--){

        solve();

    }

    return 0;

}

/*



*/