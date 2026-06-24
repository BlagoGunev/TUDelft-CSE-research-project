#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int n,k,m,q;
vector < pair < int , int > > E[100005];
LL dist[100005];
int U[300005], V[300005];
vector < int > Sfrom[100005], Sto[100005];
int P[100005];
LL Answer[300005];
LL Sum[100005];
vector < pair < pair < int , int > , LL > > pr;

int f( int x ){
	if ( P[x] != x ) return P[x] = f(P[x]);
	return x;
}

bool cmp( pair < pair < int , int > , LL > a, pair < pair < int , int > , LL > b ){
	return a.se < b.se;
}

int main(){

	memset(Answer,-1,sizeof(Answer));
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for ( int i = 1; i <= n; i++ ){
		P[i] = i;
		dist[i] = 1e18;
	}
	for ( int i = 0; i < m; i++ ){
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w);
		E[u].pb(mp(v,w));
		E[v].pb(mp(u,w));
	}
	for ( int i = 0; i < q; i++ ){
		int u,v;
		scanf("%d%d",&u,&v);
		U[i] = u;
		V[i] = v;
		Sfrom[u].pb(i);
		Sto[v].pb(i);
		Sfrom[v].pb(i);
		Sto[u].pb(i);
	}
	priority_queue < pair < LL , int > > pq;
	for ( int i = 1; i <= k; i++ ){
		pq.push(mp(0,i));
		dist[i] = 0;
	}

	while ( !pq.empty() ){
		LL z = -pq.top().fi;
		int u = pq.top().se;
		pq.pop();
		if ( dist[u] != z ) continue;
		for ( auto it : E[u] ){
			int v = it.fi;
			LL w = it.se;
			if ( dist[v] > z + w ){
				dist[v] = z + w;
				pq.push(mp(-dist[v],v));
			} else {
				pr.push_back(mp(mp(u,v),w + dist[v] + dist[u]));
			}
		}
	}
	sort(pr.begin(),pr.end(),cmp);

	for ( int id = 0; id < pr.size(); id++ ){
		int u = pr[id].fi.fi, v = pr[id].fi.se;
		LL w = pr[id].se;
		if ( f(u) != f(v) ){
			int pu = f(u), pv = f(v);
			if ( pu > pv ) swap(pu,pv);
			if ( Sfrom[pu].size() + Sto[pu].size() < Sfrom[pv].size() + Sto[pv].size() ){
				for ( auto it : Sfrom[pu] ){
					int itv = V[it];
					if ( Answer[it] != -1 ) continue;
					if ( f(itv) == f(pv) ){
						Answer[it] = w;
					} else {
						Sfrom[pv].push_back(it);
					}
				}
				for ( auto it : Sto[pu] ){
					int itu = U[it];
					if ( Answer[it] != -1 ) continue;
					if ( f(itu) == f(pv) ){
						Answer[it] = w;
					} else {
						Sto[pv].push_back(it);
					}
				}
				P[pu] = pv;
			} else {
				for ( auto it : Sfrom[pv] ){
					int itv = V[it];
					if ( Answer[it] != -1 ) continue;
					if ( f(itv) == f(pu) ){
						Answer[it] = w;
					} else {
						Sfrom[pu].push_back(it);
					}
				}
				for ( auto it : Sto[pv] ){
					int itu = U[it];
					if ( Answer[it] != -1 ) continue;
					if ( f(itu) == f(pu) ){
						Answer[it] = w;
					} else {
						Sto[pu].push_back(it);
					}
				}
				P[pv] = pu;
			}
		}
	}

	for ( int i = 0; i < q; i++ ){
		printf("%lld\n",Answer[i]);
	}
	return 0;
}