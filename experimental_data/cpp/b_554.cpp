#include<bits/stdc++.h>

using namespace std;

int n,i,ans;

string a;

map <string,int> m;

int main()

{

    cin>>n;

    for(i=0;i<n;i++) cin>>a, m[a]++;

    for(auto i:m) ans=max(ans,i.second);

    cout<<ans;

}