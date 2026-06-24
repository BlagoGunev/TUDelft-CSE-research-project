#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define CL fclose(stdin),fclose(stdout)
namespace io
{
	int F()
	{
		int n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
	long long G()
	{
		long long n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
}
char f0[99]={"What are you doing at the end of the world? Are you busy? Will you save us?"};
char f1[99]={"What are you doing while sending \""};//34
char f2[99]={"\"? Are you busy? Will you send \""};//32
char f3[99]={"\"?"};//2
long long len[60];
char qu(int n,long long k)
{
	start:;
	if(n==0)
	{
		if(k>75)return '.';
		return f0[k-1];
	}
	if(n<=54)
	{
		if(len[n]<k)return '.';
		if(k<=34)return f1[k-1];
		char c=qu(n-1,k-=34);
		if(c!='.')return c;
		k-=len[n-1];
		if(k<=32)return f2[k-1];
		c=qu(n-1,k-=32);
		if(c!='.')return c;
		k-=len[n-1];
		return f3[k-1];
	}
	if(k<=34)return f1[k-1];
	--n;
	k-=34;
	goto start;
}
int main()
{
	int q=io::F();
	len[0]=75;
	for(register int i=1;i<=58;++i)len[i]=len[i-1]*2+68;
	while(q--)
	{
		int n=io::F();
		long long k=io::G();
		putchar(qu(n,k));
	}
	return 0;
}