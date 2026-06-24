#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define File(S) freopen(S".in","r",stdin),freopen(S".out","w",stdout)
#define gec getchar
using namespace std;
typedef long long ll;
char ch;
bool fl;
template <typename Typeread>
void read(Typeread &a){
	for(fl=0,ch=gec();ch<'0'||ch>'9';ch=gec()) fl|=(ch=='-');
	for(a=0;ch>='0'&&ch<='9';ch=gec())a=((a+(a<<2))<<1)+(ch^'0');
	a=fl?-a:a;
}
const int N=1e6+10;
struct Edge{
	int nd,nx;
}e[2*N];
int fr[N],Mx[N],Dep[N],Fa[N];
int tot;
int n,x,y,X;
void Dfs(int x,int f){
	Mx[x]=0;Fa[x]=f;
	for(int i=fr[x];i;i=e[i].nx)
	if(e[i].nd!=f){
		Dep[e[i].nd]=Dep[x]+1;
		Dfs(e[i].nd,x);
		Mx[x]=max(Mx[x],Mx[e[i].nd]+1);
	}
}
void addedge(int x,int y){
	e[++tot]=(Edge){y,fr[x]};fr[x]=tot;
}
int Ans=0,now;
int main()
{
	read(n);read(X);
	for(int i=1;i<n;i++){
		read(x);read(y);
		addedge(x,y);addedge(y,x);
	}
	Dfs(1,0);
	for(now=X;Dep[now]>Dep[X]>>1;now=Fa[now]){
		Ans=max(Ans,Dep[now]+Mx[now]);
	}
	printf("%d",Ans<<1);
	return 0;
}