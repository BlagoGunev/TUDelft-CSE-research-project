#include <bits/stdc++.h>

#define ll long long

#define forr(i, x, y) for(ll i = x; i <= y; i++)

#define forn(i, x, y) for(ll i = x; i >= y; i--)

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(tab) forr(i,1,n) cout<<tab[i]<<" "; cout<<endl

#define yes cout<<"YES"<<endl

#define no cout<<"NO"<<endl

#define heyy cout<<"HEYY!!"<<endl

using namespace std;

typedef pair<short, pair<ll, ll>> tup;

typedef pair<ll, ll> pii;

const ll N = 400002, MOD = 998244353, MAX = 1e18, MIN = -1e18, CTE = 1e15, LOGN = 21;



int n, tab[N];

bool vis[N];



void solve(){

    cin>>n;

    forr(i, 1, 2*n)   vis[i] = false;

    forr(i, 1, n){

            int x;

            cin>>x;

            vis[x] = true;

    }

    int a = 0, b = 0, cnt = 0;

    forr(i, 1, 2*n){

        if(!vis[i]) cnt++;

        else if(cnt){ cnt--; a++; }

    }

    cnt = 0;

    forn(i, 2*n, 1){

        if(!vis[i]) cnt++;

        else if(cnt){ cnt--; b++; }

    }

    cout<<abs(n-a-b)+1<<endl;

}



int main(){

    fast;

//    freopen("input.in", "r", stdin);

    ll t = 1;

    cin>>t;

    while(t--)  solve();

    return 0;

}