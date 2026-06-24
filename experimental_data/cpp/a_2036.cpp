#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define int long long
#define ll long long
const int mod = 1e9 + 7; 
constexpr int INF = 2e18;
 
void solve(){
    ll a, b, c, d, n, m, k, i, j, cnt;

    cin >> n;
    vector<ll> v(n);
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    for(i = 1; i < n; i++){
      a = abs(v[i] - v[i - 1]);
      if(a != 5 and a != 7){
        cout<<"NO"<<endl;
        return;
      }
    }
    cout<<"YES"<<endl;
    
}
signed main()
{
    FIO;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}