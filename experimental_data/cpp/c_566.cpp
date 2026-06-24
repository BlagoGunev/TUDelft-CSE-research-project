#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



#define forn(i, n)  for(ll i = 0;i < n;i ++)

#define for1(i, n)  for(ll i = 1;i <= n;i ++)

#define FOR(i, a, b)  for(ll i = a;i <= b;i ++)

#define fore(i, v)  for(__typeof ((v).begin()) i = (v).begin(); i != (v).end(); i ++)

const ll N = 2e5 + 10;

const ll INF = 1e18;

#define pb         push_back

#define mp         make_pair

#define all(v)     v.begin(), v.end()





typedef vector<ll> vi;

typedef double ld;

///style for graph with weighted edges

typedef pair<ll,ll> node;

#define v       first

#define w       second

vector<node> g[N];///all the graph here

ll n;

ll human[N];     ///thanh phan tai moi dinh

void loadWGraph()

{

    scanf("%lld", &n);

    for1(i, n) scanf("%lld", &human[i]);

    //cout<< human[1];

    for1(i, n - 1){

       ll u,v,w;scanf("%lld %lld %lld",&u,&v,&w);

       g[u].pb(mp(v, w));g[v].pb(mp(u,w));

    }

}

///3 here is the part to calculate sovle



ld fun(ll val)

{

    ld m = ld(sqrt(val + 0.00)) *(val + 0.00);

 //   cout<<fixed << m <<endl;

    return m;

}



ld der[N], fu[N], dist[N];



ld dfsDp(ll u,ll p,ll edup)

{

    dist[u] = dist[p] + (ld)edup;            ///top down



    fu[u] = (ld)human[u] *    fun(dist[u]); ///bottom up

    der[u]  = (ld)human[u] * (ld)sqrt(dist[u] + 0.00);///bot up



    fore(it, g[u]){

       node v = *it;

       if(v.v!= p){

          dfsDp(v.v, u, v.w);

          der[u] += der[v.v];

          fu[u]  += fu[v.v];

       }

    }

    //cout<< "s " << u << "   " << fu[u] << endl;

    return fu[u];

}

ld solve(ll root){

    dist[root] = fu[root] = der[root] = 0;

    ld ans = 0.00;

    fore(it, g[root]){

        node v = *it;

        ans += dfsDp(v.v, root, v.w);

    }

    return ans;

}



///2, here is the part to find centroid of the tree root u

bool visited[N]; ll totals;

ll subsize[N];

void dfsSize(ll u,ll p){

    subsize[u] = 1;

    fore(t, g[u]){

        ll v = (*t).v;

        if(v==p||visited[v]) continue;

        dfsSize(v, u);

        subsize[u] += subsize[v];

    }

    if(u == p) totals = subsize[u];

}

ll dfsFind(ll u, ll p){

    fore(it, g[u]){

        ll v = (*it).v;

        if(v==p||visited[v]) continue;



        if(subsize[v] > totals/2) return dfsFind(v, u);

    }

    return u;

}

ll centroid(ll u,ll p){

   dfsSize(u, u);

   return dfsFind(u, -1);

   //cout<<"a"<<endl;

}

///find cent ends-----------------------------------------

ll compsolve(ll u){

    ll cent = centroid(u, -1);

    ld now = solve(cent);

    ld Der = 0;

    fore(v, g[cent]) Der += der[(*v).v];

    fore(v, g[cent]) {

        ld cal = Der -2 *  der[(*v).v];

        if(cal<0)

        {

            if(solve((*v).v) < now) {

                visited[cent] = true;

                return compsolve((*v).v);

            }

        }

    }

    return cent;

}



int main()

{

  //  freopen("test.inp.c","r",stdin);

    loadWGraph();

    ll dinh = compsolve(1);

    cout<< dinh << " ";

    //for1(i, n) cout<< fixed << fu[i] << endl;

    cout<<fixed << setprecision(20) << solve(dinh) << endl;

}