#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10,inf = 0x3f3f3f3f;
int a[110];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2==1) ans1+=a[i];
        else ans2+=a[i];
    }
    if(ans1<ans2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}