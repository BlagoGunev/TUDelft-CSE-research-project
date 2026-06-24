#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

#define ll long long

#define ui unsigned long long

#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ld long double

#define pb push_back

#define SZ(a) (ll)(a.size())

#define FOR(i,a,n) for(ll i=a;i<=n;i++)

#define FORr(i,a,n) for(ll i=n;i>=a;i--)

#define trav(m,a) for(auto m:a){cout<<m<<" ";}cout<<"\n";

#define read(a,n) FOR(i,1,n){ll q;cin>>q;a.pb(q);}

#define F first

#define S second

#define pie 3.141592654

#define MAX 9000000000000000000

#define MIN -9000000000000000000

#define print(a) cout<<a<<"\n"

template<class T>using oset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;//multiset-less_equal

bool cmp(const pair<ll,ll>&a,const pair<ll,ll>&b){

    return a.S<b.S;

}

void solve(){

    vector<ll>a(7),b={0};for(int i=1;i<=6;i++){cin>>a[i];}

    ll n;cin>>n;for(int i=1;i<=n;i++){ll q;cin>>q;b.pb(q);}

    sort(a.begin(),a.end());sort(b.begin(),b.end());ll ans=MAX;

    for(int i=1;i<=6;i++){

        for(int j=1;j<=n;j++){

            ll mn=b[j]-a[i],mx=0,last=n;

            if(b[1]-a[1]<mn){continue;}

            for(int k=6;k>=1;k--){

                auto c=lower_bound(b.begin()+1,b.end(),a[k]+mn);ll x=c-b.begin();

                if(x<=last){mx=max(mx,b[last]-a[k]);last=x-1;}

            }

            ans=min(ans,mx-mn);

        }

    }

    cout<<ans<<"\n";

}

int main(){

    fast();

    ll T=1;

    while(T--){

        solve();

    }

    return 0;

}