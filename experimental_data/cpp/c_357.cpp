#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <list>
#include <bitset>
#include <complex>
#include <climits>
#include <cfloat>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pLL;

#define FOR(i,a,b) for ( int i(a) ; i < int(b) ; i++)
#define ROF(i,a,b) for ( int i(a) ; i >= int(b) ; i--)
#define FOREACH(i,c) for ( __typeof ( (c).begin() ) i = (c).begin() ; i != (c).end() ; i++ )
#define ALL(c) c.begin() , c.end()
#define UNIQUE(c) (c).resize(unique( ALL(c) ) - (c).begin() )
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define gcd __gcd
#define bcnt(x) ((__builtin_popcoutn(x)))


const int MAX_N = 300000 + 20;
int a[MAX_N] , Par[MAX_N];
int n,m;


int find( int v ) {
	if ( a[ Par[v] ] == 0 )
		return Par[v];
	else
		return Par[v] = find( Par[v] );
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	FOR(i,0,n) Par[i] = i+1;
	FOR(i,0,m){
		int l , r , winner;
		cin >> l >> r >> winner;
		-- l , r--;
		int j = l;
		while( j <= r ){
			if ( a[j] == 0 && winner-1 != j ) a[j] = winner;
			j = find( j );
		}

	}
	FOR(i,0,n) cout << a[i] << ' ';
	cout << endl;
	return 0;
}