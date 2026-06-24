// LUOGU_RID: 96658454
/*

¤ï¤ó¤ï¤ó¡­¡­¤ï¤ó¤À¤Û©`¤¤¤Ã¡î

Wonderhoy!

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef double DB;

char buf[1<<21],*p1=buf,*p2=buf;

#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)

int read()

{

	int x=0;

	char c=getchar();

	while(c<'0' || c>'9')	c=getchar();

	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();

	return x;

}

void write(int x)

{

	if(x>9)	write(x/10);

	putchar(x%10+'0');

}

int n,m;

int a[1005][1005],ans[1005][1005];

int sum[4000005],cnt[4000005];

struct unionFindSet{

	int fa[4000005];

	void makeSet(int up){for(int i=0;i<=up;++i)	fa[i]=i,sum[i]=cnt[i]=1;}

	int findSet(int x){return x==fa[x]?x:fa[x]=findSet(fa[x]);}

	void unionSet(int x,int y,int w)

	{

		if(!y)	return ;

		int xx=findSet(x),yy=findSet(y);

		if(xx==yy)	return ;

		fa[xx]=yy;

		sum[yy]=(sum[yy]+(cnt[xx]&1)*(w&1))&1,cnt[yy]+=cnt[xx];

	}

}ufs;

int nxt[4000005][2],id[1005][1005][4];

struct node{

	int x,y,w;

	node(int X=0,int Y=0,int W=0){x=X,y=Y,w=W;}

	inline bool operator < (node ano) const {return w<ano.w;}

}st[1000005];

int pid,cid;

int main(){

	n=read(),m=read();

	for(int i=1;i<=n;++i)

	{

		for(int j=1;j<=m;++j)

		{

			a[i][j]=read();

			st[++cid]=node(i,j,a[i][j]);

			for(int k=0;k<4;++k)	id[i][j][k]=++pid;

		}

	}

	sort(st+1,st+1+(n*m));

	for(int i=1;i<=n;++i)

	{

		for(int j=1;j<=m;++j)

		{

			nxt[id[i][j][0]][0]=id[i+1][j][0];

			nxt[id[i][j][1]][0]=id[i][j-1][1];

			nxt[id[i][j][2]][0]=id[i-1][j][2];

			nxt[id[i][j][3]][0]=id[i][j+1][3];

			nxt[id[i][j][0]][1]=id[i][j-1][1];

			nxt[id[i][j][1]][1]=id[i-1][j][2];

			nxt[id[i][j][2]][1]=id[i][j+1][3];

			nxt[id[i][j][3]][1]=id[i+1][j][0];

		}

	}

	ufs.makeSet(4*n*m);

	for(int i=1;i<=n*m;++i)

	{

		int x=st[i].x,y=st[i].y,w=st[i].w&1,p=0;

		for(int k=0;k<4;++k)	p+=2+w*cnt[id[x][y][k]]-sum[id[x][y][k]];

		ans[x][y]=p&1;

		for(int k=0;k<4;++k)	ufs.unionSet(id[x][y][k],nxt[id[x][y][k]][p&1],w);

	}

	for(int i=1;i<=n;++i,puts(""))	for(int j=1;j<=m;++j)	putchar(ans[i][j]^'0');

	return 0;

}