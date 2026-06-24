#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

#define N 400
int a[N][N];

int main() {
    int n;
    cin >> n;
    VI t(n);
    REP(i,n) cin >> t[i];
    int si = 200, sj = 200;
    VI x, y;
    x.push_back(si);
    y.push_back(sj);
    int dx[] = {0,-1,-1,-1,0,1,1,1};
    int dy[] = {1,1,0,-1,-1,-1,0,1};
    REP(i,n){
        x.push_back(x[i]+t[i]*dx[i%8]);
        y.push_back(y[i]+t[i]*dy[i%8]);
    }

    FORR(p,n-1,0){
        int xx = x[p+1], yy = y[p+1];
        int dxx = dx[p%8], dyy = dy[p%8];
        REP(k,t[p]){
            a[xx-k*dxx][yy-k*dyy] = 1;
        }
        REP(i,N) REP(j,N){
            if (!a[i][j]) continue;
            int xd = i - xx, yd = j - yy;
            if (dxx == 0){
                xd *= -1;
            }else if (dyy == 0){
                yd *= -1;
            }else if (dxx * dyy == 1){
                swap(xd,yd);
            }else{
                swap(xd,yd);
                xd *= -1;
                yd *= -1;
            }
            xd += xx;
            yd += yy;
            a[xd][yd] = 1;
        }
    }

    int ans = 0;
    REP(i,N) REP(j,N) ans += a[i][j];
    cout << ans << endl;

    return 0;
}