#include<bits/stdc++.h>
using namespace std;
typedef double ll;
int main()
{
	long int x,n,m,k,maxn=-1,maxp1=-1,minp2=1000000,a,b;
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(x>maxn)maxn=x;
	}
	cin>>m;
	while(m--)
	{
		cin>>x;
		if(x>maxp1)maxp1=x;
	}
	cin>>k;
	while(k--)
	{
		cin>>x;
		if(x<minp2)minp2=x;
	}
	cin>>a>>b;
	ll ans=sqrt((maxn*maxn*1.0)/(1.0+((minp2*a*1.0)/(maxp1*b*1.0))));
	printf("%0.9lf",ans);
	return 0;
}