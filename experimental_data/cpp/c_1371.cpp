#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=55;

int t,n;
char c[N];

int main()
{	
	cin>>t;
	while(t--)
	{
		long long a,b,n,m;
		scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
		if(a+b>=n+m&&min(a,b)>=m)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}