#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long T;
long long N;
long long A[1 << 19];

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		scanf("%lld", &N);
		for (int j = 1; j <= N; j++) scanf("%lld", &A[j]);
		for (int j = 1; j <= 60; j++) {
			long long c1 = -1, c2 = -1; bool flag = false;
			for (int k = 1; k <= N; k++) {
				long long val = A[k] % (1LL << j);
				if (c1 == val) continue;
				if (c2 == val) continue;
				if (c1 == -1) c1 = val;
				else if (c2 == -1) c2 = val;
				else flag = true;
			}
			if (flag == true || c2 == -1) continue;
			printf("%lld\n", (1LL << j));
			break;
		}
	}
	return 0;
}