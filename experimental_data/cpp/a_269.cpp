#include<cstdio>

#include<algorithm>

using namespace std;

 

int main() {

    int n; scanf("%d", &n);

	int p = 0, maxk = 0;

	for(int i = 0; i < n; i++) {

		int k, a; scanf("%d %d", &k, &a);

		maxk = max(k, maxk);

		int m = 0, s = 1;

		while(s < a) {

			s *= 4;

			m++;

		}

		p = max(p, k+m);

	}

	if(p == maxk) {

		p++;

	}

	printf("%d\n", p);

}