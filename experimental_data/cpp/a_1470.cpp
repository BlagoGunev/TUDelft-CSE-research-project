#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 300005
#define Min(x,y)((x)<(y)?x:y)
#define For(i,x,y)for(i=x;i<=(y);i++)
int k[N],c[N];
int read()
{
	int A;
	bool K;
	char C;
	C=A=K=0;
	while(C<'0'||C>'9')K|=C=='-',C=getchar();
	while(C>'/'&&C<':')A=(A<<3)+(A<<1)+(C^48),C=getchar();
	return(K?-A:A);
}
int main()
{
	ll ans;
	int t,n,m,i;
	t=read();
	while(t--)
	{
		n=read(),m=read();
		For(i,1,n)k[i]=read();
		For(i,1,m)c[i]=read();
		For(i,1,n)k[i]=c[k[i]];
		ans=0;
		sort(k+1,k+n+1,greater<int>());
		sort(c+1,c+m+1);
		For(i,1,Min(n,m))ans+=Min(k[i],c[i]);
		For(i,Min(n,m)+1,n)ans+=k[i];
		cout<<ans<<endl;
	}
	return 0;
}