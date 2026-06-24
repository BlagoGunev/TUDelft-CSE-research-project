#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[1000 + 2];
int m[1000 + 2][1000 + 2];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		fill(a, a + n + 1, (1 << 30) - 1);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> m[i][j];
				if(i != j) {
					a[i] &= m[i][j];
					a[j] &= m[i][j];
				}
			}
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i != j && m[i][j] != (a[i] | a[j]))
					goto no;
		cout << "YES\n";
		for(int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
		continue;
no:
		cout << "NO\n";
	}
}