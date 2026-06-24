#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue> 
#include <cfloat>
#include <string> 
#include <climits> 
#include <cstring> 
#include <cassert> 
#include <complex>

using namespace std;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define EPS 1e-7

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)
#define FORIT(it, i) for(typeof((i).begin()) it = (i).begin(); it != (i).end(); ++it)

#define ALL(V) V.begin(), V.end()
#define S(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }

typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio( false );
    int n;
    cin>>n;
    vector<int> vec(n);
    REP(i, n) {
        int aux;
        cin>>aux;
        aux--;
        vec[aux] = i;
    }
    
    int m;
    cin>>m;
    int64 a = 0, b = 0;
    REP(i, m) {
        int q;
        cin>>q;
        q--;
        a += vec[q] + 1;
        b += n - vec[q];
    }
    
    cout << a << " " << b << '\n';
    
	return 0;
}