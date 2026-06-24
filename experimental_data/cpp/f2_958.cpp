#include<bits/stdc++.h>
#define FIO "F2"
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}

template<typename T> inline void Min(T &x,T y) {if(x>y) x=y;}
template<typename T> inline void Max(T &x,T y) {if(x<y) x=y;}

const int maxn=5e5+10;
int n,m,a[maxn],k[maxn],cnt[maxn],ans=0,S=0;

int main()
{
#ifdef dxymaster
	freopen(FIO".in","r",stdin);
	freopen(FIO".out","w",stdout);
#endif

	n=read(),m=read();ans=maxn;S=0;
	for(int i=1;i<=n;i++) cnt[a[i]=read()]++;
	for(int i=1;i<=m;i++) k[i]=read(),S+=k[i];
	for(int i=1;i<=m;i++) if(cnt[i]<k[i]) return puts("-1"),0;
	int l=1,r=0;memset(cnt,0,sizeof(cnt));
	if(!S) return puts("0"),0;
	else if(S==1) return puts("0"),0;
	for(int i=1;i<=m;i++)
		while(cnt[i]<k[i]&&r<n) ++r,++cnt[a[r]];
	while(r<=n)
	{
		while(cnt[a[l]]-1>=k[a[l]]&&l<r) --cnt[a[l]],++l;
		Min(ans,r-l+1-S);++r;++cnt[a[r]];
	}
	if(ans==maxn) puts("-1");
	else cout<<ans<<endl;
#ifdef dxymaster
	cerr << "TIME: " << (double)clock() / CLOCKS_PER_SEC << "s		It Runs So Fast!" << endl;
#endif
	return 0;
}