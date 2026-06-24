#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#define ll long long
#define eps 1e-8
#define iinf 0x3f3f3f3f
#define linf (1ll<<60)
#define dinf 1e100
#define maxn 300010
#define cl(x) memset(x,0,sizeof(x))
using namespace std;
int read(int x=0)
{
	int c, f=1;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-48;
	return f*x;
}
struct segment
{
	int l, r;
	segment(int a, int b){l=a,r=b;}
	segment(){}
}a[maxn], s1[maxn], s2[maxn];
int N;
segment inter(segment l1, segment l2)
{
	if(l1.l==-1 or l2.l==-1)return segment(-1,-1);
	if(l1.l>l2.l)swap(l1,l2);
	if(l1.r<l2.l)return segment(-1,-1);
	return segment(l2.l,min(l1.r,l2.r));
}
void init()
{
	int i;
	N=read();
	for(i=1;i<=N;i++)a[i].l=read(), a[i].r=read();
	s1[0]=a[0]=s2[N+1]=a[N+1]=segment(0,iinf);
	for(i=1;i<=N;i++)s1[i]=inter(s1[i-1],a[i]);
	for(i=N;i;i--)s2[i]=inter(s2[i+1],a[i]);
//	for(i=1;i<=N;i++)printf("[%d,%d]\n",s1[i].l,s1[i].r);
//	for(i=1;i<=N;i++)printf("[%d,%d]\n",s2[i].l,s2[i].r);
}
void work()
{
	int ans=0, i;
	segment tmp;
	for(i=1;i<=N;i++)
	{
		tmp=inter(s1[i-1],s2[i+1]);
		ans=max(ans,tmp.r-tmp.l);
	}
	printf("%d\n",ans);
}
int main()
{
	init();
	work();
	return 0;
}