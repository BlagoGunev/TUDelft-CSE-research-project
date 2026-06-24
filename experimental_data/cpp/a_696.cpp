#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"
#include "numeric"
#include "iomanip"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

ll lca(ll x, ll y) {
    while(x != y) {
        if(x > y)
            x >>= 1;
        else
            y >>= 1;
    }
    return x;
}

int main () {
    
    int q;
    
    scanf("%d", &q);
    
    map < ll, ll > M;
    
    while(q--) {
        int c;
        scanf("%d", &c);
        if(c == 1) {
            ll x, y, v;
            scanf("%lld %lld %lld", &x, &y, &v);
            ll z = lca(x, y);
            while(x > z) {
                M[x] += v;
                x >>= 1;
            }
            while(y > z) {
                M[y] += v;
                y >>= 1;
            }
        }
        else {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            ll z = lca(x, y);
            ll res = 0;
            while(x > z) {
                res += M[x];
                x >>= 1;
            }
            while(y > z) {
                res += M[y];
                y >>= 1;
            }
            printf("%lld\n", res);
        }
    }
    
    return 0;
    
}