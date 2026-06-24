#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;

map<ll, vector<int>> ma;

// 시간 너무 빡센 거 같은데.
pli x[7000];
int val[7000];
int ch[7000];

int main() {
	int n;
	ll sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &x[i].first);
		x[i].second = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &val[i]);

	sort(x, x + n, greater<pli>());

	for (int i = 0; i < n - 1; i++) {
		if (ch[i]) continue;
		if (x[i].first == x[i + 1].first) {
			for (int j = i; j < n; j++)
				if ((x[i].first | x[j].first) == x[i].first)
					ch[j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
		if (ch[i]) sum += val[x[i].second];

	printf("%lld", sum);
}