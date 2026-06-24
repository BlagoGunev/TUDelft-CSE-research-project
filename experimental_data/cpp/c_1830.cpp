//
// Created by adavy on 5/22/2024.
//
#include <bits/stdc++.h>


using namespace std;


using ll = long long;

#define int long long

const ll MOD = 998244353;

struct Modular {
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

// generate a random number based on clock
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const ll MAX = 6*100000 + 8;
vector<Modular> facts(MAX), ifacts(MAX);

Modular comb(int a, int b){
    return facts[a]*ifacts[b]*ifacts[a-b];
}

Modular cat(int n){
    if (n%2==1) return 0;
    int k = n/2;
    return comb(2*k, k)/(k+1);
}




void do_test(){
    int n, k; cin >> n >> k;
    vector<ll> difq(n+1,0);
    for(int i=0;i<k;++i){
        int a,b; cin >> a >> b; a--; b--;
        // get a random number

        ll r = rng()*(1LL<<30)+rng();

        difq[a]^=r;
        difq[b+1]^=r;

    }
    // generate the difq
    for(int i=1;i<n;++i){
        difq[i] ^= difq[i-1];
    }
    map<int,int> hash_cts;
    for(int i=0;i<n;++i){
        if (hash_cts.find(difq[i]) == hash_cts.end()){
            hash_cts[difq[i]] = 1;
        }
        else hash_cts[difq[i]]++;
    }

    Modular ans = 1;
    for(auto [key,val]:hash_cts){

        ans *= cat(val);

    }

    cout << ans << endl;
}



signed main(){
    facts[0] = 1; ifacts[0] = 1;
    for(int i=1;i<MAX;++i){
        facts[i] = facts[i-1]*i; ifacts[i]=ifacts[i-1]/i;
    }

    int t; cin >> t; while(t--) do_test();
}