#include <bits/stdc++.h>

#define TT double



using namespace std;



#define point complex<TT>

#define x real()

#define y imag()



const TT eps = 1e-9;

const TT PI = acos(-1.0);

const int N = 3030;



bool ok[N][N];



int main()

{

	int n, radius;

	scanf("%d%d", &n, &radius);



	vector <point> pts;

	for (int i = 0; i < n; i++) {

		int a, b;

		scanf("%d%d", &a, &b);

		pts.push_back(point(a, b));

	}



	for (int center = 0; center < n; ++center) {

		bool start = false;

		TT L = 0, R = 100;

		for (int i = 0; i < n; ++i) {

			TT d = sqrt(norm(pts[i] - pts[center]));

			if (d < radius) continue;



			TT theta = arg(pts[i] - pts[center]);

			TT diff = asin(1.*radius / d);

			TT newL = theta - diff;

			TT newR = theta + diff;

			while ((!start && newL < 0) || (start && newR < L)) {

			    newL += 2.*PI;

			    newR += 2.*PI;

			}



			start = true;

			L = max(L, newL);

			R = min(R, newR);

			if (L > R) break;

		}



		for (int i = 0; i < n; i++) {

			if (i == center) continue;

			TT angle = arg(pts[i] - pts[center]);

			while (angle < L) angle += 2.*PI;

			ok[center][i] = (!start || angle <= R);

		}

	}



	int ans = 0;

	for (int i = 0; i < n; ++i)

		for (int j = i + 1; j < n; ++j)

			ans += (ok[i][j] && ok[j][i]);



	printf("%d\n", ans);

	return 0;

}