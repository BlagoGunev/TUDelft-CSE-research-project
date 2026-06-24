#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
char s[505][505];
int k,sum,d[4][2]={{-1,0},{1,0},{0,-1},{0,1}},n,m;
bool vis[505][505];
struct pos
{
    int x,y;
    pos(int _x,int _y){x=_x;y=_y;}
};
int isin(int x,int y)
{
    if(x<0||x>=n) return false;
    if(y<0||y>=m) return false;
    return true;
}
void bfs(int x,int y)
{
    queue<pos>q;
    while(!q.empty()) q.pop();
    memset(vis,0,sizeof(vis));
    q.push(pos(x,y));
    vis[x][y]=true;
    int cnt=1;
    if(cnt==sum-k) return;
    while(!q.empty())
    {
        pos tp=q.front();q.pop();
        for(int kk=0;kk<4;kk++)
        {
            int dx=tp.x+d[kk][0],dy=tp.y+d[kk][1];
            if(!isin(dx,dy)||vis[dx][dy]||s[dx][dy]=='#') continue;
            vis[dx][dy]=true;
            cnt++;
            if(cnt==sum-k) return;
            else q.push(pos(dx,dy));
        }
    }
}
int main()
{
    sum=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    int x,y;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if(s[i][j]=='.') {sum++;x=i;y=j;}
    bfs(x,y);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if(!vis[i][j]&&s[i][j]=='.') s[i][j]='X';
    for(int i=0;i<n;i++) printf("%s\n",s[i]);
    return 0;
}