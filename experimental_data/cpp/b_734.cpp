#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,d,m,n,f,s,ans;
    cin>>a>>b>>c>>d;
    f = min(a,c);
    s = min(f,d);
    ans = (256*s);
    a -= s; c -= s; d -= s;
    if(a>0){
        n = min(b,a);
        ans += (32*n);
    }
    cout<<ans<<endl;
}