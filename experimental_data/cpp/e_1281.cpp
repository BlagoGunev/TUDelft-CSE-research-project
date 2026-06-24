#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int stack[20];
inline void write(int x)
{
	if(x<0){putchar('-');x=-x;}
	if(!x){putchar('0');return;}
	int top=0;
	while(x)stack[++top]=x%10,x/=10;
	while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
struct node
{
	int x,y,c,next;
}a[400010];int len,last[200010];
inline void ins(int x,int y,int c)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
int n,tot[200010];
long long s1,s2;
inline void dfs(int x,int fa)
{
	tot[x]=1;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y==fa)continue;
		dfs(y,x);
		if(tot[y]&1)s1+=a[k].c;
		s2+=1LL*a[k].c*min(tot[y],2*n-tot[y]);
		tot[x]+=tot[y];
	}
}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		s1=s2=len=0;for(int i=1;i<=2*n;i++)last[i]=0;
		n=read();
		for(int i=1;i<2*n;i++)
		{
			int x=read(),y=read(),c=read();
			ins(x,y,c),ins(y,x,c);
		}dfs(1,0);
		printf("%lld %lld\n",s1,s2);
	}
	return 0;
}