#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200007];
ll n,m,k,cnt,ans,sum,tmp,mx=-1e9,x,y,q;
map<ll,ll>mp;
int main(){
	cin>>q;
	while(q--){
		cin>>n;ans=0,mp.clear();
		for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]++;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			cnt=1;
			for(int j=1;j<=30;j++){
				cnt*=2,x=a[i]+j;
				if(x/a[i]==cnt)ans+=mp[x];
			}
			ans+=mp[a[i]]-1,mp[a[i]]--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}