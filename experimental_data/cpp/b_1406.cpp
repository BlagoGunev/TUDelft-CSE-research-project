#include<bits/stdc++.h>
using namespace std;
#define infll 0x7f7f7f7f7f7f7f7f
#define inf 0x7f7f7f7f
#define Maxn 100005
typedef long long ll;
inline int rd()
{
	 int x=0;
     char ch,t=0;
     while(!isdigit(ch = getchar())) t|=ch=='-';
     while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
     return x=t?-x:x;
}
ll maxll(ll x,ll y){ return x>y?x:y; }
ll minll(ll x,ll y){ return x<y?x:y; }
int t,n;
int a[Maxn];
ll ans;
bool cmp(int x,int y){ return x<y; }
int main()
{
     //freopen(".in","r",stdin);
     //freopen(".out","w",stdout);
	 t=rd();
	 while(t--)
	 {
	 	 n=rd(),ans=-infll;
	 	 for(int i=1;i<=n;i++) a[i]=rd();
	 	 sort(a+1,a+n+1,cmp);
	 	 ans=maxll(ans,1ll*a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]);
	 	 ans=maxll(ans,1ll*a[n]*a[n-1]*a[n-2]*a[1]*a[2]);
	 	 ans=maxll(ans,1ll*a[n]*a[1]*a[2]*a[3]*a[4]);
	 	 printf("%lld\n",ans);
	 }
     //fclose(stdin);
     //fclose(stdout);
     return 0;
}