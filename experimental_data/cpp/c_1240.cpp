#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
LL g[1000100],f[1000010][2];
int T,ts,s[1000010],n,k,tmp[1000010],hed[1000010],too[1000010],nxt[1000010],nedge,val[1000010];
void ae(int x,int y,int z){
	nxt[++nedge]=hed[x];
	hed[x]=nedge;
	too[nedge]=y;
	val[nedge]=z;
}
void dfs(int x,int l){
	for (int i=hed[x];i;i=nxt[i]){
		int y=too[i];
		if (y==l) continue;
		s[y]=val[i];
		dfs(y,x);
	}
	ts=0;
	for (int i=hed[x];i;i=nxt[i]){
		int y=too[i];
		if (y==l) continue;
		tmp[++ts]=y;
	}
	LL t=0;
	FOR(i,1,ts) t+=f[tmp[i]][0];
	FOR(i,1,ts) g[i]=max(f[tmp[i]][1]+s[tmp[i]]-f[tmp[i]][0],0ll);
	sort(g+1,g+ts+1);
	reverse(g+1,g+ts+1);
	f[x][0]=t;
	FOR(i,1,min(k,ts)) f[x][0]+=g[i];
	f[x][1]=t;
	FOR(i,1,min(k-1,ts)) f[x][1]+=g[i];
}
void doit(){
	scanf("%d%d",&n,&k);
	nedge=0;
	FOR(i,1,n) hed[i]=0;
	FOR(i,2,n){
		int x,y,z;
		getint(x),getint(y),getint(z);
		ae(x,y,z),ae(y,x,z);
	}
	dfs(1,0);
	printf("%lld\n",f[1][0]);
}
int main(){
	cin>>T;
	while (T--) doit();
	return 0;
}