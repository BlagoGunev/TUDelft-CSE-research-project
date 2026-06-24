// by gantheory™
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, k;
vector< int > ans( N, 0 );

void go( int l, int r, int& cut, int goal ) {
  if ( cut >= goal )
    return;
  if ( ( r - l ) <= 1 )
    return;
  int mid = ( l + r ) / 2;
  swap( ans[ mid - 1 ], ans[ mid ] );
  cut += 2;

  go( l, mid, cut, goal );
  go( mid, r, cut, goal );
}
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.setf(ios::fixed);cout.precision(20);
  cin >> n >> k;
  for ( int i = 0 ; i < n ; ++i ) {
    ans[ i ] = i + 1;
  }
  int init = 0;
  ++init;
  go( 0, n, init, k );

  if ( init != k ) {
    cout << "-1" << '\n';
    return 0;
  }
  for ( int i = 0 ; i < n ; ++i ) {
    cout << ans[ i ] << " \n"[ i + 1 == n ];
  }
}