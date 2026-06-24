#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



using namespace std;



//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

//

//using namespace __gnu_pbds;



#define sz(x) (int)(x).size()

#define int long long

#define FOR(i,l,r) for(int i=l;i<=(r);++i)

#define FORd(i,r,l) for(int i=r;i>=(l);--i)

#define pb push_back

#define f first

#define s second

#define lb lower_bound

#define ub upper_bound

#define all(x) x.begin(),x.end()

#define ins insert

//#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>



typedef long long ll;

typedef long double ld;

typedef unsigned long long ull;

typedef pair<int,int>pii;

typedef pair<ll,ll>pll;

typedef vector<ll>vll;

typedef vector<int>vi;

typedef vector<bool>vb;

typedef vector<vi>vvi;

typedef vector<vll>vvll;

typedef vector<pii>vpii;

typedef vector<pll>vpll;



const int N=5e5+55;

const int MOD=1e9+7;

const int INF=1e18;

const char nl='\n';



int n;

int t[N];



void upd(int pos,int val){

    while(pos<=n){

        t[pos]=max(t[pos],val);

        pos+=pos&-pos;

    }

}



int get(int pos){

    int res=-INF;

    while(pos){

        res=max(res,t[pos]);

        pos-=pos&-pos;

    }

    return res;

}



int a[N];

int pref[N];

int id[N];

int dp[N];



void solve(){

    cin>>n;

    vpii v;

    for(int i=1;i<=n;++i){

        cin>>a[i];

        pref[i]=pref[i-1]+a[i];

        v.pb({pref[i],-i});

        t[i]=-INF;

    }

    sort(all(v));

    for(int i=0;i<n;++i){

        id[-v[i].s]=i+1;

    }

    for(int i=1;i<=n;++i){

        dp[i]=dp[i-1]+(a[i]<0 ? -1:a[i]>0 ? 1:0);

        dp[i]=max(dp[i],get(id[i])+i);

        if(pref[i]>0){

            dp[i]=i;

        }

        upd(id[i],dp[i]-i);

    }

    cout<<dp[n]<<nl;



    for(int i=0;i<=n;++i){

        dp[i]=id[i]=t[i]=pref[i]=a[i]=0;

    }

}



signed main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int t=1;

    cin>>t;

    while(t--){

        solve();

    }

}