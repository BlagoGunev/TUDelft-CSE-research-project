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
}edge[200010];
int dl[100010],first[100010],size;
int du[100010],vis[200010];
bool exsit[100010];
void addedge(int x,int y){
	size++;
	edge[size].to=y;
	edge[size].next=first[x];
	first[x]=size;du[x]++;
}
int main(){
	int n,m;splay(n),splay(m);
	for(int i=1;i<=m;i++){
		int x,y;splay(x),splay(y);
		addedge(x,y),addedge(y,x);
	}
	int head=0,tail=0;
	for(int i=1;i<=n;i++){
		if(du[i]<=1)dl[++tail]=i,exsit[i]=1;
	}
	int ans=0;
	while(head!=tail){
		int v=dl[++head];
		if(du[v]==0)ans++;
		else{
			for(int u=first[v];u;u=edge[u].next){
				if(!vis[u]){
					du[v]--;
					du[edge[u].to]--;
					if(du[edge[u].to]<=1&&!exsit[edge[u].to]){
						exsit[edge[u].to]^=1;
						dl[++tail]=edge[u].to;
						vis[u]=vis[((u-1)^1)+1]=1;
					}
				}
				
			}
		}
	}
	cout<<ans<<endl;
}