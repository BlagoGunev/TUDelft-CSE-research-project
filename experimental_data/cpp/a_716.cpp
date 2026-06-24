#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

/* fast read */

int fastIn() {
	register int aa, bb, ch;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	ch == '-' ? (bb = 1, aa = 0) : (bb = 0, aa = ch - 48);
	while (ch = getchar(), ch >= '0' && ch <= '9') aa = (aa << 1) + (aa << 3) + ch - 48;
	return bb ? -aa : aa;
}

int main() {
	register int (*in)() = fastIn;
	int n = in();
	int k = in();
	int last = in();
	int cnt = 1;
	int a;
	for (int i = 2; i <= n; ++ i) {
		a = in();
		if (a - k > last) cnt = 1;
		else cnt ++;
		last = a;
	}
	cout << cnt << endl;
	return 0;
}