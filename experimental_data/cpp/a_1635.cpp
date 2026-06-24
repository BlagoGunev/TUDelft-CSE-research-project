#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std ;

// FAST I/O
#define GeekDav cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0) ;
#define endl '\n' ;

typedef long long ll ;
typedef unsigned long long ull ;

const ll   llmin  = -1e18 ;
const ll   llmax  =  1e18 ;
const int  imin   = -1e9  ;
const int  imax   =  1e9  ;
// imax , imin may need sometime +/- 1

// modluo
const int mod = 1e9 + 7  ;
const int mod2 = 998244353 ;
const int N = 1e5 + 5;

// Fast Functions
ll  fstp ( int b , int p ) { if (!p) return 1 ; ll x = fstp ( b , p >> 1 ) ; x = x * x ; x %= mod ;  if ( p & 1 ) x *= b ; return  x % mod  ; }
int gcd  ( int a , int b ) { return ( (!b) ? a : gcd (b , a % b ) ) ; }

// no extra spaces ( " \n" [i == n - 1] )
// freopen("bar.in","r",stdin) ;


void solve () {
    // your code
    ll n , sum = 0 , x ; cin >> n ;
    ll arr[n] ;
    for (int i = 0 ; i < n ; i++ ) {cin >> x ; sum |= x ;      }
    cout << sum << endl ; 
    return ;
}

void test  ( int t = 1 ) {
    while (t--) solve () ;
}

int main() {
    GeekDav
    int t ; cin >> t ;
    test(t) ;
    // test() ;
    return 0 ;
}

/*
  ::: holder spaceA

*/