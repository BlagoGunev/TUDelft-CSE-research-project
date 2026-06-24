#include<bits/stdc++.h>

using namespace std;

int main() {

	int n, d, h;

	scanf("%d%d%d", &n, &d, &h);

	if(d > 2 * h || (d == 1 && n != 2)) {

		puts("-1");

		return 0;

	}

	for(int i = 1; i <= h; ++i)

		printf("%d %d\n", i, i + 1);

	int x = 1;

	for(int i = 1; i <= d - h; ++i) {

		int y = h + 1 + i;

		printf("%d %d\n", x, y);

		x = y;

	}

	for(int i = d + 2; i <= n; ++i)

		printf("%d %d\n", i, (d == h) ? 2 : 1);

	return 0;

}