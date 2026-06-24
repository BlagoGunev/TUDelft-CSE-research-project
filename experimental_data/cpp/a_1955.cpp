#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define lop(i,a,b) for(int i=(a);i<(b);i++)
#define dwn(i,a,b) for(int i=(a);i>=(b);i--)
#define el '\n' 
typedef pair<int,int> PII;
using LL = long long;
const int INF=0x3f3f3f3f,N=2e5+10;
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(a*2<=b)cout<<n*a<<el;
    else
    {
        if(n%2==0)cout<<n/2*b<<el;
        else cout<<n/2*b+a<<el;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int tt = 1;
    cin>>tt;
    while(tt--)
      solve();
    return 0;
}