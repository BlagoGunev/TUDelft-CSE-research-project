#include<bits/stdc++.h>

using namespace std;

int prime(long long  n) 
{ 
	if(n==0)
		return 0;
	if(n==1)
		return 0;
	if(n<=3)
		return 1;
	if(n%2==0)
		return 0;
	if(n%3==0)
		return 0;
	for (long long  i = 5; i*i <=n ; i+=6)
	{
		if(n%i==0 || n%(i+2)==0)
			return 0;
	}
	return 1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int a,b;
		cin>>a>>b;
		if(a-b!=1)
			cout<<"NO";
		else
		{
			long long n=(a+b);
			if(prime(n))
				cout<<"YES";
			else
				cout<<"NO";
		}
		cout<<'\n';
	}
}