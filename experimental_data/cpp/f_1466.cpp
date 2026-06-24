#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	register int res=0;
	register char c=getchar(),f=1;
	while(c<48||c>57){if(c=='-')f=0;c=getchar();}
	while(c>=48&&c<=57)res=(res<<3)+(res<<1)+(c&15),c=getchar();
	return f?res:-res;
}
inline void write(int x){
	register char c[21],len=0;
	if(!x)return putchar('0'),void();
	if(x<0)x=-x,putchar('-');
	while(x)c[++len]=x%10,x/=10;
	while(len)putchar(c[len--]+48);
}
#define space(x) write(x),putchar(' ')
#define enter(x) write(x),putchar('\n')

const int N=5e5+10,mod=1e9+7;
int n,m,op,x,y,fa[N],cnt,ans[N];
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline ll qpow(ll x,int y){
	ll res=1;
	for(;y;y>>=1){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
	}return res;
}
int main(){
	m=read(),n=read();
	for(int i=0;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		op=read(),x=read();
		y=op==2?read():0;
		x=find(x),y=find(y);
		if(x==y)continue;
		fa[x]=y;
		ans[++cnt]=i;
	}
	space(qpow(2,cnt)),enter(cnt);
	for(int i=1;i<=cnt;++i)space(ans[i]);
}