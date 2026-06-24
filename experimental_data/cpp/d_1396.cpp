#include <bits/stdc++.h>

using namespace std;

#define mp(u,v) make_pair(u,v)

#define pb push_back

const int N=2005,mod=1e9+7;

void Add_mod(int &x,int val) { x+=val; if (x>=mod) x-=mod; }



int n,k,L,x[N],y[N],c[N],ans,cur;

pair<pair<int,int>,int> p[N];

set<pair<int,int> > Set;

multiset<int> pos[N];

void work(int x,int y) {

	auto it=prev(Set.lower_bound(mp(x,L+1)));

	int val=(*it).second; if (val<=y) return;

	int nx=(*next(it)).first,las=x+1;

	vector<pair<int,int> > vec; vec.clear();

	while ((*it).second>=y) {

		cur=(cur+mod-1ll*((*it).second-y)*(las-(*it).first)%mod)%mod;

		las=(*it).first;

		vec.pb(*it); it--;

	}

	for (auto x : vec) Set.erase(x);

	Set.insert(mp(las,y));

	if (x+1<nx) Set.insert(mp(x+1,val));

}

int main() {

	scanf("%d%d%d",&n,&k,&L);

	for (int i=1; i<=n; i++) scanf("%d%d%d",&p[i].first.first,&p[i].first.second,&p[i].second);

	sort(p+1,p+n+1);

	for (int i=1; i<=n; i++) {

		x[i]=p[i].first.first+1;

		y[i]=p[i].first.second+1;

		c[i]=p[i].second;

	}

	int r=0,las=0;

	for (int i=1; i<=n; i=r+1) {

		r=i; while (r<n && x[r+1]==x[i]) r++;

		for(int i=1; i<=k; i++) pos[i].clear();

		int len=x[i]-las; cur=1ll*L*L%mod;

		

		Set.clear();

		Set.insert(mp(0,-1)),Set.insert(mp(1,L)),Set.insert(mp(L+1,L+1));

		for (int j=i; j<=n; j++) pos[c[j]].insert(y[j]);

		

		int flag=0;

		for (int i=1; i<=k; i++) {

			if (pos[i].empty()) { flag=1; break; }

			int las=0;

			for (int x : pos[i]) work(x-1,las),las=x;

			work(L,las);

		}

		if (flag) { las=x[i]; continue; }

		

		int l=0,gg=L+1;

		for (int j=n; j>=i; j=l-1) {

			l=j; while (l>1 && x[l-1]==x[j]) l--;

			Add_mod(ans,1ll*len*(gg-x[l])%mod*cur%mod);

			gg=x[l];

			int flag=0;

			for (int k=l; k<=j; k++) {

				pos[c[k]].erase(pos[c[k]].find(y[k]));

				if (pos[c[k]].empty()) { flag=1; break; }

				auto it=pos[c[k]].lower_bound(y[k]);

				work((it==pos[c[k]].end()?L:(*it)-1),(it==pos[c[k]].begin()?0:(*prev(it))));

			}

			if (flag) break;

		}

		las=x[i];

	}

	printf("%d\n",ans);

	return 0;

}