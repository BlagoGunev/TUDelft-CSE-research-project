// LUOGU_RID: 161964433
#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define LL long long
int T,n,k,t,cnt,c[N],p[N];
__int128 sum,ans,S[N],b[N];
LL m,a[N],g[N];
set<LL>s;
void out(__int128 x)
{
	if(x>9)out(x/10);
	printf("%c",(char)('0'+x%10));
}
void init()
{
	s.clear();
	t=cnt=sum=ans=0;
	scanf("%d%lld%d",&n,&m,&k);
	k++;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
		if(s.count(a[i]))b[++cnt]=a[i];
		s.insert(a[i]);
	}
	n=0;
	for(auto i:s)a[++n]=i;
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;i++)b[i]+=b[i-1];
	if(cnt>=k-1)ans=max(ans,sum-b[k-1]);
	for(int i=1;i<=n;i++){
		S[i]=S[i-1]+a[i];
		g[i]=__gcd(a[i],g[i-1]);
		if(g[i]!=g[i-1])p[++t]=i;
		if(cnt>=k-i && k>=i)ans=max(ans,sum+g[i]-S[i]-b[k-i]);
	}
	p[t+1]=n+1;
	for(int i=1;i<=t;i++){
		__int128 mx=-sum;
		for(int j=p[i+1];j<=n;j++)
			mx=max(mx,(__int128)__gcd(g[p[i]],a[j])-a[j]);
		for(int j=p[i];j<min(p[i+1],k);j++)
			if(k-j-1<=cnt)ans=max(ans,sum+mx-S[j]-b[k-j-1]);
	}
	out(ans);
	printf("\n");
}
int main()
{
	scanf("%d",&T);
	while(T--)init();
}