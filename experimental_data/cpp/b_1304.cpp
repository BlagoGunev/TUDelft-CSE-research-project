#include<bits/stdc++.h>

using namespace std;
set<string>cy;
int main()
{
int n,m;
string s,t,ans1="",ans2="",rev="";
cin>>n>>m;
while(n--)	{
cin>>s,t=s;
reverse(t.begin(),t.end());
if(s==t) ans1=t;
else if(cy.count(t)){ ans2+=t; rev=s+rev;}
cy.insert(s);
}
ans2=ans2+ans1+rev;
cout<<ans2.size()<<"\n"<<ans2<<"\n";
}