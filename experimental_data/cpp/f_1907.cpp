#include<bits/stdc++.h>
using namespace std;
int main() {
	int total;
	cin >> total;
	while (total--) {
		int n;
		cin >> n;
		int a[n];
		int mn = INT_MAX;
		int mx = -INT_MAX;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		if (mn == mx) {
			cout << "0\n";
			continue;
		}
		int mnn = mn;
		//we find a chain of mn, determine the starting
		int i = 0;
		while (a[i] != mn) {
			i++;
		}
		//if at 0, we might find one BEHIND
		if (i == 0) {
			if (a[n - 1] == mn) {
				i = n - 1;
				while (a[i] == mn) {
					i--;
				}
				i++;
			}
		}
		// cout << i + 1 << '\n';
		//need to do (n - i)%n shifts
		int shift = (n - i) % n;
		int b[n];
		for (int i = 0; i < n; i++) {
			b[i] = a[((i - shift) % n + n) % n];
		}
		int f = 0;
		for (int i = 1; i < n; i++) {
			// cout << b[i] << ' ';
			if (b[i] < b[i - 1]) f = 1;
		}
		// cout << f << '\n';
		int cost1 = INT_MAX;
		if (f == 0) {
			cost1 = shift;
		}
		//do same with greatest
		i = 0;
		mn = mx;
		while (a[i] != mn) {
			i++;
		}
		//if at 0, we might find one BEHIND
		if (i == 0) {
			if (a[n - 1] == mn) {
				i = n - 1;
				while (a[i] == mn) {
					i--;
				}
				i++;
			}
		}
		// cout << i + 1 << '\n';
		//need to do (n - i)%n shifts
		shift = (n - i) % n;
		for (int i = 0; i < n; i++) {
			b[i] = a[((i - shift) % n + n) % n];
		}
		f = 0;
		for (int i = 0; i < n; i++) {
			// cout << b[i] << ' ';
			if (i && b[i] > b[i - 1]) f = 1;
		}
		int cost2 = INT_MAX;

		if (f == 0) cost2 = shift + 1;
		// cout << cost1 << ' ' << cost2 << '\n';
		for (int i = 0; i < n / 2; i++) {
			swap(a[i], a[n - i - 1]);
		}
		// for (int i = 0; i < n; i++) {
		// 	cout << a[i] << ' ';
		// }
		// cout << '\n';
		i = 0;
		mn = mx;
		while (a[i] != mn) {
			i++;
		}
		//if at 0, we might find one BEHIND
		if (i == 0) {
			if (a[n - 1] == mn) {
				i = n - 1;
				while (a[i] == mn) {
					i--;
				}
				i++;
			}
		}
		// cout << i + 1 << '\n';
		//need to do (n - i)%n shifts
		shift = (n - i) % n;
		// cout << a[i] << '\n';
		// cout << shift << '\n';
		for (int i = 0; i < n; i++) {
			b[i] = a[((i - shift) % n + n) % n];
		}
		f = 0;
		for (int i = 0; i < n; i++) {
			// cout << b[i] << ' ';
			if (i && b[i] > b[i - 1]) f = 1;
		}
		int cost3 = INT_MAX;

		if (f == 0) cost3 = shift + 2;
		i = 0;
		mn = mnn;
		while (a[i] != mn) {
			i++;
		}
		//if at 0, we might find one BEHIND
		if (i == 0) {
			if (a[n - 1] == mn) {
				i = n - 1;
				while (a[i] == mn) {
					i--;
				}
				i++;
			}
		}
		// cout << i + 1 << '\n';
		//need to do (n - i)%n shifts
		shift = (n - i) % n;
		for (int i = 0; i < n; i++) {
			b[i] = a[((i - shift) % n + n) % n];
		}
		f = 0;
		for (int i = 0; i < n; i++) {
			// cout << b[i] << ' ';
			if (i && b[i] < b[i - 1]) f = 1;
		}
		int cost4 = INT_MAX;

		if (f == 0) cost4 = shift + 1;
		int c1 = min(cost1, cost2);
		int c2 = min(cost3, cost4);
		if (min(c1, c2) == INT_MAX) {
			cout << "-1\n";
		}
		else {
			cout << min(c1, c2) << '\n';
		}

	}
}