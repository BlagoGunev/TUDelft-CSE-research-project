//======================================

//         Author:Arturia

//======================================

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cctype>

#include<ctime>

#include<cstdlib>

#include<string>

#include<queue>

#include<cmath>

#include<set>

#include<map>

#include<bitset>

#include<vector>

#define rep(x,a,b) for (int x=a;x<=(int)b;x++)

#define drp(x,a,b) for (int x=a;x>=(int)b;x--)

#define cross(x,a) for (int x=hd[a];~x;x=nx[x])

#define ll long long

#define inf (1<<29)

#define PII pair<int,int>

#define PDD pair<double,double>

#define mk(a,b) make_pair(a,b)

#define fs first

#define sc second

#define pb push_back

using namespace std;

inline ll rd(){

	ll x=0;int ch=getchar(),f=1;

	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();

	if (ch=='-'){f=-1;ch=getchar();}

	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}

	return x*f;

}

inline void rt(ll x){

	if (x<0) putchar('-'),x=-x;

	if (x>=10) rt(x/10),putchar(x%10+'0');

		else putchar(x+'0');

}

const int maxn=200005;

int cnt,to[maxn<<1],nx[maxn<<1],hd[maxn];

void addedge(int u,int v){

	to[cnt]=v;nx[cnt]=hd[u];hd[u]=cnt++;

}

int n,m,s[maxn];

ll ans;

void dfs(int u,int fa){

	cross(i,u){

		int v=to[i];

		if (v==fa) continue;

		dfs(v,u);

		s[u]+=s[v];

	}

	ans+=min(s[u],2*m-s[u]);

}

int main(){

	n=rd(),m=rd();

	rep(i,1,2*m) s[rd()]++;

	memset(hd,-1,sizeof hd);

	rep(i,1,n-1){

		int u=rd(),v=rd();

		addedge(u,v),addedge(v,u);

	}

	dfs(1,0);

	rt(ans);

}