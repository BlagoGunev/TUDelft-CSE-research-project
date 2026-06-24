/* 
 * Author: Imagine_I
 * Time: 2019-10-13 18:37:04
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int maxn=1e6+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int a1[maxn],a2[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,k;
	cin>>n>>k;
	ll ans=(n+1)*n/2;
	for(int i=1;i<=n;i++) a1[i]=i;
	for(int i=1;i<=n;i++) a2[i]=i;
	if(ans>k)
	{
		cout<<-1<<'\n';
		return 0;
	}
	ll up=n/2;
	ll now=n-1;
	for(int i=1;i<=up;i++)
	{
		if(ans+now<=k)
		{
			ans+=now;
			swap(a2[i],a2[i+now]);
		}
		else
		{
			swap(a2[i],a2[i+k-ans]);
			ans=k;
			break;
		}
		now-=2;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) cout<<a1[i]<<(i==n?'\n':' ');
	for(int i=1;i<=n;i++) cout<<a2[i]<<(i==n?'\n':' ');

	return 0;
}