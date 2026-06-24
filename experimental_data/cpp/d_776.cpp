#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=100005;
int n,m;
int num,head[maxn],t[maxn<<1],ne[maxn<<1],v[maxn<<1];
inline void addedge(int x,int y,int z){
	ne[++num]=head[x];head[x]=num;t[num]=y;v[num]=z;
	ne[++num]=head[y];head[y]=num;t[num]=x;v[num]=z;
}
int r[maxn];
int a[maxn],b[maxn];
int col[maxn];
bool vis[maxn],inv=0;
inline void dfs(int x){
	vis[x]=1;
	forE(i,x)
		if(!vis[t[i]]){
			col[t[i]]=col[x]^v[i];vis[t[i]]=1;
			dfs(t[i]);
		}else{
			if((col[t[i]]^col[x])!=v[i])inv=1;
		}
}
int main(){
    read(n);read(m);
    rep(i,1,n)read(r[i]);
    rep(i,1,m){
    	int k;read(k);
    	rep(j,1,k){
    		int x;read(x);
    		if(a[x])b[x]=i;else a[x]=i;
    	}
    }
    rep(i,1,m)head[i]=-1;
    rep(i,1,n)addedge(a[i],b[i],r[i]^1);
    rep(i,1,m)if(!vis[i])dfs(i);
    puts(inv?"NO":"YES");
    return 0;
}