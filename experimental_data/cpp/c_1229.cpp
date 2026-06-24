#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;

// #define TT() printf("%.4f sec\n", (double) clock() / CLOCKS_PER_SEC )
#define Fi first
#define Se second
#define rep(i, n) for(ll i=0;i<n;i++)
#define repp(i, n) for(ll i=1;i<=n;i++)

#define INF 987654321
#define IINF 987654321987654321

int n,m,deg[100100];
vector<int> ed[100100],ba[100100];

int main(){
	scanf("%d%d",&n,&m);
	repp(i,m){
		int x,y; scanf("%d%d",&x,&y);
		ed[x].push_back(y); ed[y].push_back(x);
		deg[x]++; deg[y]++;
	}
	repp(i,n){
		for(auto e : ed[i]) if(e > i) ba[i].push_back(e);
	}
	ll ans = 0;
	repp(i,n) ans += (ll)(deg[i]-(int)ba[i].size())*(int)ba[i].size();
	printf("%lld\n",ans);
	int q; scanf("%d",&q);
	while(q--){
		int x; scanf("%d",&x);
		ans -= (ll)(deg[x]-(int)ba[x].size())*(int)ba[x].size();
		for(auto e : ba[x]){
			ans += (ll)(deg[e]-(int)ba[e].size()-(int)ba[e].size()-1);
			ba[e].push_back(x);
		}
		ba[x].clear();
		printf("%lld\n",ans);
	}


	return 0;
}