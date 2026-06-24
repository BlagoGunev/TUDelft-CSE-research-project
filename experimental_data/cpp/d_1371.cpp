#include<bits/stdc++.h>

using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int a,b;
cin>>a>>b;
cout<<(b%a?2:0)<<endl;
for(int i=a-1;i>=0;i--)
{
for(int j=a-1;j>=0;j--)
cout<<((j+i)%a*a+i<b);
cout<<endl;
}
}
}