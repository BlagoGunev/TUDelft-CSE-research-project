#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define endl               "\n"
//char to ASCII : int j = s[i];

const long long INF=1e18;
const int32_t mod=1e9+7;

//------------------------------------

void solve(){
    int a, b;
    cin >> a >> b;
    int ans;
    ans = min(a, b);
    ans = min(ans, (a+b)/4);
    cout << ans;
    cout << endl;
}

//------------------------------------
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}