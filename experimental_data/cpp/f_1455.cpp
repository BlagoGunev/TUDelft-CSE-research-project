#include<bits/stdc++.h>



using namespace std;



const int _ = 610;



int n, k;



char s[_];



string f[_][2];



char nx(char ch) {

	return 'a' + (ch - 'a' + 1) % k;

}



char pr(char ch) {

	return 'a' + (ch - 'a' + k - 1) % k;

}



string g(string x, int i, int op) {

	if (x == "~")return x;

	if (!op) x[i - 1] = nx(x[i - 1]);

	else x[i - 1] = pr(x[i - 1]);

	return x;

}



string sp(string x, int i) {

	if (x == "~")return x;

	swap(x[i - 1], x[i - 2]);

	return x;

}



signed main() {

	int T;

	scanf("%d", &T);

	while (T--) {

		scanf("%d%d", &n, &k);

		scanf("%s", s + 1);

		f[0][0] = s[1];

		f[0][1] = "~";

		for (int i = 1; i <= n; ++i) {

			// O

			f[i][0] = min(f[i - 1][1], f[i - 1][0]);

			// U

			f[i][0] = min(f[i][0], min(g(f[i - 1][0], i, 0), g(f[i - 1][1], i - 1, 0)));

			// D

			f[i][0] = min(f[i][0], min(g(f[i - 1][0], i, 1), g(f[i - 1][1], i - 1, 1)));

			// L

			if (i > 1) f[i][0] = min(f[i][0], sp(f[i - 1][0], i));

			if (i > 2) f[i][0] = min(f[i][0], sp(f[i - 1][1], i - 1));

			// R

			if (i < n) f[i][1] = sp(f[i - 1][0] + s[i + 1], i + 1);

			if (i < n) f[i][0] += s[i + 1];

		}

		cout << f[n][0] << "\n";

	}

	return 0;

}