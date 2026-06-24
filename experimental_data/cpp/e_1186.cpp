#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-ff;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
void write(long long aa)
{
	if(aa<0) putchar('-'),aa=-aa;
	if(aa>9) write(aa/10);
	putchar(aa%10+'0');
	return;
}
long long n,m,q,sum;
long long a[1005][1005],shu[1005][1005];
char mp[1005][1005];
long long ok(long long aa)
{
	long long ff=0;
	while(aa) ff^=(aa&1),aa>>=1;
	return ff;
}
long long solve(long long aa,long long bb)
{
	long long A=aa/(n*2),B=bb/(m*2),ans=A*B*n*m*2,ff1=0,ff2=0;
	long long sa=aa-A*n*2,sb=bb-B*m*2;
	A*=2,B*=2;
	if(sa>n) ans+=B/2*n*m;
	if(sb>m) ans+=A/2*n*m;
	if(sa>n&&sb>m) 
	{
		if(ok(A)^ok(B)) ans+=n*m-sum;
		else ans+=sum;
	}
	if(sa>n) A++,sa-=n,ff1=1;
	if(sb>m) B++,sb-=m,ff2=1;
	ans+=B/2*sa*m;ans+=A/2*sb*n;
	if(ff2)
	{
		
		if(ok(A)^ok(B-1)) ans+=sa*m-shu[sa][m];
		else ans+=shu[sa][m];
	}
	if(ff1)
	{
		
		if(ok(A-1)^ok(B)) ans+=sb*n-shu[n][sb];
		else ans+=shu[n][sb];
	}
	if(ok(A)^ok(B)) ans+=sa*sb-shu[sa][sb];
	else ans+=shu[sa][sb];
	return ans;
}
int main()
{
	n=read(),m=read(),q=read();
	for(long long i=1;i<=n;++i) 
	{
		scanf("%s",mp[i]+1);
		for(long long j=1;j<=m;++j) 
		a[i][j]=mp[i][j]-'0',sum+=a[i][j],shu[i][j]=shu[i-1][j]+shu[i][j-1]-shu[i-1][j-1]+a[i][j];
	}
	for(long long i=1;i<=q;++i)
	{
		long long ax=read(),ay=read(),bx=read(),by=read();
		write(solve(bx,by)-solve(bx,ay-1)-solve(ax-1,by)+solve(ax-1,ay-1));puts("");
	}
	return 0;
}