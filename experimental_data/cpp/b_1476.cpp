#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline long long read()
{
	long long x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main()
{
//	freopen("in.txt","r",stdin);
	long long t=read();
	while(t--)
	{
		long long n=read();
		long long k=read();
		long long sum=read();
		long long xx=0;
		for(long long i=1;i<n;i++)
		{
			long long x=read();
			if(x*100>sum*k)
			{
				xx+=(ceil)(100.0*x/k)-sum;
				sum+=(ceil)(100.0*x/k)-sum;
			}
			sum+=x;
		}
		cout<<xx<<endl;
	}
	return 0; 
}