#include<cstdio>
#include<cctype>
using namespace std;
#define re register int
const int INF=0x3f3f3f3f;
int read()
{
	int f=0,x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		f=f|(c=='-');
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
int main()
{
	int n=read(),l=read(),a=read();
	int f=0,ans=0;
	for(re i=1;i<=n;i++)
	{
		int t=read();
		ans+=(t-f)/a;
		f=read()+t;
	}
	ans+=(l-f)/a;
	printf("%d\n",ans);
	return 0;
}