#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io
{
	int F()
	{
		 int F=1,n=0;
		 char ch;
		 while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		 ch=='-'?F=0:n=ch-'0';
		 while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		 return F?n:-n;
	}
	long long G()
	{
		 long long F=1,n=0;
		 char ch;
		 while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		 ch=='-'?F=0:n=ch-'0';
		 while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		 return F?n:-n;
	}
}
const int M=998244353;
int ex(int b,int e=M-2)
{
	int ans=1;
	for(;e;e>>=1,b=(long long)b*b%M)
		if(e&1)ans=(long long)b*ans%M;
	return ans;
}
int B=20,N=1048576;
int rev[1111111];
int w[1111111];
int W[22];
void kn(int l)
{
	B=0;
	while(1<<B<l)++B;
	N=1<<B;
}
void DFT(int* a,int l)
{
	kn(l);
	for(register int i=1;i<N;++i)rev[i]=rev[i>>1]>>1|(i&1)<<B-1;
	for(register int i=1;i<N;++i)
		if(i<rev[i])std::swap(a[i],a[rev[i]]);
	for(register int T=1;T<N;T<<=1)
		for(register int i=0;i<N;i+=T+T)
			for(register int j=0,*x=a+i,*y=a+i+T,*w=::w+T;j<T;++j,++x,++y,++w)
			{
				int tmp=1ll* *y * *w%M;
				*y=(*x+M-tmp)%M;
				*x=(*x+tmp)%M;
			}
}
void IDFT(int* a,int l)
{
	std::reverse(a+1,a+N);
	DFT(a,l);
	int iv=ex(N);
	for(register int i=0;i<N;++i)
		a[i]=1ll*iv*a[i]%M;
}
int d[1111111];
int main()
{
	int n=io::F(),k=io::F();
	for(register int i=1;i<=k;++i)d[io::F()]=1;
	
	for(register int i=0;i<=B;++i)W[i]=ex(3,(M-1)>>i);
	for(register int i=0;i<B;++i)
	{
		w[1<<i]=1;
		for(register int j=(1<<i)+1;j<1<<i+1;++j)
			w[j]=1ll*w[j-1]*W[i+1]%M;
	}
	
	DFT(d,1000000);
	for(register int i=0;i<N;++i)
		d[i]=ex(d[i],n/2);
	IDFT(d,1000000);
	int ans=0;
	for(register int i=0;i<=n*9/2;++i)
		ans=(ans+1ll*d[i]*d[i])%M;
	printf("%d\n",ans);
	return 0;
}