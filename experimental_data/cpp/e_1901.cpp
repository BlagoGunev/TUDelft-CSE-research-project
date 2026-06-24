#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
//const int mod=998244353;
int n,a[500005];
ll res[500005],ans;
vector<int> e[500005];
void dfs(int d,int fa){
	vector<ll> son;
	res[d]=a[d];
	for(int i:e[d]){
		if(i==fa) continue;
		dfs(i,d);
		son.push_back(res[i]);
	} 
	ll ansd=a[d];
	sort(son.begin(),son.end());
	if(son.size()>2){
		ll sum=son[son.size()-1]+son[son.size()-2]+son[son.size()-3];
		for(int i=son.size()-4;i>=0;i--){
			if(son[i]<=0) break;
			sum+=son[i];
		}
		ansd=max(ansd,a[d]+sum);
	}
	if(son.size()>1){
		ll sum=son[son.size()-1]+son[son.size()-2];
		for(int i=son.size()-3;i>=0;i--){
			if(son[i]<=0) break;
			sum+=son[i];
		}
		res[d]=max(res[d],a[d]+sum);
		ansd=max(ansd,son[son.size()-1]+son[son.size()-2]);
	}
	if(son.size()>0){
		res[d]=max(res[d],son[son.size()-1]);
		if(son.size()>=1) ansd=max(ansd,a[d]+son[son.size()-1]);
	}
	ans=max(ans,ansd);
	//cout<<d<<' '<<res[d]<<'\n';
} 
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //srand(unsigned(time(0)));
    int T=1;
    cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=0;
		dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	
	return 0;
}