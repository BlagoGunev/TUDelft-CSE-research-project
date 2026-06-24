#include <stdio.h>
#include <algorithm>
#include <string.h>

int w, h;
int m1[51][51], m2[51][51];
int row1[51] = {}, col1[51] = {};
int row2[51] = {}, col2[51] = {};

bool ok(int x, int y) {
	return
		m1[y][x] > row1[y] && m1[y][x] > col1[x] &&
		m2[y][x] > row2[y] && m2[y][x] > col2[x];
}

void solve() {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (m1[y][x] > m2[y][x]) std::swap(m1[y][x], m2[y][x]);
			if (!ok(x, y)) {
				printf("Impossible\n");
				return;
			}
			row1[y] = m1[y][x];
			row2[y] = m2[y][x];
			col1[x] = m1[y][x];
			col2[x] = m2[y][x];
		}
	}

	printf("Possible\n");
}

int main() {
	scanf("%d %d", &h, &w);
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			scanf("%d", &m1[y][x]);
		}
	}
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			scanf("%d", &m2[y][x]);
		}
	}
	
	solve();
	
	return 0;
}