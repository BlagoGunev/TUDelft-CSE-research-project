#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef unsigned long long ull;
const int inf_int=1e8;
const ll inf_ll=1e16;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double dbl;
#define pb push_back
const double pi=3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
#define div nasyi

const int MAXN = 2e5+100;

ll ans[MAXN];
int cnt[MAXN];
int a[MAXN];
bool lvl[MAXN];
vector<int> g[MAXN];
inline int my_gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}


int cur[MAXN];
int all[MAXN];


void dfs(int v,int p,int val){
    val = my_gcd(val,a[v]);
    ans[val]++;
    cur[val]++;
   // cout << v <<" "<< p<<" "<<val<<endl;
    for(int to:g[v]){
        if(!lvl[to] && to!=p)
            dfs(to,v,val);
    }
}
vector<int> div[MAXN];
void sieve(){
    for(int i=1;i<MAXN;++i){
        for(int e=i;e<MAXN;e=e+i){
            div[e].pb(i);
        }
    }
}


void process(int v){
   // cout <<"proces "<<v<<endl;
    int val = a[v];
    int m = sz(div[val]);
    for(int to:g[v]){
        if(!lvl[to]){
            dfs(to,v,val);
            for(int i=0;i<m;++i){
                if(cur[div[val][i]])
                for(int e=0;e<m;++e){
                    if(all[div[val][e]]){
                        ans[my_gcd(div[val][i],div[val][e])]+=1ll * cur[div[val][i]] * all[div[val][e]];
                    }
                }
            }
            for(int i=0;i<m;++i){
                all[div[val][i]]+=cur[div[val][i]];
                cur[div[val][i]] = 0;
            }

        }

    }
    for(int i=0;i<m;++i){
        all[div[val][i]] = 0;
    }
}

int dfs(int v,int p,int &center,int size){
    int sum = 1;
    for(int to:g[v]){
        if(to==p || lvl[to])
            continue;
        sum+=dfs(to,v,center,size);
    }
    if(center==-1 && (2*sum >= size || p==-1))
        center = v;
    return sum;
}
void build(int v,int size){
    int center = -1;
    dfs(v,-1,center,size);
    process(center);
    lvl[center] = 1;

    for(int to:g[center]){
        if(!lvl[to])
            build(to,size/2);
    }
}
void solve(){
    sieve();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ans[a[i]]++;
    }
    for(int i=1;i<=n-1;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].pb(b);
        g[b].pb(a);
    }
    build(1,n);

    for(int i=1;i<MAXN;++i){
        if(ans[i]){
            printf("%d %I64d\n",i,ans[i]);
        }
    }

}

signed main()
{
        #ifdef taow
            debug = 1;
           freopen("input.txt","r",stdin);
          //  freopen("output.txt","w",stdout);
        #else
        #endif // taow


        int t = 1;
        while(t--)
            solve();
}