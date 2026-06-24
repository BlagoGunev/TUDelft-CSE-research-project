#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define pb push_back
int solve() {
    ll n,k,ans=0;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        ll f2=n;
        ll f1=i;
        bool sequence=true;
        for(ll j=0;j<k-2;j++){
            ll f0=f1;
            f1=f2-f0;
            f2=f0;
            sequence&=f1<=f2;
            sequence&=min(f1,f2)>=0;
            if(!sequence){
                break;
            }
        }
        if(sequence){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}