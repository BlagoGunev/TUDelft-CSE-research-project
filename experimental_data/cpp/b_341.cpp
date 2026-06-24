// In The Name Of GOD
// Author : Arashking

#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cstring>
#include <complex>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define F first
#define S second
#define X real()
#define Y imag()
#define MP make_pair
#define PB push_back 
#define ALL(n) (n).begin() , (n).end()
#define FOR(i,a,b) for ( int i = (int)a ; i < (int)b ; ++i )

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef complex<double> point;
typedef unsigned long long ull;

int n;

vector<int> d;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	FOR(i,0,n) {
		int x;
		cin >> x;
		if ( d.empty() || x > d.back() ) {
			d.PB(x);
		}
		else {
			int p = upper_bound(d.begin(),d.end(),x)-d.begin();
			d[p] = x;
		}
	}
	cout << d.size() << endl;
	return 0;
}