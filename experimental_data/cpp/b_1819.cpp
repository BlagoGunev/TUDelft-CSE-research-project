// LUOGU_RID: 160739255
#include <bits/stdc++.h>
using namespace std;
struct dd{
	long long a,b;
}xx[200005];
long long n,sum,ma1,ma2;
vector<pair<long long,long long> >ans;
bool ok(long long x,long long y,int o){
	map<pair<long long,long long>,long long,greater<> >m1,m2;
	for(int i=1;i<=n;i++){
		m1[make_pair(xx[i].a,xx[i].b)]++;
		m2[make_pair(xx[i].b,xx[i].a)]++;
	}
	for(int c=0;c<n;o^=1){
		if(o){
			if(m1.begin()->first.first!=x) return 0;
			while(m1.begin()->first.first==x){
				y-=m1.begin()->first.second;
				c++;
				auto now1=make_pair(x,m1.begin()->first.second);
				auto now2=make_pair(m1.begin()->first.second,x);
				if(!--m2[now2]){
					m2.erase(now2);
				}
				if(!--m1[now1]){
					m1.erase(now1);
				}
			}
		}
		else{
			if(m2.begin()->first.first!=y) return 0;
			while(m2.begin()->first.first==y){
				x-=m2.begin()->first.second;
				c++;
				auto now1=make_pair(y,m2.begin()->first.second);
				auto now2=make_pair(m2.begin()->first.second,y);
				if(!--m1[now2]){
					m1.erase(now2);
				}
				if(!--m2[now1]){
					m2.erase(now1);
				}
			}
		}
	}
	return 1;
}
void solve(){
	cin>>n;
	ma1=0,ma2=0;
	sum=0;
	for(int i=1;i<=n;i++){
		cin>>xx[i].a>>xx[i].b;
		ma1=max(ma1,xx[i].a);
		ma2=max(ma2,xx[i].b);
		sum+=xx[i].a*xx[i].b;
	}
	ans.clear();
	if(!(sum%ma1)&&ok(ma1,sum/ma1,1))ans.push_back({ma1,sum/ma1});
	if(ma1!=sum/ma2&&!(sum%ma2)&&ok(sum/ma2,ma2,0))ans.push_back({sum/ma2,ma2});
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	long long t;
	cin>>t;
	while(t--){
		solve();
	}
}