#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef gp_hash_table<int,int> umap;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937_64 eng(seed);
 
ll random2(){
    return eng() >> 1;
}
 
ll n,m,k,q,T;
 
const ll nils = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1000001;

vector<vi> grid;
vector<vi> hej;
vector<vl> pref;

int DX[4] = {0,0,1,-1};
int DY[4] = {-1,1,0,0};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

vi W;

int mi_x, ma_x, mi_y, ma_y;

void mark(int i, int j, int x){
    if(grid[i][j] == 0)return;
    if(hej[i][j] != -1)return;
    hej[i][j] = x;
    mi_x = min(mi_x, i);
    ma_x = max(ma_x, i);
    mi_y = min(mi_y, j);
    ma_y = max(ma_y, j);
    W[x]++;
    rep(c1,0,4){
        int i2 = i + DX[c1];
        int j2 = j + DY[c1];
        if(inbounds(i2, j2))mark(i2,j2,x);
    }
}

void inc(ll x1, ll x2, ll y1, ll y2, ll w){
    pref[x1][y1] += w;
    pref[x2+1][y1] -= w;
    pref[x1][y2+1] -= w;
    pref[x2+1][y2+1] += w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll a,b,c,d;
    
    cin >> T;
 
    rep(c4,0,T){
        cin >> n >> m;
        grid.clear();
        hej.clear();
        W.clear();
        pref.clear();
        rep(c1,0,n){
            vi row;
            vi zero;
            vl p;
            string s;
            cin >> s;
            rep(c2,0,m){
                row.push_back((s[c2] == '#'));
                zero.push_back(-1);
                p.push_back(0);
            }
            p.push_back(0);
            pref.push_back(p);
            grid.push_back(row);
            hej.push_back(zero);
        }

        vl p2;
        rep(c1,0,m+1){
            p2.push_back(0);
        }
        pref.push_back(p2);

        rep(c1,0,n){
            rep(c2,0,m){
                if(grid[c1][c2] == 1 && hej[c1][c2] == -1){
                    W.push_back(0);
                    mi_x = nils;
                    mi_y = nils;
                    ma_x = -nils;
                    ma_y = -nils;
                    mark(c1,c2,sz(W)-1);
                    mi_x--;
                    ma_x++;
                    mi_y--;
                    ma_y++;
                    mi_x = max(0,mi_x);
                    ma_x = min((int)n-1, ma_x);
                    mi_y = max(0,mi_y);
                    ma_y = min((int)m-1, ma_y);
                    inc(0, n-1, mi_y, ma_y, W.back());
                    inc(mi_x, ma_x, 0, m-1, W.back());
                    inc(mi_x, ma_x, mi_y, ma_y, -W.back());
                }
                if(grid[c1][c2] == 0){
                    inc(0,n-1,c2,c2,1);
                    inc(c1,c1,0,m-1,1);
                    inc(c1,c1,c2,c2,-1);
                }
            }
        }

        ll ans = -nils;
        rep(c1,0,n+1){
            rep(c2,0,m+1){
                if(inbounds(c1-1,c2))pref[c1][c2] += pref[c1-1][c2];
                if(inbounds(c1,c2-1))pref[c1][c2] += pref[c1][c2-1];
                if(inbounds(c1-1,c2-1))pref[c1][c2] -= pref[c1-1][c2-1];
                
            }
        }
        rep(c1,0,n){
            rep(c2,0,m){
                ans = max(ans, pref[c1][c2]);
                //cerr << pref[c1][c2] << " ";
            }//cerr << "  gg\n";
        }

        

        cout << ans << "\n";

    }
 
    return 0;
}