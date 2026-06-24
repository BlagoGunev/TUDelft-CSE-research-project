#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=1005;
int n,m,f[MN][MN],g[MN][MN];
bool mp[MN][MN],vis[MN][MN];
char ch[MN];
typedef pair<int,int>pii;
#define fi first
#define se second
queue<pii>q;
const int dir[2][4]={{1,-1,0,0},{0,0,1,-1}};
int main(){
	scanf("%d%d",&n,&m);
	for(reg int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(reg int j=1;j<=m;j++)
			mp[i][j]=(ch[j]=='#');
	}
	reg int flg1=0,flg2=0;
	for(reg int i=1;i<=n;i++){
		for(reg int j=1;j<=m;j++){
			if(!mp[i][j-1]&&mp[i][j])f[i][j]=f[i][j-1]+1;
			else f[i][j]=f[i][j-1];
		}
		if(f[i][m]>1)return 0*puts("-1");
		if(!f[i][m])flg1=1;
	}
	for(reg int j=1;j<=m;j++){
		for(reg int i=1;i<=n;i++){
			if(!mp[i-1][j]&&mp[i][j])g[i][j]=g[i-1][j]+1;
			else g[i][j]=g[i-1][j];
		}
		if(g[n][j]>1)return 0*puts("-1");
		if(!g[n][j])flg2=1;
	}
	if(flg1!=flg2)return 0*puts("-1");
	reg int Ans=0;
	for(reg int i=1;i<=n;i++)
		for(reg int j=1;j<=m;j++)
			if(mp[i][j]&&!vis[i][j]){
				q.push(make_pair(i,j));vis[i][j]=true;
				while(!q.empty()){
					reg pii v=q.front();q.pop();
					for(reg int k=0,dx,dy;k<4;k++){
						dx=v.fi+dir[0][k];dy=v.se+dir[1][k];
						if(mp[dx][dy]&&!vis[dx][dy])
							q.push(make_pair(dx,dy)),vis[dx][dy]=true;
					}
				}
				Ans++;
			}
	printf("%d\n",Ans);
	return 0;
}