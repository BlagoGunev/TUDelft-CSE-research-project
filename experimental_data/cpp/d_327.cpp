#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
#define M 510
#define N 1000010

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

queue<int> qq;

char s[M][M],st[N];
int p[M*M],vis[M*M];
int a[N],b[N];

int main() {
    //freopen("in.txt","r",stdin);

    int r,c,i,ii,j,k,x,y,xx,yy,t,tt;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++) scanf("%s",s[i]);
    memset(vis,0,sizeof(vis));

    t=0;
    for(ii=0;ii<r*c;ii++) {
        x=ii/c;
        y=ii%c;
        if(s[x][y]!='#' && !vis[ii]) {
            while(!qq.empty()) qq.pop();
            vis[ii]=1;tt=1;
            b[0]=ii;qq.push(ii);
            while(!qq.empty()) {
                i=qq.front();qq.pop();
                x=i/c;y=i%c;
                for(k=0;k<4;k++) {
                    xx=x+dx[k];
                    yy=y+dy[k];
                    if(xx<0 || xx>=r || yy<0 || yy>=c) continue;
                    i=xx*c+yy;
                    if(vis[i] || s[xx][yy]=='#') continue;
                    vis[i]=1;
                    qq.push(i);
                    b[tt++]=i;
                }
            }
            for(i=0;i<tt;i++) {
                st[t]='B';
                a[t++]=b[i];
            }
            for(i=tt-1;i>0;i--) {
                st[t]='D';
                a[t++]=b[i];
                st[t]='R';
                a[t++]=b[i];
            }
        }
    }
    printf("%d\n",t);
    for(i=0;i<t;i++) printf("%c %d %d\n",st[i],a[i]/c+1,a[i]%c+1);
    return 0;
}