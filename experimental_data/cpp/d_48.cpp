#include <bits/stdc++.h>

using namespace std;



const int MAX = 1e5 + 5;

int n, l, fq[MAX], mk[MAX], a[MAX], s[MAX];

vector <int> pos[MAX];



int main() {

	scanf("%d", &n);



	int mx = 0;

	for(int i = 1; i <= n; i++) {

		int x; scanf("%d", &x);

		fq[x]++;

		pos[x].push_back(i);

		mx = max(mx, x);



		if(!mk[x]) {

			mk[x] = 1;

			a[++l] = x;

		}

	}



	for(int i = 1; i < mx; i++) {

		if(fq[i] < fq[i + 1]) {

			printf("-1\n");

			return 0;

		}

	}



	sort(a + 1, a + l + 1);



	int it = 0;

	for(int i = l; i > 0; i--) {

		while(fq[a[i]] > 0) {

			++it;

			for(int j = 1; j <= i; j++) {

				fq[j]--;

				assert(fq[j] >= 0);

				int p = pos[j].back();

				s[p] = it;

				pos[j].pop_back();

			}

		}

	}



	printf("%d\n", it);

	for(int i = 1; i <= n; i++)

		printf("%d ", s[i]);

	printf("\n");



	return 0;

}