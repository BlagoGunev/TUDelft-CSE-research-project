#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define LL long long
#define mp make_pair
#define sqr(x) ((x) * (x))

const double EPS = 1e-9;
const double INC_EPS = 1e-7;
const int N = 1e5 + 5;

int a[N], b[N], n, ans[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i =0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		ans[a[i]] = b[i];
	for (int i =  1; i <= n; i++)
		cout << ans[i] << ' ';
	return 0;
}