#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#define Rint register int
#define LL long long
#define F(x,y,z) for(Rint x=y;x<=z;++x)
using namespace std;
inline LL R(){
    char c='!';LL x=0,z=1;
    for( ; c>'9'||c<'0';c=getchar()) if(c=='-')z=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    return x*z;
}
const int N=1000000;
int n,m,ans;
int to[N],ne[N],st[N],sl,d[N];
bool vis[N];
void Ads(int x,int y){to[++sl]=y;ne[sl]=st[x];st[x]=sl;}
bool fl;

void dfs(int u){
	if (vis[u]) return;
	vis[u]=1;
	if (d[u]!=2) fl=0;
	for (int i=st[u];i;i=ne[i])
		dfs(to[i]);
	
}

int main()
{
	n=R();m=R();
	F(i,1,m){
		int x=R();
		int y=R();
		Ads(x,y);Ads(y,x);
		d[x]++;d[y]++;
	}
	F(i,1,n) {
		if (vis[i]) continue;
		fl=1;
		dfs(i);
		if (fl) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}