#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(i,a,b) for(int i=a; i>=b; i--)
#define FORAD(i,u) for(int i=0; i < (int)u.size(),i++)
#define BUG(x) cout << x << endl
#define ll long long
#define fi first
#define sd second
#define pb push_back
#define two(i) 1 << i
#define sz(x) (int)x.size()
#define e 1e-12
#define bit(s,i) ((s >> (i-1)) & 1)
#define Nmax 100100
const double pi = acos(-1);
const int Xmax = 1100;
typedef vector<int> vi ;
typedef pair<int,int> pii ;

vector<int> ad[100], xx[Xmax], xx2[Xmax];
pii a[111];
int n, f[111][Xmax][11], t_res[111][Xmax][11], t_[111][Xmax][11], t2_[111][Xmax][11], p[66], dem, nt[66], dem2, nt2[66], kq[111];



void init(){
    int x = 60;
    FOR(i, 2, trunc(sqrt(x))) if (p[i] == 0) {
        int j = i*i;
        while (j <= x) {
            p[j] = i;
            j += i;
        }
    }
    FOR(i, 2, 60) {
        x = i;
        while (x > 1) {
            int y; if (p[x]) y = p[x]; else y = x;
            ad[i].pb(y);
            while (x % y == 0) x/= y;
        }
    }
    FOR(i, 2, 30) if (p[i] == 0) nt[++dem] = i;
    FOR(i, 31, 60) if (p[i] == 0) nt2[++dem2] = i;
    FOR(i, 0, n) FOR(j, 0, (1 << dem) - 1) FOR(k, 0, dem2) f[i][j][k]= 1000000000;
    f[0][0][0] = 0;
    FOR(i, 1, 60) if (i <= 30 || p[i]) {
        int x = 0;
        FOR(j, 1, dem) if (i % nt[j] == 0) x += 1 << (j - 1);
        FOR(j, 0, (1 << dem) - 1) if ((x & j) == 0) {xx[j].pb(i); xx2[j].pb(x + j);}
    }

}

void update(int i, int j, int k, int u, int v, int t, int x, int No) {

    if (f[i][j][k] > f[u][v][t] + x){
        f[i][j][k] = f[u][v][t] + x;
        t_res[i][j][k] = No;
        t_[i][j][k] = v;
        t2_[i][j][k] = t;
    }
}

int main() {
    // freopen("in.inp","r",stdin);
    // freopen("","w",stdout);
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    init();
    FOR(i, 0, n - 1) FOR(j, 0, (1 << dem) - 1) FOR(u, 0, dem2) if (f[i][j][u] < 1000000000)
    {   FOR(t, 0, sz(xx[j]) - 1){
        int x = xx2[j][t], k =  xx[j][t];
       /* if (f[i + 1][x][u] > f[i][j][u] + abs(a[i + 1].first - k)) {
            f[i + 1][x][u] = f[i][j][u] + abs(a[i + 1].first - k);
            t_res[i + 1][x][u] = k;
            t_[i + 1][x][u] = j;
            t2_[i + 1][x][u] = u;
        }*/
        update(i + 1, x, u, i, j, u, abs(a[i + 1].first - k), k);
        }
       FOR(u2, u + 1, dem2) update(i + 1, j, u2, i, j, u, abs(a[i + 1].first - nt2[u2]), nt2[u2]);
    }
    int res = 1000000000, x = 1, y = 1;
   // cout << f[1][0][0] << endl;
    FOR(i, 0, (1 << dem) - 1) FOR(j, 0, dem2) if (res > f[n][i][j]) {
        res = f[n][i][j];
        x = i;
        y = j;
    }
   // cout << x << ' ' << y << endl;
    REP(i, n, 1) {
        kq[a[i].second] =  t_res[i][x][y];
        int x2 = t_[i][x][y];
        y = t2_[i][x][y];
        x = x2;
    }
    FOR(i, 1, n) cout << kq[i] << ' ';
     return 0;
}