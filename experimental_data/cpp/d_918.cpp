#include <bits/stdc++.h>
using namespace std;
#define sqr(x) ((x)*(x))
#define par make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
template<class X, class Y> void amax(X& x, const Y& y){if(x < y) x = y;}
template<class X, class Y> void amin(X& x, const Y& y){if(x > y) x = y;}
typedef vector<int> vi; typedef pair<int, int> ii; typedef long long ll; typedef long double ld;
const int INF = 1e9 + 10; const ll INFL = 1e18 + 10;
const int MAX = 110;

int n, m;
vector<pair<int, char>> es[MAX];
int f[MAX][MAX];

int calc(int x, int y){
    if(f[x][y] != -2) return f[x][y];
    f[x][y] = -1;
    for(auto e : es[x]){
        int v = e.fi, c = e.se - 'a';
        int nx = calc(y, v);
        if(c > nx) amax(f[x][y], c);
    }
    return f[x][y];
}

void process(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        es[u].pb(par(v, c));
    }
    fill(&f[0][0], &f[0][0] + sizeof(f)/sizeof(f[0][0]), -2);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x = calc(i, j);
            if(x >= 0) cout << 'A';
            else cout << 'B';
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("d.in", "r", stdin);
    process();
}