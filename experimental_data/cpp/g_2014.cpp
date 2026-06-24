#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef pair<int,int> pii;
const int MAX=1e18;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<pii>v,a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		v.push_back(a[i]);
		int now=a[i].first,mx;
		if(i!=n-1) mx=a[i+1].first;
		else mx=MAX;
		int sum=0;
		while(!v.empty()){
			int num=v.back().first,cnt=v.back().second;
			int l=1,r=cnt;
			while(l<=r){
				int mid=(l+r)>>1;
				int d=(sum+mid)/m;
				if((sum+mid)%m!=0) d++;
				if(now+d-1<mx&&now+d-1<=num+k-1){
					l=mid+1;
				}else{
					r=mid-1;
				} 
			}
			sum+=r;
			if(r==cnt){
				v.pop_back();
			}else{
				v.back().second-=r;
				break;
			}
		}
		ans+=sum/m;
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}