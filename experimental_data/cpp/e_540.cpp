#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF (1<<30)
#define ll long long
#define sz(x) ((int) (x.size()))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define clr(x) memset(x, 0, sizeof(x))
#define d(x) cout << x << endl
#define REP(i,x) for (int i = 0; i < (int)(x); ++i)
#define rep(i,a,b) for (int i = (int) a; i <= (int) b; ++i)
#define dep(i,a,b) for (int i = (int) a; i >= (int) b; --i)
#define foreach(it,x) for (typeof((x).begin()) it=(x).begin();it!=(x).end();++it)
#define PII pair<int,int>

ll power(ll x,ll y,ll mod){if (y<0)return power(power(x,mod-2,mod),-y,mod);ll res=1;while(y){if (y&1) res=res*x%mod;y>>=1;x=x*x%mod;}return res;}

const int nn=1001234;
int C[nn],p[nn],g[nn],x[nn],y[nn];
int n,cnt;

void insert(int x,int y) {
	for (;x<=cnt;x+=x&-x) C[x]+=y;
}
int query(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=C[x];
	return s;
}
int find(int x) {return lower_bound(p+1,p+1+cnt,x)-p;}
int main()
{
	//freopen("1.in", "r", stdin);
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&x[i],&y[i]);
		p[++cnt]=x[i];
		p[++cnt]=y[i];
	}
	sort(p+1,p+1+cnt);
	cnt=unique(p+1,p+1+cnt)-p-1;
	rep(i,1,cnt) g[i]=p[i];
	rep(i,1,n) {
		x[i]=find(x[i]);
		y[i]=find(y[i]);
		swap(g[x[i]],g[y[i]]);
	}
	ll s=0;
	rep(i,1,cnt) {
		int t=find(g[i]);
		s+=i-1-query(t);
		if (g[i]<p[i])
			s+=p[i]-p[t]-(i-t);
		insert(t,1);
		if (i<cnt)
			s+=1ll*(p[i+1]-p[i]-1)*(i-query(i));
	}
	cout << s << endl;
	return 0;
}