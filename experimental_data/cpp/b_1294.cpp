#include<bits/stdc++.h>

using namespace std;

int main()

{int t;

cin>>t;

while(t--){

int n;

cin>>n;

pair<int ,int >a[n];

for(int i=0;i<n;i++){

cin>>a[i].first>>a[i].second;

}

sort(a,a+n);

int x=0,y=0,f=0;

string s="";

for(int i=0;i<n;i++){

int u=a[i].first,v=a[i].second;

if(v<y){

f=1;

cout<<"NO";

cout<<endl;

break;

}

s+=string(u-x,'R');

s+=string(v-y,'U');

x=u;

y=v;

}

if(!f)

cout<<"YES"<<endl<<s<<endl;

}

return 0;

}