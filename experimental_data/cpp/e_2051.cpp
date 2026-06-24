#include<bits/stdc++.h>
using namespace std;
int t;
int n,k;
map<long long,int>mp,st;
long long a[200005],b[200005];
int m;
bool check(long long x){
	long long ret=0;
	for(int i=1;i<=n;i++){
		if(x<=a[i])continue;
		
	}
}
int main() {
	cin>>t;
	while(t--){
		cin>>n>>k;
		mp.clear();
		st.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]+=0;
			mp[a[i]+1]++;
			st[a[i]]+=0;
			st[a[i]+1]+=0;
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
			mp[b[i]]+=0;
			st[b[i]]+=0;
			mp[b[i]+1]--;
			st[b[i]+1]--;
		}
		long long ans=0,pe=n,cnt=0;
		for(auto to:mp){
			cnt+=to.second;
			pe+=st[to.first];
			if(cnt>k)continue;
			ans=max(ans,1ll*pe*to.first);
		}
		cout<<ans<<endl;
	}
	return 0;
}