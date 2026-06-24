#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long n,x,y,i,j,k;

int main()
{
	scanf("%lld%lld%lld",&n,&x,&y);
	if(y<n||n-1+(y-n+1)*(y-n+1)<x)printf("-1\n");
	else
	{
		printf("%lld\n",y-n+1);
		for(i=1;i<n;++i)printf("1\n");
	}
}