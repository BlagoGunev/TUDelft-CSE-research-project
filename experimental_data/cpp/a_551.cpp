#include<bits/stdc++.h>

using namespace std;

const int nmax=2000+42;

pair<int,int> t[nmax];

int n;

int ans[nmax];

bool cmp(pair<int,int> x,pair<int,int> y)

{

return x.first>y.first;

}

int main()

{

cin>>n;

for(int i=0;i<n;i++){cin>>t[i].first;t[i].second=i;}

sort(t,t+n,cmp);

ans[t[0].second]=1;

for(int i=1;i<n;i++)

{

if(t[i].first==t[i-1].first)ans[t[i].second]=ans[t[i-1].second];

else ans[t[i].second]=i+1;

}

cout<<ans[0];

for(int i=1;i<n;i++)cout<<" "<<ans[i];cout<<endl;

return 0;

}