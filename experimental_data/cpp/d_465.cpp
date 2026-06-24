#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <bitset>
#include <complex>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int a[8][3], b[8][3], used[8];
int d[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

double len(LL x, LL y, LL z)
{
	return sqrt((double)x*x+(double)y*y+(double)z*z);
}

long long to_int(double x)
{
	if (x >= 0) return (long long)(x+0.4);
	else return (long long)(x-0.4);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	

	for (int i = 0; i < 8; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

	int x0 = a[0][0], y0 = a[0][1], z0 = a[0][2];
	b[0][0] = a[0][0], b[0][1] = a[0][1], b[0][2] = a[0][2];
	for (int i = 1; i < 8; i++)
		for (int j = 1; j < 8; j++) if (i != j)
			for (int u = 0; u < 6; u++)
				for (int v = 0; v < 6; v++) {
					int x1 = a[i][d[u][0]]-x0, y1 = a[i][d[u][1]]-y0, z1 = a[i][d[u][2]]-z0;
					int x2 = a[j][d[v][0]]-x0, y2 = a[j][d[v][1]]-y0, z2 = a[j][d[v][2]]-z0;
					if ((LL)x1*x2+(LL)y1*y2+(LL)z1*z2 != 0) continue;
					if ((LL)x1*x1+(LL)y1*y1+(LL)z1*z1 != (LL)x2*x2+(LL)y2*y2+(LL)z2*z2) continue;
					if (x1 == 0 && y1 == 0 && z1 == 0) continue;
					LL x3 = (LL)y1*z2-(LL)z1*y2;
					LL y3 = (LL)z1*x2-(LL)x1*z2;
					LL z3 = (LL)x1*y2-(LL)y1*x2;
					double ret = len(x1, y1, z1)/len(x3, y3, z3);
					int xx = to_int(x3*ret);
					int yy = to_int(y3*ret);
					int zz = to_int(z3*ret);

					memset(used, 0, sizeof(used));
					used[0] = 1;
					int ok = 1;
					for (int vv = 1; vv < 8; vv++) {
						int nx = x0, ny = y0, nz = z0;
						if (vv >> 0 & 1) nx += x1, ny += y1, nz += z1;
						if (vv >> 1 & 1) nx += x2, ny += y2, nz += z2;
						if (vv >> 2 & 1) nx += xx, ny += yy, nz += zz;
						ok = 0;
						for (int o = 0; o < 8; o++) if (! used[o]) {
							for (int oo = 0; oo < 6; oo++)
								if (a[o][d[oo][0]] == nx && a[o][d[oo][1]] == ny && a[o][d[oo][2]] == nz) {
									b[o][0] = nx, b[o][1] = ny, b[o][2] = nz;
									ok = used[o] = 1;
									break;
								}
							if (ok) break;
						}
						if (! ok) break;
					}
					if (! ok) continue;

					// ok
					cout << "YES" << endl;
					for (int o = 0; o < 8; o++) cout << b[o][0] << ' ' << b[o][1] << ' ' << b[o][2] << endl;
					return 0;
				}

	cout << "NO" << endl;

	return 0;
}