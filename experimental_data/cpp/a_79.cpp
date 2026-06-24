#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int x, y;
int C() {
	if (x >= 2 && y >= 2) {
		x -= 2; y -= 2; return 0;
	}
	if (x >= 2) return 1;
	if (y >= 2) {
		if (1 == x) {
			if (y >= 12) {
				x -= 1; y -= 12; return 0;
			} else return 1;
		} else if (y >= 22) {
			y -= 22; return 0;
		} else return 1;
	}
	return 1;
}
int H() {
	if (y >= 22) {
		y -= 22; return 0;
	} else if (y >= 12) {
		if (x >= 1) {
			x -= 1; y -= 12; return 0;
		} else return 1;
	} else if (y >= 2) {
		if (x >= 2) {
			x -= 2; y -= 2; return 0;
		} else return 1;
	}
	return 1;
}
int main() {
	scanf("%d%d", &x, &y);
	for (;;) {
		if (C()) {puts("Hanako"); break;}
		if (H()) {puts("Ciel"); break;}
	}
	return 0;
}