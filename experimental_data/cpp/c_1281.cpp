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
const int mod=1000000007;
inline int ad(int x){return x>=mod?x-mod:x;}
inline int dec(int x){return x<0?x+mod:x;}
char ss[1000010];
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read();scanf("%s",ss+1);int len=strlen(ss+1);
		int now=len;
		for(int i=1;i<=n;i++)
		{
			int uf=now,p=i+1,cnt=2;
			while(now<n && cnt<=ss[i]-'0')
			{
				ss[++now]=ss[p];
				p++;if(p>uf)p=i+1,cnt++;
			}
			len=ad(1LL*dec(len-i)*(ss[i]-'0')%mod+i);
		}pr2(len);
	}
	return 0;
}