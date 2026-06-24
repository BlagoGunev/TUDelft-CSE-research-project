#include      <algorithm>
#include      <cmath>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <vector>
#include      <cstdarg>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
template<typename T> inline T ceilDiv(T l, T r) {return (l / r) + ((l % r) != 0);}
//const int INFTY = numeric_limits<int>::max();
int q[100005], a[100005];
int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int m, n;
	cin >> m;
	for (int i = 0; i < m; i += 1) cin >> q[i];
	cin >> n;
	for (int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n, greater<int>());
	int nMin = *min_element(q, q + m);
	for (int i = 0; i < n; ) {
		for (int j = 0; j < nMin; j += 1, i += 1);
		if (i < n) a[i++] = 0;
		if (i < n) a[i++] = 0;
	}
	long long r = 0;
	for (int i = 0; i < n; i += 1) r += a[i];
	cout << r << endl;

	return 0;
}