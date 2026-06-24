#include<cstdio>
#include<cctype>
#include<algorithm>
//#include<ctime>
#define rg register
typedef long long ll;
template <typename T> inline T max(const T a,const T b){return a>b?a:b;}
template <typename T> inline T min(const T a,const T b){return a<b?a:b;}
template <typename T> inline void mind(T&a,const T b){a=a<b?a:b;}
template <typename T> inline void maxd(T&a,const T b){a=a>b?a:b;}
template <typename T> inline T abs(const T a){return a>0?a:-a;}
template <typename T> inline void swap(T&a,T&b){T c=a;a=b;b=c;}
//template <typename T> inline void swap(T*a,T*b){T c=a;a=b;b=c;}
template <typename T> inline T gcd(const T a,const T b){if(!b)return a;return gcd(b,a%b);}
template <typename T> inline T lcm(const T a,const T b){return a/gcd(a,b)*b;}
template <typename T> inline T square(const T x){return x*x;};
template <typename T> inline void read(T&x)
{
	char cu=getchar();x=0;bool fla=0;
	while(!isdigit(cu)){if(cu=='-')fla=1;cu=getchar();}
	while(isdigit(cu))x=x*10+cu-'0',cu=getchar();
	if(fla)x=-x;
}
template <typename T> inline void printe(const T x)
{
	if(x>=10)printe(x/10);
	putchar(x%10+'0');
}
template <typename T> inline void print(const T x)
{
	if(x<0)putchar('-'),printe(-x);
	else printe(x);
}
int n,a,dqz=100001,sgz=100001,dqcx=-100000000,sgcx=-100000000,ans=0;
int main()
{
	read(n);
	for(rg int i=1;i<=n;i++)
	{
		read(a);
		if(a==dqz)
		{
			dqcx++;
		}
		else
		{
			sgz=dqz;
			sgcx=dqcx;
			dqz=a;
			dqcx=1;
		}
		maxd(ans,min(dqcx,sgcx)<<1);
	}
	print(ans);
	return 0;
}