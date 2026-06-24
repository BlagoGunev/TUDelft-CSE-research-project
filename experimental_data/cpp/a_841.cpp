#include <bits/stdc++.h>
using namespace std;

int n, f, cn[26];
string b;

int main() {
	cin >> n >> f >> b;
	for (int i = 0; i < (int) (b.size()); ++i) {
		cn[b[i] - 'a']++;
		if (cn[b[i] - 'a'] > f)
			return puts("NO"), 0;
	}
	puts("YES");
	return 0;
}