#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
bool vis[2005][2005];
int n,m,ans;
char str[2005];
struct node {
	int xx,yy,ll,rr;
};
queue<node> que;
int main() {
	scanf("%d%d",&n,&m);
	int x,y,l,r;
	scanf("%d%d%d%d",&x,&y,&l,&r);
	for (int i=1;i<=n;i++) {
		scanf("%s",str+1);
		for (int j=1;j<=m;j++) {
			if (str[j]=='*') vis[i][j]=true;
		}
	}
	que.push((node){x,y,l,r});vis[x][y]=1;
	for (int i=x-1;i>0;i--) {
		if (vis[i][y]) break;
		que.push((node){i,y,l,r});vis[i][y]=1;
	}
	for (int i=x+1;i<=n;i++) {
		if (vis[i][y]) break;
		que.push((node){i,y,l,r});vis[i][y]=1;
	}
	while (!que.empty()) {
		node h=que.front();que.pop();ans++;
		int nx=h.xx,ny=h.yy-1;
		if (h.ll>0 && ny>0 && !vis[nx][ny]) {
			que.push((node){nx,ny,h.ll-1,h.rr});vis[nx][ny]=1;
			for (int i=nx-1;i>0;i--) {
				if (vis[i][ny]) break;
				que.push((node){i,ny,h.ll-1,h.rr});vis[i][ny]=1;
			}
			for (int i=nx+1;i<=n;i++) {
				if (vis[i][ny]) break;
				que.push((node){i,ny,h.ll-1,h.rr});vis[i][ny]=1;
			}
		}
		nx=h.xx,ny=h.yy+1;
		if (h.rr>0 && ny<=m && !vis[nx][ny]) {
			que.push((node){nx,ny,h.ll,h.rr-1});vis[nx][ny]=1;
			for (int i=nx-1;i>0;i--) {
				if (vis[i][ny]) break;
				que.push((node){i,ny,h.ll,h.rr-1});vis[i][ny]=1;
			}
			for (int i=nx+1;i<=n;i++) {
				if (vis[i][ny]) break;
				que.push((node){i,ny,h.ll,h.rr-1});vis[i][ny]=1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}