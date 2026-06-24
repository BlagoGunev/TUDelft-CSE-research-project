#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        ll m;
        cin>>n>>m;
        char arr[105][105]={0};
        for(int i=0;i<n;i++)
        {
           scanf("%s",arr[i]);
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i][m-1]=='R')
            {
                ans++;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(arr[n-1][i]=='D')
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}