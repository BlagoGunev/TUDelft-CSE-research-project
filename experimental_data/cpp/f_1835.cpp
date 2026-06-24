// Problem: F. Good Graph
// Contest: Codeforces - Codeforces Round 880 (Div. 1)
// URL: https://codeforces.com/contest/1835/problem/F
// Memory Limit: 256 MB
// Time Limit: 7000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 *                                                     __----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          __--~ ~~
 *                    -.            \_|//     |||\\  ~~~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \\            _/~~-
 *         __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
 *     _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \\ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       __--~~
 *                       |-~~-_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-~~____--~-/                  ~~==.
 *                       ((->/~   '.|||' -_|    ~~-/ ,              . _||
 *                                  -_     ~\      ~~---l__i__i__i--~~_/
 *                                  _-~-__   ~)  \--______________--~~
 *                                //.-~~~-~_--~- |-------~~~~~~~~
 *                                       //.-~~~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               神兽保佑            永无BUG
 */

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define inf 1e9
#define infll 1e18
#define pii pair<int,int>
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
#define wh(lzm) while(lzm--)
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
#define HH printf("\n")
#define eb emplace_back
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int mod=998244353,maxn=4000005;
int tot=1,to[maxn],w[maxn],hd[maxn],nxt[maxn],S,T;
void add(int u,int v,int x){ to[++tot]=v,w[tot]=x,nxt[tot]=hd[u],hd[u]=tot; }
void ins(int u,int v,int x=1){ add(u,v,x),add(v,u,0); }
int now[maxn],d[maxn];
int bfs(){
    queue<int>q; q.push(S);
    F(i,0,T+5) d[i]=inf;
    d[S]=0,now[S]=hd[S];
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=hd[u];i;i=nxt[i]){
            int v=to[i],x=w[i];
            if(x>0&&d[v]>=inf){
                q.push(v);
                now[v]=hd[v];
                d[v]=d[u]+1;
                if(v==T) return 1;
            }
        }
    }
    return 0;
}
int dfs(int u,int sum){
    if(u==T||!sum) return sum;
    int k=0,fl=0;
    for(int i=now[u];i;i=nxt[i]){
        now[u]=i;
        int v=to[i],x=w[i];
        if(x>0&&d[v]==d[u]+1){
            k=dfs(v,min(sum-fl,x));
            w[i]-=k,w[i^1]+=k,fl+=k;
            if(fl==sum) return fl;
        }
    }
    if(!fl) d[u]=inf;
    return fl;
}
int flag[maxn];
void dfs(int u){
	flag[u]=1;
	for(int i=hd[u];i;i=nxt[i]) if(w[i]&&!flag[to[i]]) dfs(to[i]);
}
int n,m,mat[1005],sz[1005],p[1005],vis[1005];
bitset<1005>g[1005];
signed main(){
	n=read(),m=read(),S=(n<<1)+1,T=(n<<1)+2;
	F(i,1,n) ins(S,i),ins(i+n,T);
	F(i,1,m){ int x=read(),y=read(); ins(x,y); }
	int flow=0;
    for(;bfs();){ for(int x;x=dfs(S,inf);flow+=x); }
	if(flow<n){
		dfs(S);
		vector<int>vec;
		F(i,1,n) if(flag[i]) vec.push_back(i);
		puts("NO");
		printf("%d\n",(int)vec.size());
		for(int i:vec) printf("%d ",i);
		return 0;
	}
	puts("YES");
	F(i,1,n) for(int j=hd[i];j;j=nxt[j]) if(!w[j]&&(to[j]<=(n<<1))) mat[to[j]-n]=i;
	F(i,1,n) for(int j=hd[i];j;j=nxt[j]) if(to[j]<=(n<<1)) g[i][mat[to[j]-n]]=1;
	F(i,1,n) F(j,1,n) if(g[j][i]) g[j]|=g[i];
	F(i,1,n) sz[i]=g[i].count(),p[i]=i;
	sort(p+1,p+n+1,[&](int x,int y){
		return sz[x]<sz[y];
	});
	bitset<1005>tmp;
	F(i,1,n){
		int lst=0;tmp.reset();
		F(j,i+1,n){
			if(g[p[i]][p[j]]) lst=p[j],vis[j]=1,g[p[i]][p[j]]=0;
			if(g[p[j]][p[i]]){
				if((g[p[j]]&tmp).any()) g[p[j]][p[i]]=0;
				else tmp[p[j]]=1;
			}
		}
		if(!vis[i]&&lst>0) g[p[i]][lst]=1;
	}
	int ans=0;
	F(i,1,n) ans+=g[i].count();
	printf("%d\n",ans);
	F(i,1,n) F(j,1,n) if(g[i][j]) printf("%d %d\n",i,j+n);
}