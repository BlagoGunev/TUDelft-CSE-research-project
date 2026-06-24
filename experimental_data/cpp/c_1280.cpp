#include<bits/stdc++.h>
#define mxn 1000010
#define db double
#define LL long long
#define ldb long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair<int,int> 
#define mp make_pair
#define fr first
#define sc second
#define x1 faqx1
#define y1 faqy1
#define x2 faqx2
#define y2 faqy2
using namespace std;
const int inf=1e9,mod=1e9+7;
int n,m,sl,fh,siz[mxn];
LL ans1,ans2;
int t,h[mxn];
struct Tre
{
	int to,val,nxt;
}e[mxn<<1];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
void add(int u,int v,int w)
{
	e[++t]=(Tre){v,w,h[u]};h[u]=t;
	e[++t]=(Tre){u,w,h[v]};h[v]=t;
}
void dfs1(int u,int f)
{
	int v;siz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
		if((v=e[i].to)!=f)
		{
			dfs1(v,u);siz[u]+=siz[v];
			if(siz[v]&1) ans1+=e[i].val;
			ans2+=1ll*e[i].val*min(siz[v],n-siz[v]);
		}
}
int main()
{
	for(int x,y,z,T=rd();T;--T)
	{
		memset(h+1,0,n<<2);t=0;
		n=rd()<<1;ans1=ans2=0;
		for(int i=1;i<n;++i) x=rd(),y=rd(),z=rd(),add(x,y,z);
		dfs1(1,0);
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}