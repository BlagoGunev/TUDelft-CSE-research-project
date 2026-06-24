#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define MAX 2147483647

const int N=1e6+10;
const double dif=1e-7;
//const int M=20;
//int a[N];
//bool isnp[N];

void solve()
{
    int n;
    cin>>n;
    int a[n];
    map<int ,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int k=a[i];
        if(mp[k]&&mp[MAX-k]>0)
        {
            ans++;
            mp[MAX-k]--;
            mp[k]--;
        }
    }
    cout<<n-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}