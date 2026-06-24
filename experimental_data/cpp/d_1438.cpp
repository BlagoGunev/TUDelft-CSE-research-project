#include "bits/stdc++.h"

#define ll long long

#define pii pair<ll,ll>

#define piii pair<ll,pii>

#define pi acos(-1)

#define maxn 200009 /// I want to stay forever with you little star

#define MOD 1000000007

#define F first

#define S second

#define rep(i, a, b) for(ll i = a; i < (b); ++i)

#define per(i, b, a) for(ll i = b-1; i>=a ; i--)

#define sz(x) (ll)((x).size())

#define bg(x) begin(x)

#define all(x) bg(x), end(x)

#define rall(x) x.rbegin(), x.rend() 

#define sor(x) sort(all(x)) 

#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}

#define rsz resize

#define ins insert 

#define ft front()

#define bk back()

#define pb push_back

#define eb emplace_back 

#define pf push_front

#define INF 1e15

using namespace std;

 

#ifdef LOCAL

#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#else

#define debug(...) 42

#endif

 

void solvetask(){

    ll n;

    cin>>n;

    vector<ll> vet(n);

    ll xoract = 0;

    rep(i,0,n){

        cin>>vet[i];

        xoract^=vet[i];

    }

    ll temeq = -1;

    rep(i,0,n){

        if(temeq == -1 && vet[i] == xoract) temeq = i;

    }

    vector<piii> ans;

    if(n%2==1){

        cout<<"YES\n";

        rep(i,1,n){

            ans.pb({0,{i,i+1}});

            i++;

        }

        per(i,n-2,1){

            ans.pb({n-1,{i,i-1}});

            i--;

        }

    }

    else if(xoract == 0){

        cout<<"YES\n";

        rep(i,2,n){

            ans.pb({1,{i,i+1}});

            i++;

        }

        per(i,n-2,2){

            ans.pb({n-1,{i,i-1}});

            i--;

        }

    }

    else{

        cout<<"NO\n";

        return;

    }

    cout<<sz(ans)<<"\n";

    for(auto e:ans){

        cout<<e.F+1<<" "<<e.S.F+1<<" "<<e.S.S+1<<'\n';

    }

}

 

int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    int t = 1;

//    cin>>t;

    while(t--) solvetask();

    return 0;

}