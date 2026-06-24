#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
int a[200010];
int top,sta[200010];
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
   	int T=read();
   	while(T--)
   	{
   		int n=read(),m=read();long long sum=0;
   		for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
   		if(sum%2!=m%2){puts("NO");continue;}
   		long long tot=0;top=0;
   		for(int i=1;i<=n;i++)
   		{
   			tot+=a[i];
   			if(tot&1)sta[++top]=i,tot=0;
   		}
   		if(top>=m)
   		{
   			puts("YES");
   			for(int i=1;i<m;i++)pr1(sta[i]);
   			pr2(n);
   		}
   		else puts("NO");
   	}
	return 0;
}