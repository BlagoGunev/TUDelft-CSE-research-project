#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
#pragma optimize("SEX_ON_THE_BEACH")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=skylake")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double
#define pb push_back
#define lb lower_bound
#define ub upper_bound  
#define mod 1000000007
#define mod1 998244353

#define fr(i, a, b) for(ll i = a; i <= b; i++)
#define rev(i, a, b) for(ll i = a; i >= b; i--)

#define minheappr priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>
#define minheap priority_queue<ll,vector<ll>,greater<ll>>

 
const ll INF = 2e18;
const ll N = 500002;

void solve() {
    map<ll, vector <ll>>m;
    ll n; cin >> n;
    ll a[n];
    set<ll> s;
    fr(i, 0, n - 1){
        cin >> a[i];
        ll mask = a[i];
        fr(j, 0, 1){
            if(a[i] & (1 << j)){
                mask ^= (1 << j);
            }
        }
        m[mask].emplace_back(a[i]);
        s.insert(mask);
    }

    for(auto it = s.begin(); it != s.end(); it++){
        sort(m[*it].begin() , m[*it].end());
    }
    map<ll, ll> pt;
    fr(i, 0, n - 1){
        ll mask = a[i];
        fr(j, 0, 1){
            if(a[i] & (1 << j)){
                mask ^= (1 << j);
            }
        } 
        cout << m[mask][pt[mask]] << " ";
        pt[mask]++;
    }
    cout << "\n";
}
 
signed main() {

    #ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll misery = 1;
    cin >> misery;

    while(misery--)       
        solve();    

}