#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ldb;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ldb,ldb> pdd;

#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,b,a) for(int i = b; i >= a; i--)
#define trav(a,x) for(auto& a : x)
 
#define sz(a) (int)(a).size()
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

const int mod = 1000000007;
const int inf = 1e9 + 5;
const int mxN = 300005; 

int n, m;

vector<int> g[mxN];

int timer = 0;
int d[mxN];
int in[mxN];
int out[mxN];
int deda[mxN][20];
void dfs1(int v, int p){
    deda[v][0] = p; in[v] = ++timer; 
    ff(i,1,19)deda[v][i] = deda[deda[v][i - 1]][i - 1];
    for(auto u : g[v]){
        if(u != p){
            d[u] = d[v] + 1;
            dfs1(u, v);
        }
    }
    out[v] = timer;
}

int LCA(int x, int y){
    if(d[x] < d[y])swap(x, y);
    fb(i,19,0)if((d[x] - d[y]) & (1 << i))x = deda[x][i];
    fb(i,19,0)if(deda[x][i] != deda[y][i])x = deda[x][i], y = deda[y][i];
    return (x == y ? x : deda[x][0]);
}

int calc(int x, int y){
    fb(i,19,0)if(y & (1 << i))x = deda[x][i];
    return x;
}

int dud[mxN];
void upd(int x, int val){
    while(x <= mxN){
        dud[x] += val;
        x += x&(-x);
    }
}
int query(int x){
    int sum = 0;
    while(x > 0){
        sum += dud[x];
        x -= x&(-x);
    }
    return sum;
}

ll rez = 0;

int cnt[mxN];
vector<pii> vec[mxN];

void dfs2(int v, int p){

    // prvo da resim za sve sa istim lca-om

    ll kol = 0; map<pii,int> zaj;

    int uk = sz(vec[v]); vector<pii> pom;
    for(auto [a, b] : vec[v]){

        if(a == b){
            rez += query(out[v]) - query(in[v] - 1);

            kol += uk - 1;

            continue;
        }

        if(a == v){
            rez += query(out[v]) - query(in[v] - 1);

            int X = calc(b, d[b] - d[v] - 1);
            rez -= query(out[X]) - query(in[X] - 1);

            pom.pb({X, 0}); cnt[X] += 1;

            continue;
        }

        if(b == v){
            rez += query(out[v]) - query(in[v] - 1);

            int X = calc(a, d[a] - d[v] - 1);
            rez -= query(out[X]) - query(in[X] - 1);

            pom.pb({X, 0}); cnt[X] += 1;

            continue;
        }

        rez += query(out[v]) - query(in[v] - 1);

        int X = calc(a, d[a] - d[v] - 1);
        int Y = calc(b, d[b] - d[v] - 1);
        
        rez -= query(out[X]) - query(in[X] - 1);
        rez -= query(out[Y]) - query(in[Y] - 1);

        if(X > Y)swap(X, Y);

        pom.pb({X, Y}); cnt[X] += 1; cnt[Y] += 1;
        zaj[{X, Y}] += 1; 

    }

    // sa istim lca-om 


    for(auto [a, b] : pom){
        if(b == 0){
            kol += uk - cnt[a];
        }
        else{
            kol += uk - cnt[a] - cnt[b] + zaj[{a, b}];
        }

    }


    kol /= 2; rez += kol;

    for(auto [a, b] : pom){
        if(b == 0)cnt[a] -= 1;
        else cnt[a] -= 1, cnt[b] -= 1;
    }


    // i da updejtujem
    for(auto [a, b] : vec[v]){
        upd(in[a],1);
        upd(in[b],1);
    }

    for(auto u : g[v]){
        if(u != p){
            dfs2(u, v);
        }
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    ff(i,1,n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u); 
    }

    dfs1(1, 0);

    cin >> m;
    ff(i,1,m){
        int u, v;
        cin >> u >> v;

        int lca = LCA(u, v);
        vec[lca].pb({u, v});

    }

    dfs2(1, 0);

    cout << rez << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/