#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(...) 42
    template<typename T>ostream&operator<<(ostream&os,vector<T>&vec){for(signed i=0;i+1<vec.size();++i){os<<vec[i]<<" ";}if(vec.size()>0)os<<vec.back();return os;}
#endif
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
template<typename T>istream&operator>>(istream&is,vector<T>&vec){for(T&element:vec){is>>element;}return is;}
template<typename T>void chmin(T&x,T y){x=min(x,y);}
template<typename T>void chmax(T&x,T y){x=max(x,y);}
 
#define int long long
 
void test_case(void) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ar(n);
    cin >> ar;
    vector<int> needar(m);
    cin >> needar;
    map<int, int> need;
    for (int i = 0; i < m; ++i) {
        need[needar[i]]++;
    }
    int res = 0;
    int same = 0;
    map<int, int> have;
    auto add = [&] (int el) {
        if (have[el] < need[el]) ++same;
        have[el]++;
    };
    auto rm = [&] (int el) {
        if (have[el] <= need[el]) --same;
        --have[el];
    };
    for (int i = 0; i < m; ++i) {
        add(ar[i]);
    }
    if (same >= k) ++res;
    for (int i = m; i < n; ++i) {
        rm(ar[i - m]);
        add(ar[i]);
        if (same >= k) ++res;
    }
    cout << res << "\n";
}
 
signed main(void) {
    cin.tie(0)->sync_with_stdio(false);
 
    signed tt = 1;
    cin >> tt;
    for (int __ = 1; __ <= tt; ++__) {
        test_case();
    }
}