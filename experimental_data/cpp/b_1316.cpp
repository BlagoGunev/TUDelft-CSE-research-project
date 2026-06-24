#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long t,n,k,i,j;
string s,a,b,c;
int main()
{
scanf("%lld",&t);
for(j=1;j<=t;j=j+1)
{
scanf("%lld",&n);cin>>s;a=s;k=1;
for(i=2;i<=n;i=i+1)
{
c=s.substr(0,i-1);
if((n-i)%2==1)b=s.substr(i-1,n-i+1)+c;
if((n-i)%2==0){reverse(c.begin(),c.end());b=s.substr(i-1,n-i+1)+c;}
if(a>b){a=b;k=i;}
}
cout<<a;
printf("\n%lld\n",k);
}
return 0;
}