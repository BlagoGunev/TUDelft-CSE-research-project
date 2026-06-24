#include <cstdio>
#include <cctype>
#include <climits>
#include <algorithm>
using namespace std;

#define repu(i,a,b) for (int i=(a);i<=(b);i++)
#define repd(i,a,b) for (int i=(a);i>=(b);i--)

const int N=200010;
const int MAX=INT_MAX;

int n;
char s[N];
int x[N];
int res=MAX;

inline int read(void)
{
	int x=0,f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

int main(void)
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	
	n=read();
	scanf("%s",&s[1]);
	repu(i,1,n) x[i]=read();
	
	int tp1=0,tp2;
	repu(i,1,n)
		if (s[i]=='L')
		{
			if (tp1>0)
			{
				tp2=x[i]-x[tp1]>>1;
				res=min(res,tp2);
			}
		}
		else tp1=i;
	tp1=n+1;
	repd(i,n,1)
		if (s[i]=='R')
		{
			if (tp1!=n+1)
			{
				tp2=x[tp1]-x[i]>>1;
				res=min(res,tp2);
			}
		}
		else tp1=i;
	
	if (res==MAX) printf("-1\n");
	else printf("%d\n",res);
		
	return 0;
}