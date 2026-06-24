#include <bits/stdc++.h>
using namespace std;

int t,it,l,r,ans,cnt,i,n,k;

int main(){
    cin>>t;
    for (it=1;it<=t;it++) {
        cin>>n;
        cnt=0;
        l=1000000000;
        r=0;
        for (i=1;i<=n;i++) {
            cin>>k;
            l=min(l,k);
            r=max(r,k);
        }
        ans=(r-l);
        while (ans!=0) {
            cnt++;
            ans/=2;
        }
        cout<<cnt<<'\n';
        if (cnt<=n) {
for (i=1;i<=cnt;i++) {
            cout<<l<<' ';
        }
        if (cnt) cout<<'\n';
}
    }
}