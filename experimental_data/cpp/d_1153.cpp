#include<bits/stdc++.h>
#define inf 1000000007
#define N 300005
typedef long long ll;
using namespace std;
// 每题开始1小时后，没有ac ， 直接重写，重写1小时没有ac，当天不能再交该题
int tot=1,head[N],net[N],to[N],fa[N],siz[N],a[N],a1,n,ans;
int gets(){
	int v=0;bool f=0;char ch;
	while(!isdigit(ch)) { f|=ch=='-'; ch=getchar(); }
	while( isdigit(ch)) { v=(v<<3)+(v<<1)+ch-48; ch=getchar(); }
	return f?-v:v;
}
void ins(int frm,int to2){
	to[++tot]=to2, net[tot]=head[frm], head[frm]=tot;
}
void dfs(int x){
	int fl=0;
	for(int t=head[x];t;t=net[t]) if(to[t]!=fa[x]){
		fa[to[t]]=x; dfs(to[t]); 
		fl=1; 
		if(a[x]){
			if(siz[to[t]]<siz[x] || !siz[x]) ans+=siz[x], siz[x]=siz[to[t]]; 
			else ans+=siz[to[t]];
		}
		else siz[x]+=siz[to[t]];
	}
	if(!fl) siz[x]=1;
}
int main ()
{
	n=gets();
	for(int i=1;i<=n;i++) a[i]=gets();
	for(int i=2;i<=n;i++) a1=gets(), ins(a1,i);
	dfs(1);
	cout<<ans+1<<endl;
	return 0;
}