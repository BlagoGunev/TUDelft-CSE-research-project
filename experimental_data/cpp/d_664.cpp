//Copyright(c)2016 liuchenrui
#include<bits/stdc++.h>
using namespace std;
inline void splay(int &v){
	v=0;char c=0;int p=1;
	while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
	v*=p;
}
struct Edge{
	int to,next;
	int col;
}edge[200010];
int first[100010],size;
void addedge(int x,int y,int z){
	size++;
	edge[size].to=y;
	edge[size].next=first[x];
	first[x]=size;
	edge[size].col=z;
}
int n,m,tmp;
bool f,flag;
int cnt=100001,ans[100010],p[100010];
int C[100010];
bool vis[100010];
int ff[100010],sum;
void dfs(int now,int col){
	ff[++sum]=now;
	vis[now]=1;C[now]=col;
	if(C[now])tmp++;
	for(int u=first[now];u;u=edge[u].next){
		if(vis[edge[u].to]){
			if(edge[u].col){
				if(C[edge[u].to]==C[now])f=0;
			}
			else{
				if(C[edge[u].to]!=C[now])f=0;
			}
		}
		else{
			dfs(edge[u].to,col^edge[u].col);
		}
	}
}
void get(){
	f=1;int _cnt=0;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sum=0;tmp=0;dfs(i,0);
			if(f&&tmp<=sum-tmp){
				for(int i=1;i<=sum;i++){
					if(C[ff[i]]){
						p[++_cnt]=ff[i];
					}
				}
			}
			if(f&&sum-tmp<tmp){
				for(int i=1;i<=sum;i++){
					if(!C[ff[i]]){
						p[++_cnt]=ff[i];
					}
				}
			}
		}
	}
	if(f){
		if(_cnt<=cnt){
			for(int i=1;i<=_cnt;i++){
				ans[i]=p[i];
			}
			cnt=_cnt;
			flag=true;
		}
	}
}
int main(){
	splay(n),splay(m);
	for(int i=1;i<=m;i++){
		int x,y,z;char op[5];
		splay(x),splay(y),scanf("%s",op);
		if(op[0]=='B')z=0;
		else z=1;
		addedge(x,y,z),addedge(y,x,z);
	}
	get();
	for(int i=1;i<=size;i++){
		edge[i].col^=1;
	}
	get();
	if(flag){
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++){
			printf("%d ",ans[i]);
		}
	}
	else puts("-1");
}