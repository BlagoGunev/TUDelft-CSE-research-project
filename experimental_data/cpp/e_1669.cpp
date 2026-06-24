#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int cnt[150][150];

int n; 



void init(){

	for (int i = 'a'; i <= 'k'; i++){

		for (int j = 'a'; j <= 'k'; j++){

			cnt[i][j] = 0;

		}

	}

}

/*有且仅有一个字符相同则OK，那组合一共有26*26中 ；

那我们只要去记录每一种组合的个数就好*/

int main(){

	int t;

	cin >> t;

	while (t--){

		scanf("%d", &n);

		long long ans = 0;

		char x, y;

		init();

		for (int i = 0; i < n; i++){

			cin >> x >> y;

			for (int j = 'a'; j <= 'k'; j++){

				if (j != y) ans += cnt[x][j];

				if (x != j) ans += cnt[j][y];

			}

			cnt[x][y]++;

		}

		printf("%lld\n", ans);

	}

    return 0;

}