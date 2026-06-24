#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <fstream>
#include <limits.h>
#define REP(start, end) for (size_t i = (start); i < (end); i++)
#define REP2(start, end) for (size_t j = (start); j < (end); j++)
#define INF   2000000000
#define LLINF 9000000000000000000LL
#define mp(a,b) std::make_pair ((a),(b))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
inline int read() {
    int n = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return n * f;
}
vii V,P;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N = read(), f = read(), k, l;
    REP(0,N){
        k = read(), l = read();
        P.pb(mp(k,l));
        V.pb(mp(min(k*2,l)-min(k,l),i));
    }
    sort(all(V),std::greater<ii>());
    LL sum = 0;
    REP(0,f){
        int ind = V[i].se;
        sum+=min(P[ind].fi*2,P[ind].se);
        P[ind].fi = 0;
    }
    REP(0,N){
        sum+=min(P[i].fi,P[i].se);
    }
    cout << sum << endl;
}