#include <bits/stdc++.h>

using namespace std;



const int MAX = 1e6 + 5;

int n, x;

char ans[MAX], s[MAX];



int main() {

	scanf("%d%d", &n, &x);



	ans[0] = '9' + 1;

	for(int d = 1; d < 10; d++) {

		int cd = d, cc = 0;

		s[0] = '0' + d;



		for(int i = 2; i <= n; i++) {

			int r = cd * x + cc;

			cd = r % 10;

			cc = r / 10;

			s[i - 1] = '0' + cd;

		}



		if(cd == 0)

			continue;



		if(cd * x + cc == d) {

			int l = strlen(s);

			reverse(s, s + l);

			

			if(strcmp(s, ans) < 0)

				for(int i = 0; i < l; i++)

					ans[i] = s[i];

		}

	}



	if(ans[0] == '9' + 1)

		printf("Impossible\n");



	else printf("%s\n", ans);



	return 0;

}