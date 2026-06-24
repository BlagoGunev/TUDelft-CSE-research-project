#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define vt vector
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ub upper_bound
#define lb lower_bound


const int inf = (int)2e9, mod = (int)1e9 + 7, mx = (int)2e5 + 10;
const ll infll = (ll)7e18;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    for(auto &u : a)cin >> u;
    for(auto &u : b)cin >> u;
    vector<vi> stor(n+1);
    for(int i = 0; i < n; i++){
        stor[b[i]].pb(i); 
    }
    vector<bool> finished(n+1); 
    for(int i = 1; i <= n; i++){
        if(stor[i].empty())continue;
        for(int j : stor[i]){
            if(b[j] == a[j])continue; 
            if(b[j] < a[j]){
                cout << "NO\n";
                return; 
            }
            assert(b[j] > a[j]); 
            //now we gotta try and find some value that exists to us 
            int lind = -1; 
            for(int k = j - 1; k >= 0; k--){
                if(a[k] > b[j])break;
                if(finished[k])break; 
                if(a[k] == b[j]){
                    lind = k; break; 
                }
            }
            bool good = false; 
            if(lind != -1){
                for(int k = lind; k <= j; k++){
                    a[k] = b[j];  
                }
                good = true; 
            }
            int rind = -1;
            for(int k = j + 1; k < n; k++){
                if(a[k] > b[j])break; 
                if(finished[k])break; 
                if(a[k] == b[j]){
                    rind = k; break; 
                }
            }
            if(rind != -1 && !good){
                for(int k = j; k <= rind; k++){
                    a[k] = b[j]; 
                }
                good = true;
            }
            if(!good){
                cout << "NO\n";
                return; 
            }



        }
        for(int j : stor[i])finished[j] = true; 
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}