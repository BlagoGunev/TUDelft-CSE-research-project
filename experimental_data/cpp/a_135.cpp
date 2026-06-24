#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <sstream>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define MP make_pair

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = (1 << 31) - 1;
const long long LLINF = (1LL << 63) - 1;

typedef long long ll;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> stat;
	int n;
	cin >> n;
	vector<int> a(n, 0);
	bool can = false;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		can = can || a[i] > 1;
	}
	sort(all(a));
	vector<int> res(a);
	int c = 0;
	for (int i = a.size() - 1; i >= 0; --i) {
		c = max(c, 1);
		if (can) {
			if (i - c >= 0)
				res[i]= min(res[i], a[i - c]);
			else
				res[i] = min(res[i], 1);
		}
	}
	if (!can)
		res.back() = 2;
	for (int i = 0 ;i < n; ++i) {
		printf("%d ", res[i]);
	}
	return 0;
}