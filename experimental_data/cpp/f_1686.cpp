#include <cstdio>

#include <vector>

 

const int N = 200;

int t, n;

int a[N];

bool u[N];

 

int main() {

	scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		for (int i = 0; i < n; ++i) {

			scanf("%d", a + i);

			--a[i];

			u[i] = 0;

		}

		std::vector<int> ans;

		for (int i = 0; i < n; ++i) if (!u[i]) {

			int p = -1;

			if (i) for (p = 0; ans[p] != i - 1; ++p);

			int cur = i;

			do {

				ans.insert(ans.begin() + p + 1, cur);

				u[cur] = 1;

				cur = a[cur];

			} while (cur != i);

		}

		for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i] + 1);

		printf("\n");

	}

	return 0;

}