#include <bits/stdc++.h>

 

/// #pragma GCC optimize("Ofast")

/// #pragma GCC target("avx,avx2,fma")

 

using namespace std;

 

#ifdef LOCAL

	ifstream fin("input.txt");

	ofstream fout("output.txt");

#else

	#define fin cin

	#define fout cout

#endif

 

struct vect {

	int x, pos;

} v[3005];

 

int tc, n;

 

bool cmp(vect a, vect b) {

	return (a.x < b.x);

}

 

void solve() {

	fin >> n;

 

	for (int i = 0; i < n; ++ i) {

		fin >> v[i].x;

 

		v[i].pos = i;

	}

 

	if (n == 1) {

		fout << "0" << "\n";

		return;

	}

 

	sort(v, v + n, cmp);

 

	int res = 1, Max = 1;

 

	for (int i = 1; i < n; ++ i) {

		if (v[i].pos > v[i - 1].pos) {

			++ res;

			Max = max(Max, res);

		}

		else

			res = 1;

	}

 

	fout << n - Max << "\n";

 

	return;

}

 

int main() {

	fin >> tc;

 

	while (tc --) {

		solve();

	}

 

	return 0;

}