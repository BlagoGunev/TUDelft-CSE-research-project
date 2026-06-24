#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define down(i,l,r) for (int i=l;i>=r;i--)
#define clr(x,y) memset(x,y,sizeof(x))
#define maxn 605000
#define inf (int)1e9
#define ll long long
#define eps 1e-9
#define mm 998244353LL
#define low(x) x&(-x)
#define pb push_back
#define mp make_pair
#define PII pair<int,int>
using namespace std;
ll read(){
    ll x=0,f=1; char ch=getchar();
    while (!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
struct data{int obj,pre,c;
}e[maxn*2];
int head[maxn],a[maxn],dfn[maxn],n,m,tot,root,ans;
void insert(int x,int y){
	e[++tot].obj=y; e[tot].pre=head[x]; head[x]=tot;
}
int dfs(int u){
	int cnt=a[u]; dfn[u]=1;
	if (a[u]==-1) cnt=0;
	for (int j=head[u];j;j=e[j].pre){
		int v=e[j].obj;
		if (dfn[v]) continue;
		int now=dfs(v);
		if (now) e[j].c=1,ans++;
		cnt^=now;
	}
	return cnt;
}
int main(){
	n=read(); m=read();
	root=1; tot=1;
	rep(i,1,n) {
		a[i]=read();
		if (a[i]==-1) root=i;
	}
	rep(i,1,m) {
		int x=read(),y=read();
		insert(x,y); insert(y,x);
	}
	if (dfs(root)&&(a[root]!=-1)) {puts("-1"); return 0;}
	printf("%d\n",ans);
	rep(i,1,m) if (e[i+i].c||e[i+i+1].c) printf("%d\n",i);
/*	rep(i,1,n) if (a[i]==1) {
		for (int j=head[i];j;j=e[j].pre){
			int v=e[j].obj;
			if (a[v]==1&&(d[v]&1==0)) e[j].c=1,d[u]++,d[v]++;
		}
	}*/
	return 0;
}