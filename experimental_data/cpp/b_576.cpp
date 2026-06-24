//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <bitset>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define reveach(i, v) for (__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++ i)
#define REP(i,n) for ( int i=1; i<=int(n); i++ )
#define rep(i,n) for ( int i=0; i< int(n); i++ )
using namespace std;
typedef long long ll;
#define X first
#define Y second
#define PB push_back
#define MP make_pair
typedef pair<int,int> pii;

template <class T>
inline bool RD(T &ret) {
        char c; int sgn;
        if (c = getchar(), c == EOF) return 0;
        while (c != '-' && (c<'0' || c>'9')) c = getchar();
        sgn = (c == '-') ? -1 : 1 , ret = (c == '-') ? 0 : (c - '0');
        while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
        ret *= sgn;
        return 1;
}
template <class T>
inline void PT(T x) {
        if (x < 0) putchar('-') ,x = -x;
        if (x > 9) PT(x / 10);
        putchar(x % 10 + '0');
}

int gcd(int a,int b){
        return b == 0 ? a : gcd( b, a % b);
}

const int N = 1e5+100;
int p[N];
vector<pii> all;
bool vis[N];
int main(){
        int n;
        RD(n);
        REP(i,n) RD(p[i]);
        bool ok = 0;
        REP(i,n){
                if( vis[i] == 0 ){
                        int cnt = 0;
                        for(int pos = i; vis[pos] == 0 ; pos = p[pos] ) {
                                vis[ pos ] = 1;
                                cnt ++;
                        }
                        if( cnt == 1 ) ok = 1;
                        all.push_back( pii( cnt, i ) );
                }
        }

        int d = 0;
        sort( ALL( all ) );
        foreach( it , all ){
                d = gcd( d, (*it).X );
        }

        if( ok == 1 || ( d == 2 && all[0].X == 2 )  ) {

                puts("YES");

     //   if( n == 70082 )printf(" gcd = %d, (%d %d)\n", d , all[0].X, all[0].Y );
                int poi = all[0].Y;
                memset( vis, 0 , sizeof(vis) );

                foreach(it, all){
                        if( it == all.begin() ) continue;
                        pii cur = *it;
                        for(int u = poi, v = cur.Y; vis[v] == 0 ; v = p[v], u = p[u] ){
                                vis[v] = 1;
                                printf("%d %d\n", u, v);
                        }
                }

                if( all[0].X == 2 ) printf("%d %d\n", poi, p[poi]);
        } else puts("NO");
}