#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b,x,y,buf,count=0,i,n,p,q;
	cin>>a>>b>>x>>y;

	n=__gcd(x,y);
	x/=n;
	y/=n;

	
	
	p=(a/x);
	q=(b/y);

	if (p>=q)
	{
		cout<<q;
	}
	else
	{
		cout<<p;
	}
		
	
	
}