#include <bits/stdc++.h>
using namespace std;
#define N 2000005
int T,n,a[N],ps[N],ans[N];bool vs[N];
void slv()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) ans[i]=vs[i]=0,scanf("%d",&a[i]);
	for(int i=1;i<n;i++) if (a[i]>a[i+1])
	{
		printf("NO\n");
		return;
	 } 
	if(a[1]>n) {printf("NO\n");return;}a[n+1]=n+1;vs[a[1]]=1;
	for(int i=1,t=1;i<=n;++i)
		if(a[i]<a[i+1]) vs[a[i+1]]=1,ps[i]=a[i+1];
		else
		{
			t=max(t,i+1);while(t<=n && vs[t]) ++t;
			if(t>a[i+1]) {printf("NO\n");return;}vs[t]=1;ps[i]=t;
		}
	for(int i=n,t=n;i;--i) if(a[i]==a[i+1])
	{
		while(t>a[1] && vs[t]) --t;if(t<=a[1]) break;
		if(t>a[i]) {printf("NO\n");return;}
		if(t>ps[i]) vs[ps[i]]=0,vs[t]=1,ps[i]=t;
	}for(int i=n;i>a[1];--i) if(!vs[i]) {printf("NO\n");return;} 
	for(int i=1;i<=n;++i) if(!ans[i])
	{for(int j=i;j<=n;j=ps[j]) ans[j]=i;}
	printf("YES\n");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);putchar('\n');
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}