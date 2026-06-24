#include <cstdio>
#include <vector>
#include <cstring>
#define LL long long
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();++i)
using namespace std;

const LL INF=1999999999999999ll;
int n,m,w,l,r,c;
LL ans,g[303],f[303][303];
vector< pair<int,int> > v[303];

int main() {
	scanf("%d%d%d",&n,&m,&w);
	for (int i=1;i<=m;++i) {
		scanf("%d%d%d",&l,&r,&c);
		v[l].push_back(make_pair(r,c));
	}
	for (int i=0;i<=n;++i)
		for (int j=0;j<=n;++j) f[i][j]=INF;
	for (int i=0;i<=n;++i) g[i]=INF;
	f[0][0]=0;
	ans=INF;
	for (int i=0;i<n;++i) {
		for (int j=0;j<=i;++j)
			f[i+1][j]=min(f[i+1][j],f[i][j]);
		FOR(p,v[i+1])
			g[p->first]=min(g[p->first],(LL)p->second);
		for (int j=0;j<=i;++j) if (f[i][j]<INF)
			for (int k=i+1;k<=n;++k) if (g[k]<INF) {
				f[k][k-i+j]=min(f[k][k-i+j],f[i][j]+g[k]);
				if (k-i+j>=w) ans=min(ans,f[k][k-i+j]);
			}
	}
	if (ans>=INF) puts("-1");
	else printf("%I64d\n",ans);
	return 0;
}