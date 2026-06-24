#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#define pr pair
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pll pr<ll,ll>
#define pii pr<int,int>
#define piii pr<int,pii>
using namespace std;
map<int,int> p;
pii v[100005];
int z;
void sl()
{
	int n,k;
	cin>>n>>k;
	int x;
	z=0;
	p.clear();
	while(n--)
	{
		cin>>x;
		p[x]++;
	}
	for(pii i:p) v[z++]=mp(i.s,i.f);
	sort(v,v+z);
	int ans=z;
	for(int i=0;i<z;i++)
	{
		if(v[i].f>k) break;
		k-=v[i].f;
		ans--;
	}
	ans=max(ans,1);
	cout<<ans<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) sl();
	return 0;
}