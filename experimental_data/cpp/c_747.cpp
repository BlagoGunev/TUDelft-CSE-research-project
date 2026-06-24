#include<bits/stdc++.h>
#define ll long long
#define inf 1000000007
using namespace std;
void read(int &x)
{
	x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
int n,q;
int mark[105];
int main()
{
	read(n);read(q);
	for(int i=1;i<=q;i++)
	{
		int t,k,d;
		read(t);read(k);read(d);
		int num=0;
		for(int i=1;i<=n;i++)if(mark[i]<t)num++;
		if(num<k){puts("-1");continue;}
		int ans=0;
		num=0;
		for(int i=1;i<=n;i++)
		{
			if(mark[i]<t)ans+=i,mark[i]=t+d-1,num++;
			if(num>=k)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}