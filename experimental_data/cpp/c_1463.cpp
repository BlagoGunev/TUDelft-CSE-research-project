/**
 * author: NotLinux
 * created: isoD
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef LOCAL
    #include "/home/notlinux/debug.h"
#else
    #define debug(x...) void(37)
#endif
void solve(){
    int n;
    cin>>n;
    vector < int > a(n+1),b(n+1);
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    int x=0,y=0, ans=0;
    for(int i=1,t;i<=n;i++){
        if(x==y)y=b[i];
        if(a[i+1]-a[i]>=abs(x-y) or i==n)t=y;
        else t=x<y?x+a[i+1]-a[i]:x-a[i+1]+a[i];
        if((b[i]-x)*(b[i]-t)<=0) ans++;
        x=t;
    }
    cout<< ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    int tt=1;
    cin >> tt;
    while(tt--)solve();
}