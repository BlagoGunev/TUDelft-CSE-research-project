#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
typedef long long ill;
const int N = 2e5 + 7;
const int M = N;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
//const double PI = acos(-1);

int main() {
	//std::ios::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);
	//freopen("in.txt", "r", stdin);
	
	int n, a[3], b[3];
	scanf("%d", &n);
	for (int i = 0; i < 3; ++ i) scanf("%d", &a[i]);
	for (int i = 0; i < 3; ++ i) scanf("%d", &b[i]);
	
	int ans1 = min(a[0], b[0] + b[2]) + min(a[1], b[1] + b[0]) + min(a[2], b[2] + b[1]);
	int ans2 = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
	
	cout << n - ans1 << " " << ans2 << "\n";
	
	return 0;
}