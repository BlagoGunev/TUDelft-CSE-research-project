#include <iostream>

#include <algorithm>

using namespace std;



int a[200005];



int main() {

	int n, i, j, l, r, m, mx, ans = 0;

	cin >> n;

	for (i = 0; i < n; i++) scanf("%d", a + i);

	

	sort(a, a + n);

	n = unique(a, a + n) - a;

	mx = a[n - 1] * 2;



	for (i = n - 2; i >= 0 && a[i] > ans; --i) {

		l = i;

		

		for (j = a[i] * 2; j <= mx; j += a[i]) {

			r = n - 1;



			while (l < r) {

				m = l + (r - l + 1) / 2;



				if (a[m] < j)

					l = m;

				else

					r = m - 1;

			}



			ans = max(ans, a[r] % a[i]);

		}

	}



	cout << ans << endl;

	return 0;

}