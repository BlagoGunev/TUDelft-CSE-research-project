#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include <utility>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0; i<n; i++)
#define formap(it) for(map<int, int>::iterator it = m.begin(); it!=m.end(); it++)

int a[200001], b[200001];

void solve() {
	int n; cin >> n;
	int dem=0, x, y;
	forn(i, n) {
		cin >> x >> y;
		if (x > y) dem++;
	}
	cout << dem << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}