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

typedef pair<ll, pair<ll, ll>> tup;

typedef pair<ll, ll> pii;

const ll N = 102, MOD = 998244353, MAX = 1e9, MIN = -1e9, CTE = 1e15, LOGN = 21;



int n;

string s;



void solve(){

    cin>>n>>s;

    sort(s.begin(), s.end());

    cout<<s<<endl;

}



int main(){

    fast;

//    freopen("input.in", "r", stdin);

    ll t = 1;

    cin>>t;

    while(t--)  solve();

    return 0;

}