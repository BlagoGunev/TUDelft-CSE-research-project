// In The Name Of God :
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std ;
using namespace __gnu_pbds;
#define X first 
#define Y second
//#define int long long
typedef long long ll ;
typedef pair < int , int > pii ; 
typedef pair < pii , int > pii_i ;
#define ordered_set(TYPE) tree<TYPE, null_type, less<TYPE>, rb_tree_tag, tree_order_statistics_node_update>
//#define "%I64d" "%I64d"
const long long maxn = 2e6 + 20 ;
const long long maxL = 20 ;
//const int inf = 1e12 ;
int n ;

main ( )
{
  cin >> n ;
  if ( n & 1 )
    cout << "black" ;
  else
    cout << "white\n1 2" ;
}