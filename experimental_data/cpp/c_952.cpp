#include<cstdio>
#include<algorithm> 
#include<cstring>
#include<cmath>
#include<cstdlib>
#define LL long long
using namespace std;
const int N=15;
int n,a[N];
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)
		if(abs(a[i]-a[i-1])>=2)
			{printf("NO");return 0;}
	printf("YES");
	return 0;
}