#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define Set(a) memset(a,0,sizeof(a))
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
typedef long long ll;
typedef unsigned long long ull;
template<typename T> inline T rd(T& x)
{
	T f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(T)(c-'0');
	x*=f;
	return x;
}
ll rd(){ll x;rd(x);return x;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int inf=1<<30;

const int M=10000007;
int mnp[M];int prs[700000];int tot=0;bool isnp[M];
void shai(int n)
{
	isnp[0]=isnp[1]=1;
	F(i,2,n)
	{
		if(!isnp[i]) prs[++tot]=i,mnp[i]=i;
		for(ri j=1;j<=tot&&i*prs[j]<=n;++j)
		{
			isnp[i*prs[j]]=1;
			mnp[i*prs[j]]=prs[j];
			if(i%prs[j]==0) break;
		}
	}
}
const int N=500005;
int a[N],d1[N],d2[N];
int main()
{
	shai(10000000);
	int n=rd();
	F(i,1,n) rd(a[i]);
	F(i,1,n)
	{
		int x=a[i],y=mnp[a[i]],z=1;
		while(x%y==0) x/=y,z*=y;
		if(x==1) d1[i]=d2[i]=-1;
		else d1[i]=z,d2[i]=x;
	}
	F(i,1,n) printf("%d ",d1[i]);puts("");
	F(i,1,n) printf("%d ",d2[i]);puts("");
	return 0;
}