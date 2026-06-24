#include <bits/stdc++.h>



using namespace std;



typedef long long ll;

typedef pair < int, int > ii;



const int inf = 1e9 + 333;

const ll linf = 1e18 + inf;



const int N = 200 + 5;

const int S = 200 + 1;

const int T = 200 + 2;



int n;

int a[N], d[N][N];



int prime(int x) {

	int sq = sqrt(x) + .5;

	for(int i = 2; i <= sq; i++)

		if(x % i == 0)

			return 0;

	return 1;

}



bool used[N];



bool dfs(int x) {

	if(x == T)

		return 1;

	used[x] = 1;

	for(int i = 1; i < N; i++) {

		if(!used[i] and d[x][i] and dfs(i)) {

			d[x][i]--;

			d[i][x]++;

			return 1;

		}

	}

	return 0;

}



int main() {



	scanf("%d", &n);



	for(int i = 1; i <= n; i++) {

		scanf("%d", a + i);

		if(a[i] & 1) {

			d[S][i] = 2;

		}

		else {

			d[i][T] = 2;

		}

	}



	for(int i = 1; i <= n; i++) {

		if(a[i] & 1) {

			for(int j = 1; j <= n; j++) {

				if(prime(a[i] + a[j])) {

					d[i][j] = 1;

				}

			}

		}

	}



	int ans = 0;



	for(; ;) {

		memset(used, 0, sizeof(used));

		if(!dfs(S))

			break;

		ans++;

	}



	if(ans != n) {

		puts("Impossible");

		return 0;

	}



	memset(used, 0, sizeof(used));



	vector < vector < int > > ansV;



	for(int i = 1; i <= n; i++) {

		if(!used[i] and a[i] % 2) {

			vector < int > v;

			used[i] = 1;

			v.push_back(i);

			int x;

			for(int j = 1; j <= n; j++) {

				if(d[j][i]) {

					x = j;

					break;

				}

			}

			while(!used[x]) {

				used[x] = 1;

				v.push_back(x);

				for(int j = 1; j <= n; j++) {

					if(a[x] % 2) {

						if(!used[j] and d[j][x]) {

							x = j;

							break;

						}

					}

					else {

						if(!used[j] and d[x][j]) {

							x = j;

							break;

						}

					}

				}

			}

			ansV.push_back(v);

		}

	}



	printf("%d\n", ansV.size());



	for(auto v : ansV) {

		printf("%d", v.size());

		for(auto x : v) {

			printf(" %d", x);

		}

		puts("");

	}



	return 0;

}