#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(v) (v).begin(), (v).end()
#define forn(i,a,n) for(ll i=a; (i)<(n); (i)++)
#define scan_a(a,n) for(ll i=0; (i)<(n); (i)++) cin>>a[i];
#define ff first
#define ss second
#define newl '\n'

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x)
#endif
struct custom_hash {
    // template <class T1, class T2>
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x % y);
}



void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    scan_a(a, n);
    map<ll, ll> mp;
    dbg(a)
    for(ll i = 0; i<n; i++){
        ll z = a[i];
        // dbg(sqrtl(z))
        for(ll j = 2; j * j <= z; j++){
            while(z % j == 0){
                mp[j]++;
                z /= j;
            }
            
        }
        if(z > 1){
            mp[z]++;
        }
        
    }
    dbg(mp)
    bool ans = 1;
    // ll last = -1;
    
    for(auto v: mp){
        if((v.ss % n) != 0){            
            dbg(v.ff)
            ans = 0;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(25);
    std::cerr << std::fixed << std::setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while(t--) {

        solve();
    }


    auto stop = std::chrono::high_resolution_clock::now();
    long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cerr << "Time taken : " << duration / 1e9 << "s" << newl;
    return 0;
}