#include<bits/stdc++.h>
#define rgi register int
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=200010;
int n,t,q[N],c,x;
int fa[N],rs[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
signed main(){
	read(t);
	while(t--){
		read(n),c=0;
		for(rgi i=1;i<=n;++i)fa[i]=i,rs[i]=0;
		for(rgi i=1;i<=n;++i){
			read(x);
			int now=i;
			while(x){
				rs[now]=1;
				if(now<=i-x+1||now==1)break;
				fa[now]=find(now-1);
				now=fa[now];
				rs[now]=1;
			}
		}
		for(rgi i=1;i<=n;++i){
			write(rs[find(i)],' ');
		}
		puts("");
	}
	return 0;
}