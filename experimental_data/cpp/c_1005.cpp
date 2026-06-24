#include<cstdio>
#include <iostream>
#include<cmath>
#include<set>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);

const int mod = 1e9 + 7;
const int maxn = 120000 + 5;
const int M = 2e9;
ll pow2[32];
int a[maxn];
int b[maxn];
int n;

int main() {
	scanf("%d", &n);
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	sort(a, a + n);

	pow2[0] = 1;
	for (int i = 1; i < 32; i++) {
		if (pow2[i] > M) {
			break;
		}
		pow2[i] = pow2[i - 1] * 2;
	}
	//cout << num << endl;

	int cnt = 0;
	int i, j, k;

	for (i = 0; i < n; i++) {
		if (!b[i]) {
			for (j = 0; j < 32; j++) {
				if (pow2[j] > a[i]) {
					int temp = pow2[j] - a[i];
					int* p = lower_bound(a, a + n, temp);
					if (p - a < n && p != a + i) {
						if (*p == temp) {
							b[i] = b[p - a] = 1;
							goto st;
						}
					}
				}
			}
		}
	st:;
	}
	for (int i = 0; i < n; i++) {
		if (!b[i])cnt++;
	}
	printf("%d", cnt);
	return 0;
}