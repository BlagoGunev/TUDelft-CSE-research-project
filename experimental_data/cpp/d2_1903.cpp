#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define mod 998244353
using namespace std;
ll n,Q;
ll a[maxn],que[maxn],ans[maxn];
ll f[20][1<<20],g[20][1<<20];

ll work(ll k)
{
	ll ans=0,gg=0;
	//gg指的是当前已经gg的数字 
	for (int w=19;w>=0;w--)
	{
		ll ned=gg*(1<<w); //首先是g掉的数字肯定要加的
		//此外这一位上是0的，也得G
//		if (w<=3) cout<<ans<<" "<<f[w][ans]<<" "<<g[w][ans]<<" "<<k<<" "<<gg<<endl;
		ned+=f[w][ans]*(1<<w)-g[w][ans];
		if (k>=ned)
		{
			k-=ned;
			gg+=f[w][ans];
			ans|=(1<<w);
		} 
	}
	return ans;
}

void getans(ll wei) //最低位是wei，的个数，以及其他的和 
{
	ll mo=(1<<wei)-1; ll w=wei-1;
	for (int i=1;i<=n;i++)
	if (((a[i]>>wei)&1)==0)
	{
		f[wei][((a[i]>>wei)<<wei)]++;
		g[wei][((a[i]>>wei)<<wei)]+=(a[i]&mo);
	}
	//求超集的和 
	for (int i=0;i<20;i++)
	for (int sta=0;sta<(1<<20);sta++)
	{
		if (((sta>>i)&1)==0) g[wei][sta]+=g[wei][sta^(1<<i)],f[wei][sta]+=f[wei][sta^(1<<i)];
	}
//	if (wei==0) for (int i=0;i<8;i++) cout<<f[wei][i]<<endl;
	return;
}


int main()
{
	cin>>n>>Q;
	ll tot=0;
	for (int i=1;i<=n;i++) {cin>>a[i]; tot+=(1<<20)-a[i];}
	for (int wei=0;wei<20;wei++) getans(wei);
	for (int i=1;i<=Q;i++)
	{
		cin>>que[i];
		if (que[i]>=tot)
		{
			ans[i]=(1ll<<20)+(que[i]-tot)/n;
		}
		else
			ans[i]=work(que[i]);
	}
	for (int i=1;i<=Q;i++) cout<<ans[i]<<endl;
}