#include <cstdlib>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define mp              make_pair
#define pb              push_back
#define sz(x)           ((x).size())
#define For(i,a,b)      for(int i=(a);i<(b);++i)
#define rep(i,n)        For(i,0,(n))
#define all(v)          (v).begin(),(v).end()


int main( void )
{
    vector<long long>       b( 100, 0 );
    string                  str;
    long long               res = 0;

    getline( cin, str );

    rep( i, sz( str ) ) {
        if( isdigit( str[i] ) )
            ++b[str[i]-'0'];
        else
            ++b[str[i]-'a'+20];
    }

    rep( i, sz( b ) )
        res += b[i] * b[i];

    cout << res;
}