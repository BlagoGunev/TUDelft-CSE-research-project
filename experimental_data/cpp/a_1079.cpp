#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e6+1;
typedef long long lli;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,t=0,a[200],b[200],k,ans=0,i,s=0,re;
    cin >>n>>k;
    for (i=0;i<=105;i++)
         b[i]=0;
    for (i=1;i<=n;i++)
    {
        cin >>a[i];
        b[a[i]]++;
        if (t<b[a[i]]) t=b[a[i]];
    }
    //cout <<t<<" ";
    if (t%k==0) s=t/k;
    else s=t/k+1;
    re=s*k;
    //cout <<re<<" ";
    for (i=0;i<=101;i++)
    {
        if (b[i]==0) continue;
        else ans+=re-b[i];
    }
    cout <<ans;
}