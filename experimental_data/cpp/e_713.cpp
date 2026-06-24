// LUOGU_RID: 90377717
/*
わんわん……わんだほーいっ☆
Wonderhoy!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const int MOD=998244353;
inline int Add(int u,int v){return u+v>=MOD?u+v-MOD:u+v;}
inline int Sub(int u,int v){return u-v>=0?u-v:u-v+MOD;}
inline int Mul(int u,int v){return LL(u)*LL(v)%MOD;}
inline int add(int &u,int v){return u=Add(u,v);}
inline int sub(int &u,int v){return u=Sub(u,v);}
inline int mul(int &u,int v){return u=Mul(u,v);}
int QuickPow(int x,int p=MOD-2)
{
	int ans=1,base=x;
	while(p)
	{
		if(p&1)	mul(ans,base);
		mul(base,base);
		p>>=1;
	}
	return ans;
}
int m,n,a[100005];
void mvSeq()
{
	int f=n,maxn=m+a[1]-a[n];
	for(int i=2;i<=n;++i)	if(a[i]-a[i-1]>maxn)	f=i-1,maxn=a[i]-a[i-1];
	for(int i=1;i<=f;++i)	a[i]+=m;
	rotate(a+1,a+f+1,a+n+1);
	int d=a[1]-1;
	for(int i=1;i<=n;++i)	a[i]-=d;
}
int dp[100005];
bool check(int d)
{
	// printf("%d\n",d);
	dp[1]=1;
	for(int i=2;i<=n;++i)
	{
		dp[i]=-1;
		if(dp[i-1]+1>=a[i])	dp[i]=max(a[i]+d,dp[i]);
		else if(dp[i-1]+d+1>=a[i])	dp[i]=max(a[i],dp[i]);
		if(dp[i-2]+1>=a[i]-d)	dp[i]=max(a[i-1]+d,dp[i]);
	}
	// printf("%d %d\n",dp[n],m-d);
	if(dp[n]>=m-d)	return true;
	if(d+1<a[2]-d-1)	return false;
	dp[1]=d+1,dp[2]=max(a[2],d+1);
	for(int i=3;i<=n;++i)
	{
		dp[i]=-1;
		if(dp[i-1]+1>=a[i])	dp[i]=max(a[i]+d,dp[i]);
		else if(dp[i-1]+d+1>=a[i])	dp[i]=max(a[i],dp[i]);
		if(dp[i-2]+1>=a[i]-d && i!=3)	dp[i]=max(a[i-1]+d,dp[i]);
	}
	// printf("%d %d\n",dp[n],m-max(0,d+1-a[2]));
	return dp[n]>=m-max(0,d+1-a[2]);
}
int main(){
	m=read(),n=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	if(n==1)	return write(m-1),puts(""),0;
	sort(a+1,a+1+n);
	mvSeq();
	// for(int i=1;i<=n;++i)	printf("%d ",a[i]);puts("");
	dp[0]=-1e9;
	int l=0,r=1e9,ans=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))	ans=mid,r=mid-1;
		else	l=mid+1;
	}
	write(ans),puts("");
	return 0;
}