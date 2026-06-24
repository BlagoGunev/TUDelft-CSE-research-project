#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase=1; cin>>testcase;
    while(testcase--){
        long long n,m,a,b,c; cin>>n>>m;
        a=abs(n-m);
        b=__gcd(n,m);
        c=max(n,m);
        if(n==m)cout<<0<<" "<<0<<"\n";
        else if(b==a)cout<<a<<" "<<0<<"\n";
        else{
            cout<<a<<" "<<min(c%a,a-c%a)<<"\n";
        }
    }
    return 0;
}