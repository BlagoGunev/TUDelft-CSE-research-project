#include <bits/stdc++.h>
#define vc vector
#define ll long long

using namespace std;

int main() {
    ll tcs;cin >> tcs;
    while(tcs--){
        ll a, b;cin >> a >> b;
        if(a<0) a=-a;
        if(b<0) b=-b;
        if(a>b) swap(a, b);
        
        cout << a+b+max(0LL, b-a-1) << endl;;
    }
}