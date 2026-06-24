#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 0x3FFFFFF
#define MN 100005
using namespace std;
int a[MN],b[MN],pos[MN];
int n,L,R,pre;

inline int abs(int x) {return x<0?-x:x;}
inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

//inline void dal(char ch,int x,int y)
//{
//	if (ch=='#'||ch=='*'||ch=='&') dis[x][1]=min(dis[x][1],y);
//	else if (ch>='a' && ch<='z') dis[x][2]=min(dis[x][2],y);
//	else if (ch>='0' && ch<='9') dis[x][3]=min(dis[x][3],y);
//}
//bool pd()
//{
//	for (int i=1;i<=n;++i) if (a[i]) return false;
//	return true;
//}
//bool cmp(int x,int y) {return b[x]<b[y] || b[x]==b[y] && di[x]<0 && di[y]>0;}

int main()
{
//	freopen("test.in","r",stdin);
	register int i;
	n=read(); L=read(); R=read();
	for (i=1;i<=n;++i) a[i]=read();
	for (i=1;i<=n;++i) pos[read()]=i;
	b[pos[1]]=L; pre=L-a[pos[1]];
	for (i=2;i<=n;++i)
	{
		if (a[pos[i]]+pre+1<L) b[pos[i]]=L;
		else if (a[pos[i]]+pre+1>R) return 0*printf("-1");
		else b[pos[i]]=a[pos[i]]+pre+1;
		pre=b[pos[i]]-a[pos[i]];
	}
	for (i=1;i<=n;++i) printf("%d ",b[i]);
}