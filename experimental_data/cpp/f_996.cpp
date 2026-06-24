#include<iostream>  
#include<string>  
#include<cstring> 
#include<cmath> 
#include<cstdio>  
#include<cstdlib>  
#include<stdio.h>  
#include<algorithm>  
using namespace std;

const int maxs=(1<<18)+100;

int val[maxs];
int n,r;

int main()
{
	scanf("%d%d",&n,&r);
	int ms=(1<<n);
	long long sum=0;
	for (int i=0; i<ms; i++) scanf("%d",&val[i]),sum+=(long long)val[i];
	printf("%.8lf\n", (double)sum/(double)ms );
	while (r--)
	{
		int z,g;
		scanf("%d%d",&z,&g);
		sum-=(long long)val[z];
		val[z]=g;
		sum+=(long long)val[z];
		printf("%.8lf\n", (double)sum/(double)ms );
	}
	return 0;
}