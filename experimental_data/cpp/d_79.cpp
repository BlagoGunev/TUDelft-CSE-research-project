#include <algorithm>

#include <iostream>

#include <cstring>

#include <vector>

#include <cstdio>

#include <string>

#include <cmath>

#include <queue>

#include <set>

#include <map>

using namespace std;

typedef long long ll;

typedef double db;

typedef pair<int,int> pii;

typedef vector<int> vi;

#define de(x) cout << #x << "=" << x << endl

#define rep(i,a,b) for(int i=a;i<b;++i)

#define all(x) (x).begin(),(x).end()

#define sz(x) (int)(x).size()

#define mp make_pair

#define pb push_back

#define fi first

#define se second

#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)

const int N = 10101 , MAXK = 20 , MAXL = 101 , inf = 1<<29;

int a[N] , b[N] , n , K , L , len[MAXL];

vi ele;int id[N] , dis[N] , cost[MAXK][MAXK];

void bfs(int c,int u){

    fill(dis , dis + n + 2 , inf);

    fill(cost[u] , cost[u] + sz(ele) , inf);

    dis[c] = 0;

    vi v;v.pb(c);

    rep(i,0,sz(v)){

        c = v[i];

        if(b[c] == 1) cost[u][id[c]] = dis[c];

        rep(j,0,L){

            if(c - len[j] > 0 && dis[c - len[j]] == inf) dis[c - len[j]] = dis[c] + 1 , v.pb(c - len[j]);

            if(c + len[j] <= n+1 && dis[c + len[j]] == inf) dis[c + len[j]] = dis[c] + 1 , v.pb(c + len[j]);

        }

    }

}

int f[1<<MAXK] , who[1<<MAXK];

void Dp(){

    f[0] = 0;

    rep(i,1,(1<<sz(ele))){

        f[i] = inf;

        int j = i&(-i);

        for(int k=i^j;k;k-=k&(-k)) f[i] = min(f[i] , f[i^j^(k&(-k))] + cost[who[j]][who[(k&(-k))]]);

    }

    int ans = f[(1<<sz(ele))-1];

    if(ans == inf) ans = -1;

    printf("%d\n",ans);

}





int main(){

    rep(i,0,MAXK) who[1<<i] = i;

    cin >> n >> K >> L;

    rep(i,0,K){

        int x;cin >> x;

        a[x] = 1;

    }

    rep(i,0,L) cin >> len[i];

    rep(i,1,n+2) b[i] = a[i-1] ^ a[i];

    rep(i,1,n+2) if(b[i] == 1) id[i] = sz(ele) , ele.pb(i);

    rep(i,0,sz(ele)) bfs(ele[i] , i);

    //rep(i,0,sz(ele)) rep(j,0,sz(ele)) printf("%d%c",cost[i][j] , " \n"[j + 1 == sz(ele)]);

    Dp();

    return 0;

}