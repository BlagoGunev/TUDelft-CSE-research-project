#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<int> x(n+1),y(n+1);
    for (int i = 1; i <= n; ++i)
    {
        cin>>x[i]>>y[i];
    }
    if(a<=k&&b<=k) cout<<0<<endl;
    else
    {
        int m=abs(x[a]-x[b])+abs(y[a]-y[b]);
        int ma=10000000000,mb=10000000000;
        for (int i = 1; i <=k ; ++i)
        {
            int ta=abs(x[a]-x[i])+abs(y[a]-y[i]),
                tb=abs(x[i]-x[b])+abs(y[i]-y[b]);
            ma=min(ma,ta);
            mb=min(mb,tb);
        }
        cout<<min(ma+mb,m)<<endl;
    }
}
signed main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
    return 0;
}