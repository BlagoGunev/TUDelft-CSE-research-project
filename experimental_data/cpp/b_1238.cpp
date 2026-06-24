#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
const int N=2e5+7;
int Q,n,K,A[N];
int main()
{
	Q=read();
	while(Q--)
	{
		n=read(); K=read();
		for(int i=1;i<=n;i++) A[i]=read();
		sort(A+1,A+n+1); ll sum=0; int ans=0;
		for(int i=n;i>=1;i--)
		{
			if(A[i]<=sum) continue;
			int r=i; while(A[r-1]==A[i]) r--;
			ans++; sum+=K; i=r;
		}
		printf("%d\n",ans);
	}
	return 0;
}