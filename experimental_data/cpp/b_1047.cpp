#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int w=1,d=0; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')d=d*10+ch-'0',ch=getchar();
	return w*d;
}
int main()
{
	long long sum=0;
	int n=read();
	for(int i=1;i<=n;i++)
	{
		long long x=read(),y=read();
		sum=max(sum,x+y);
	}
	cout<<sum;
}