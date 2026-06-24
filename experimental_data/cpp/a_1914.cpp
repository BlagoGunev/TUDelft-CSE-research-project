#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string s; cin>>s;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[s[i]-'A'+1]++;
        }
        int count=0;
        for(auto i: m){
            if(i.second>=i.first) count++;
        }
        cout<<count<<endl;

    }
}