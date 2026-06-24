#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define INIT(a, v) __typeof(v) a = (v)
#define FOREACH(a, v) for (INIT(a, (v).begin()); a!=(v).end(); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}
 
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;

#define INF 1000000000
#define PB push_back
#define MP make_pair
 
//////////////////////////////////////////

double ttt1 = 0, ttt2 = INF;

void dodaj(int pocz, int kon, int st, int v) {
    if (v==0) {
        if (st>pocz && st<kon) return;
        printf("-1\n");
        exit(0);
    }
    if (v<0) { pocz = -pocz; kon = -kon; swap(pocz, kon); st = -st; v = -v; }
    if (st>=kon) {
        printf("-1\n");
        exit(0);
    }
    double czp = max(0., (pocz-st)*1./v);
    ttt1 = max(czp, ttt1);
    double czk = (kon-st)*1./v;
    ttt2 = min(ttt2, czk);
}

int N;

int main() {
    scanf("%d", &N);
    int xl, yl, xp, yp;
    scanf("%d%d%d%d", &xl, &yl, &xp, &yp);
    REP(a, N) {
        int sx, sy, vx, vy;
        scanf("%d%d%d%d", &sx, &sy, &vx, &vy);
        dodaj(xl, xp, sx, vx);
        dodaj(yl, yp, sy, vy);
    }
    if (ttt1+0.00000000001<ttt2)
        printf("%.15f\n", ttt1);
    else
        printf("-1\n");
}