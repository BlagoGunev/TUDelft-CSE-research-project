#include <cstring>
#include <cstdio>

using namespace std;

bool grid[1005][1005];

int main() {
	memset(grid, false, sizeof(grid));

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	int x, y;
	int sol = 0;
	for (int i = 1; i <= k; ++i) {
		scanf("%d%d", &x, &y);
		grid[x][y] = true;

		// upper left
		if (grid[x-1][y] && grid[x-1][y-1] && grid[x][y-1]) {
			sol = i;
			break;
		}

		// upper right
		if (grid[x-1][y] && grid[x-1][y+1] && grid[x][y+1]) {
			sol = i;
			break;
		}

		// lower right
		if (grid[x+1][y] && grid[x+1][y+1] && grid[x][y+1]) {
			sol = i;
			break;
		}

		// lower left
		if (grid[x+1][y] && grid[x+1][y-1] && grid[x][y-1]) {
			sol = i;
			break;
		}
	}

	printf("%d\n", sol);
	return 0;
}