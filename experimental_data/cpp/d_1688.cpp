// If you copy and paste my solution I will murder you in your sleep.
#include <bits/stdc++.h>

#define int long long
#define endl "\n"
using namespace std;

signed solve(){
    int n,k;
    cin>>n>>k;
    vector <int> a(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    int q = min(k,n);
    int ans = 0;
    int buf = q*(q-1)/2;
    for(int i = 0;i<n;i++){
        buf += a[i];
        if(i>= q){
            buf -= a[i-q];
        }
        if(i+1 >= q){
            ans = max(ans, buf);
        }
    }
    ans+= n*(max((int)0, k-n));
    cout<<ans<<endl;

    return 0;
}
signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin>>test;
    while(test--) solve();


    return 0;
}