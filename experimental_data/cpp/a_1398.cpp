// 给我这个菜鸡 AC 我就给你吃糖 qaq
// puts("C12H22O11");
#include<stdio.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int NR=5e4+5;
const int MR=1e5+5;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
inline int read()
{
	int x=0;
	int bei=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			bei=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*bei;
}
int a[NR];
int main()
{
	int t=read();
	while(t--)
	{
		int n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		if(a[1]+a[2]<=a[n])
			printf("1 2 %d\n",n);
		else
			puts("-1");
	}
	return 0;
}