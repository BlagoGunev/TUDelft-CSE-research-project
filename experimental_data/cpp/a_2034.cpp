#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        cout<<a/__gcd(a,b)*b<<endl; 
    }
}