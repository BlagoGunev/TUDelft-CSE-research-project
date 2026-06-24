#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map <char,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
    }
    int res=0,sum=0;
    for(int i=0;i<26;i++)
    {
        res+=min(mp[char(i+'a')],mp[char(i+'A')]);
        sum+=abs(mp[char(i+'a')]-mp[char(i+'A')])/2;
    }
    cout<<res+min(k,sum)<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}