#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=2e5+10;
const int mod=1e9+7;
vector<int> a[N];
struct ll{
	int l,r,cnt;
	bool friend operator<(const ll a,const ll b){
		return  a.l>b.l;
	}
};
void solve(){
	set<pair<int,int>> s;
	set<pair<int,ll>> t;
	int n;
	cin>>n;
	for(int i=0;i<=n;i++) a[i].clear();
	i64 m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x].push_back(i);
	}
	cin>>m;
	s.insert({1,n});
	int cnt=0;
	t.insert({n,{1,n,0}});
	for(int i=n;i>=0;i--){
		for(auto y:a[i]){
			auto u=s.upper_bound({y+1,0});
			u--;
			auto [o,p]=*u;
	//		cout<<o<<" "<<p<<" "<<y<<endl;
			s.erase(u);
			auto k=*t.lower_bound({p-o+1,{o,p,-n-n}});
			t.erase(k);
			k.second.cnt+=cnt;
			t.insert(k);
			if(o<=y-1){
			s.insert({o,y-1});
			t.insert({y-o,{o,y-1,-cnt}});
			}
			if(y+1<=p){
			s.insert({y+1,p});
			t.insert({p-y,{y+1,p,-cnt}});
			}
		}
		cnt+=1;
	}
	i64 ans=0;
	while(t.size()){
		auto u=t.end();
		u--;
		auto k=*u;
		t.erase(u);
		if(m<=1) break;
		if(k.first<=1) break;
		if(m>=(i64)k.first*k.second.cnt){
			ans+=(i64)(k.first-1)*k.second.cnt;
			m-=(i64)k.first*k.second.cnt;
		}else{
			i64 p=m/(k.first);
			ans+=p*(k.first-1);
			m-=p*(k.first);
			k.second.cnt-=p;
			k.first=min(k.first,(int)m);
			t.insert(k);
		}
	}
	cout<<ans<<endl;
	 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}