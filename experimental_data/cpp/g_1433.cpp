#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define testCases() int t; cin >> t; while(t--)

#define rep(x,n,i)   for(int i = x; i < n; i++)

#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define f first

#define s second

#define all(v) v.begin(),v.end()

#define e endl

#define ln "\n"

#define yes cout<<"YES"<<ln

#define no  cout<<"NO"<<ln

#define invalid cout<<-1<<ln

#define pb push_back

#define pf push_front

#define mp map<ll,ll> 

#define debug(a) cout << #a << " : " << a << ln

#define debugLine() cout << "==============" << ln

#define left p<<1 , l , (l+r)>>1

#define right p<<1|1 , ((l+r)>>1)+1 , r

#define log(x) (31^__builtin_clz(x)) // Easily calculate log2 on GNU G++ compilers

const ll mxn=1e5+3;

ll x;

int d[1001][1001],n;vector<pair<int,int> > adj[1001];

inline void Dijkstra(int node)

{for(int i=0;i<=n;i++)d[node][i]=2e9;

d[node][node]=0;priority_queue<pair<int,int> > pq;

pq.push(make_pair(-0,node));

while(!pq.empty())

 {int dis=-pq.top().first;

 int u=pq.top().second;

 pq.pop();

 if(dis>d[node][u])continue;

 for(int i=0;i<adj[u].size();i++)

  {int v=adj[u][i].first;int w=adj[u][i].second;

   if(d[node][v]>d[node][u]+w)

   {d[node][v]=d[node][u]+w;

    pq.push(make_pair(-d[node][v],v));}

  }

 }

}

int main(){

	fast;

	ll m,k,ans= 1e18;

	cin>>n>>m>>k;

	pair<ll,ll> edge[m+2];

	pair<ll,ll> rout[k+2];

	ll x,y,w;

	for(int i = 0;i < m;i++){

		cin>>x>>y>>w;

		edge[i] = make_pair(x,y);

		adj[x].pb({y,w});

		adj[y].pb({x,w});

	}

	ll a,b;

	for(int i = 0;i < k;i++){

		cin>>a>>b;

		rout[i] =make_pair(a,b); 

	}

	for(int i = 1;i <= n;i++){

		Dijkstra(i);

	}

	

	for(int i = 0;i < m;i++){

	ll cost = 0;

	for(int j = 0;j < k;j++){

		cost+=min(d[rout[j].f][rout[j].s],min(d[rout[j].f][edge[i].f]+d[edge[i].s][rout[j].s],d[rout[j].f][edge[i].s]+d[edge[i].f][rout[j].s]));

	}	

	ans = min(ans,cost);

	}

	cout<<ans<<ln;

	return 0;

}