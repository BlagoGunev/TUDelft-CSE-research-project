#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=100005;
int n;
LL a[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void solve()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	repd(i,n-1,1) a[i]+=a[i+1];
	LL ans=a[1];
	rep(i,2,n) if(a[i]>0) ans+=a[i];
	printf("%lld\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}