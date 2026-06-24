#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL long long
using namespace std;
inline int max(const int a,const int b){return a>b?a:b;}
inline int min(const int a,const int b){return a<b?a:b;}
inline int abs(const int a){return a>0?a:-a;}
inline void swap(int&a,int&b){int c=a;a=b;b=c;}
inline void read(int&x)
{
	char cu=getchar();x=0;bool fla=0;
	while(cu<'0'||cu>'9'){if(cu=='-')fla=1;cu=getchar();}
	while('0'<=cu&&cu<='9')x=x*10+cu-'0',cu=getchar();
	if(fla)x=-x; 
}
void printe(const int x)
{
	if(x>=10)printe(x/10);
	putchar(x%10+'0');
}
inline void print(const int x)
{
	if(x<0)putchar('-'),printe(-x);
	else printe(x);
}
const int maxn=300001;
int n,a[maxn],num[maxn];
int edd;
int main()
{
	read(n);
	edd=n+1;
	for(int i=1;i<=n;i++)read(a[i]);
	print(1),putchar(' ');
	for(int i=1;i<=n;i++)
	{
		num[a[i]]=1;
		while(num[edd-1])edd--;
		print(i-(n-edd)),putchar(' ');
	}
	return 0;
}