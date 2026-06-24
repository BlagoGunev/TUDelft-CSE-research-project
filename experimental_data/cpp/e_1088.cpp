#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 1LL<<60
#define ll long long
#define ULL unsigned long long
#define MAXN 300100
#define MOD 1000000007
#define Fill(a) memset(a,0,sizeof(a))
#define rep(i,s,t) for(register int i=(s);i<=(t);++i)
#define dwn(i,s,t) for(register int i=(s);i>=(t);--i)
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Vector{double x,y,z;}xyz[MAXN],r,h,w;
Vector operator + (const Vector &a,const Vector &b) {return (Vector){a.x+b.x,a.y+b.y,a.z+b.z};}
Vector operator - (const Vector &a,const Vector &b) {return (Vector){a.x-b.x,a.y-b.y,a.z-b.z};}
Vector operator * (const Vector &a,const double &b) {return (Vector){a.x*b,a.y*b,a.z*b};}
Vector operator / (const Vector &a,const double &b) {return (Vector){a.x/b,a.y/b,a.z/b};}
Vector operator ^ (const Vector &a,const Vector &b) {return (Vector){a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
double operator & (const Vector &a,const Vector &b) {return a.x*b.x+a.y*b.y+a.z*b.z;}
inline double len(Vector a) {return sqrt(a&a);}
inline double getV(Vector a,Vector b,Vector c) {return a&(b^c);}
inline double getA(Vector a,Vector b,Vector c)
{
    Vector x=a^c,y=a^b;return acos(x&y/len(x)/len(y));
}
const ll INF=0x3f3f3f3f3f3f3f3fLL;
int fst[MAXN],to[MAXN<<1],nxt[MAXN<<1],cnt,a[MAXN],n;
ll f[MAXN],ans1=-INF,ans2;
void add(int u,int v) {nxt[++cnt]=fst[u],fst[u]=cnt,to[cnt]=v;}
void dfs(int x,int pa)
{
	f[x]=a[x];
	for(int i=fst[x];i;i=nxt[i])
		if(to[i]!=pa) dfs(to[i],x),f[x]+=max(f[to[i]],0ll);
	ans1=max(ans1,f[x]);
}
void dfs2(int x,int pa)
{
	f[x]=a[x];
	for(int i=fst[x];i;i=nxt[i])
		if(to[i]!=pa) dfs2(to[i],x),f[x]+=max(f[to[i]],0ll);
	if(f[x]==ans1) ans2++,f[x]=0;
}
int main()
{
	n=read();int x,y;
	rep(i,1,n) a[i]=read();
	r=r^h,w=w^h;double uuuu=getV(r,w,h),xxxx=w&h;
	rep(i,2,n) x=read(),y=read(),add(x,y),add(y,x);
	r=w^h,h=w^r;double uuyu=getV(r,w,h),xxwx=w&h;
	dfs(1,0);dfs2(1,0);
	printf("%I64d %d\n",ans1*ans2,ans2);
}