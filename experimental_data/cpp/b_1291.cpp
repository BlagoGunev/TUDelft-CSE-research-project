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
int a[300010];
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int T=read();
    while(T--)
    {
    	int n=read();bool bk=true;
    	for(int i=1;i<=n;i++)a[i]=read();
	    for(int i=1;i<=n;i++)if(a[i]<min(i-1,n-i)){bk=false;break;}
	    if(n%2==0 && max(a[n/2],a[n/2+1])<n/2){bk=false;}
	    if(bk==false)puts("No");
	    else puts("Yes");
    }
    return 0;
}