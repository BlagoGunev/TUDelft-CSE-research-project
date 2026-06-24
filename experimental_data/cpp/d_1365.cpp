#include<bits/stdc++.h>
using namespace std;
char a[60][60];
int mp[60][60];
int vis[60][60];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m;
void dfs(int x,int y){
    if (vis[x][y]!=0) return ;
    if (a[x][y]=='#'||a[x][y]=='B'){
        vis[x][y]=-1;
        return ;
    }
    for (int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (tx>=1&&tx<=n&&ty>=1&&ty<=m){
            if (a[tx][ty]=='B'){
                vis[x][y]=-1;
                return ;
            }
        }
    }
    vis[x][y]=1;
    for (int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (tx>=1&&tx<=n&&ty>=1&&ty<=m){
            if (vis[tx][ty]==0)
            dfs(tx,ty);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for (int i=0;i<=n;i++){
            for (int j=0;j<=m;j++){
                vis[i][j]=0;
                mp[i][j]=0;
            }
        }
        for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
        dfs(n,m);
        int flag=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (a[i][j]=='G'){
                    if (vis[i][j]!=1) flag=1;
                }
            }
        }
        if (flag) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}