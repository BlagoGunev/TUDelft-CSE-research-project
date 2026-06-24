#include <bits/stdc++.h>
#define ll long long
#define nn endl
#define YES cout << "YES" << nn
#define NO cout << "NO" << nn
#define sp " "
#define all(x) x.begin(), x.end()
using namespace std;
void RAHMA(){ios::sync_with_stdio(false); cin.tie(NULL);}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n),arr;
    for(auto &it:v)cin>>it;
    ll sum=0;
    for(int i=1;i<n;i++)
        arr.push_back(abs(v[i]-v[i-1]));
    sort(all(arr));
    for(int i=0;i<(n-m);i++)sum+=arr[i];

    cout<<sum<<nn;
}
int main() {
    RAHMA();
    ll t=1; cin>>t;
    while(t--){
        solve();
    }
}