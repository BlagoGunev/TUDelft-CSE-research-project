#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r)for(int i=l;i<=r;i++)
#define pii pair<int,int>
#define mp make_pair
#define N 1010
const int dx[]={-1,-1,0,1,1,1,0,-1};
const int dy[]={0,1,1,1,0,-1,-1,-1};
int n,m,Q,S,T,cnt,flag;
int ch[N][N],id[N][N];
char s[N];
int fa[N*N];
set<pii>se;
int find(int x){return x==fa[x] ? x : fa[x]=find(fa[x]);}
int find2(int x){return x==fa[x] ? x : find(fa[x]);}
pii get(int x,int y){return mp(min(x,y),max(x,y));}
void merge(int x,int y){fa[find2(x)]=find2(y);}
int K,top,ans;
int bx[N],by[N],st[N];
int main()
{
scanf("%d%d%d",&n,&m,&Q);
for(int i=1;i<=n;i++){
scanf("%s",s+1);
for(int j=1;j<=m;j++)ch[i][j]=(s[j]=='#');
}
S=++cnt;T=++cnt;
rep(i,1,n)rep(j,1,m)id[i][j]=++cnt;
rep(i,1,n){ch[i][0]=ch[i][m+1]=1;id[i][0]=S;id[i][m+1]=T;}
rep(i,1,m){ch[0][i]=ch[n+1][i]=1;id[0][i]=T;id[n+1][i]=S;}
rep(i,1,cnt)fa[i]=i;
rep(i,1,n)rep(j,1,m)if(ch[i][j]){
rep(k,0,7){
int nx=i+dx[k],ny=j+dy[k];
if(ch[nx][ny])fa[find(id[i][j])]=find(id[nx][ny]);
}
}
rep(i,1,n)rep(j,1,m){
if(i==1&&j==1)continue;
if(i==n&&j==m)continue;
rep(k,0,7)rep(l,k+1,7){
int nx=i+dx[k],ny=j+dy[k];
int mx=i+dx[l],my=j+dy[l];
se.insert(get(find(id[nx][ny]),find(id[mx][my])));
if(get(find(id[nx][ny]),find(id[mx][my]))==get(find(S),find(T)))flag=1,i=n+1,j=m+1;
}
}
if(flag){rep(i,1,Q)puts("NO");return 0;}
 
while(Q--){
scanf("%d",&K);
top=0;
rep(i,1,K){
scanf("%d%d",&bx[i],&by[i]);ch[bx[i]][by[i]]=1;
st[++top]=find(id[bx[i]][by[i]]);
rep(k,0,7){
int nx=bx[i]+dx[k],ny=by[i]+dy[k];
if(ch[nx][ny])st[++top]=find(id[nx][ny]);
}
}
st[++top]=find(S);st[++top]=find(T);
sort(st+1,st+top+1);
top=unique(st+1,st+top+1)-st-1;
rep(i,1,K)rep(k,0,7){
int nx=bx[i]+dx[k],ny=by[i]+dy[k];
if(ch[nx][ny])merge(id[nx][ny],id[bx[i]][by[i]]);
}
ans=1;
rep(i,1,top)if(find2(st[i])==find2(S))
rep(j,1,top)if(find2(st[j])==find2(T)&&se.find(get(st[i],st[j]))!=se.end())
ans=0;
puts(ans ? "YES" : "NO");fflush(stdout);
rep(i,1,K)ch[bx[i]][by[i]]=0;
while(top)fa[st[top]]=st[top],top--;
}
return 0;
}