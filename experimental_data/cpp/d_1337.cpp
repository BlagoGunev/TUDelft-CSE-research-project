#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
namespace Qza{
	#define MAXN 100005
	#define MAXG 300005
	typedef long long ll;
	int a[MAXN],b[MAXN],c[MAXN],buc[10];
	struct Gem {
		int w,c;
	}gem[MAXG];
	bool operator<(const Gem x,const Gem y) {
		return x.w<y.w;
	}
	ll Mod(ll a,ll p) {return a<p?a:a-p;}
	ll max(ll a,ll b) {return a<b?b:a;}
	ll min(ll a,ll b) {return a<b?a:b;}
	ll d(ll x,ll y,ll z)
	{
		//x=gem[a[x]].w; y=gem[b[y]].w; z=gem[c[z]].w;
		return (x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z);
	}
	int read()
	{
		char ch=getchar(); int x=0,f=1;
		while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9') x=(x*10)+(ch^48),ch=getchar();
		return x*f;
	}
	ll readll()
	{
		char ch=getchar();ll x=0,f=1;
		while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9') x=(x*10)+(ch^48),ch=getchar();
		return x*f;
	}
	void main()
	{
		int t,n,n1,n2,n3,cnt1,cnt2,cnt3,p[4];
		ll ans=0ll;
		t=read();
		while(t--) {
			ans=(1ll<<63)-1;
			n1=read(); n2=read(); n3=read();
			n=n1+n2+n3;
			for(int i=1;i<=n1;++i) {
				gem[i].c=1;
				gem[i].w=read();
			}
			for(int i=1;i<=n2;++i) {
				gem[n1+i].c=2;
				gem[n1+i].w=read();
			}
			for(int i=1;i<=n3;++i) {
				gem[n1+n2+i].c=3;
				gem[n1+n2+i].w=read();
			}
			sort(gem+1,gem+n+1);
			cnt1=cnt2=cnt3=0;
			for(int i=1;i<=n;++i) {
				if(gem[i].c==1) a[++cnt1]=i;
				else if(gem[i].c==2) b[++cnt2]=i;
				else c[++cnt3]=i;
			}
			p[1]=p[2]=p[3]=1;
			buc[1]=buc[2]=buc[3]=0;
			for(int l=1,r=1;r<=n;--buc[gem[l].c],++p[gem[l].c],++l,++r) {
				++buc[gem[r].c];
				while((!buc[1] || !buc[2] || !buc[3]) && r<n) {
					++r;
					++buc[gem[r].c];
				}
				if((!buc[1] || !buc[2] || !buc[3])) break;
				while(buc[gem[l].c]>=2) {
					--buc[gem[l].c];
					++p[gem[l].c];
					++l;
				}
				for(int k=l+1;k<r;++k) ans=min(ans,d(gem[l].w,gem[k].w,gem[r].w));
			}
			printf("%lld\n",ans);
		} 
	}
} 
int main()
{
	Qza::main();
	return 0;
}