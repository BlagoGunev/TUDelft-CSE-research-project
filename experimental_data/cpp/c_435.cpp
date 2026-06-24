#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
  
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 8191
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair
  
struct tri{
    int dir, esq, mid;
    string id;
    tri ( int dir = -1, int esq = 0, int mid = -1, string id = "" ) : dir(dir), esq(esq), mid(mid), id(id) { }
};
  
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
const  double pi = acos(-1.0);
const  double EPS = 1e-15;
const  double INF = 1e50;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
  
int cmp(double a, double b = 0.0){ if(fabs(a-b) < EPS) return 0; return a > b ? 1 : -1; }
  
  
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
   
bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}

int vet[100000];
vector < pair < int, pair < int, int > > > mapa;
char espaco[100000];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for( int i = 0; i < 10001; i++ ) espaco[i] = ' ';
    int x = 1, y = 1, sinal = 0;;
    int lo = 1e9, hi = -1e9;
    REP(i,n){
        cin >> vet[i];
        sinal = !sinal;
        FOR(j,1,vet[i]){
            if( sinal ) y++;
            else y--;
            lo = min(lo,y);
            hi = max(hi,y);
            mapa.pb(make_pair(-(y),make_pair(x++,!sinal)));
        }
        if( sinal ) y++;
        else y--;
    }
    sort(ALL(mapa));
    int tam = mapa.size(), ant = 0;
    char ans[] = {'/','\\'};
    REP(i,mapa.size()){
        int w = i;
        ant = 0;
        int ok  = 1;
        while(w < tam && mapa[i].first == mapa[w].first){
            printf("%.*s", (mapa[w].second.first - ant)-ok,espaco);//for( int j = 0; j < mapa[w].second.first - ant; j++ ) cout << " ";
            putchar(ans[mapa[w].second.second]);
            //cout << ans[mapa[w].second.second];
            ant = mapa[w].second.first+1;
            w++;
            ok = 0;
        }
         printf("%.*s", (x-ant),espaco);
        i = w-1;
        //cout << "\n";
        putchar('\n');
    }
    return 0;
}