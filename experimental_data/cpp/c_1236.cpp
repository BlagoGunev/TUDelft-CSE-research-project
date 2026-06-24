#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IL inline
#define RG register
#define gi geti<int>()
#define gl geti<ll>()
#define gc getchar()
#define File(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
template<typename T>IL bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
template<typename T>IL bool chkmin(T &x,const T &y){return x>y?x=y,1:0;}
template<typename T>
IL T geti()
{
	RG T xi=0;
	RG char ch=gc;
	bool f=0;
	while(!isdigit(ch))ch=='-'?f=1:f,ch=gc;
	while(isdigit(ch))xi=xi*10+ch-48,ch=gc;
	return f?-xi:xi;
}
template<typename T>
IL void pi(T k,char ch=0)
{
	if(k<0)k=-k,putchar('-');
	if(k>=10)pi(k/10);
	putchar(k%10+'0');
	if(ch)putchar(ch);
}
/*
IL unsigned int LOG2(unsigned int x)
{
	unsigned int ret;
	__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));
	return ret;
}
*/
const int N=3e2+7;
int a[N][N];
int main(void)
{
	#ifndef ONLINE_JUDGE
//	File("");
	#endif
	int n=gi;
	int cnt=0;
	for(int j=1;j<=n;++j)
	{
		if(j&1)
			for(int i=1;i<=n;++i)a[i][j]=++cnt;
		else for(int i=n;i;--i)a[i][j]=++cnt;
	}
	for(int i=1;i<=n;++i,putchar('\n'))
		for(int j=1;j<=n;++j)
		{
			pi(a[i][j],' ');
		}
	return 0;
}