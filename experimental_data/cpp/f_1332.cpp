#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define int LL
#define db double
#define INF 2147483647
#define LLINF 9223372036854775807
#define LL long long
using namespace std;
int inline read(){
    int num=0,neg=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
    while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
    return num*neg;
}
const int maxn=400010,mod=998244353;
struct Edge{
	int nxt,to;
}edge[maxn<<1];
int n,head[maxn],cnt,f[maxn][3];
void add_edge(int x,int y){
	edge[++cnt].nxt=head[x];edge[cnt].to=y;head[x]=cnt;
}
void dfs(int x,int fa){
	f[x][0]=1;
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].to;if(v==fa)continue;dfs(v,x);
		f[x][2]=((f[x][2]+f[x][0])*(f[v][2]+f[v][1]+f[v][0]*2)%mod+f[x][2]*(f[v][2]+f[v][1]+f[v][0])%mod)%mod;
		f[x][1]=((f[x][1]+f[x][0])*(f[v][2]+f[v][0])%mod+f[x][1]*(f[v][2]+f[v][1]+f[v][0]))%mod;
		f[x][0]=f[x][0]*(f[v][2]+f[v][1]+f[v][0])%mod;
	}
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();add_edge(u,v);add_edge(v,u);
	}dfs(1,0);printf("%d",(f[1][0]+f[1][1]+f[1][2]-1)%mod);
	return 0;
}