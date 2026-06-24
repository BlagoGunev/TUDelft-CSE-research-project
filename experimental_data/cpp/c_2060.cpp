#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,k,i,a,ans;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>k;
		ans=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(mp[k-a]>0)
			{
				mp[k-a]--;
				ans++;
			}
			else mp[a]++;
		}
		cout<<ans<<'\n';
		mp.clear();
	}
	return 0;
}