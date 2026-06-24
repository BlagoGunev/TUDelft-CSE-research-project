#include <bits/stdc++.h>



using namespace std;



#define ll long long



struct cht {

	struct line {

		ll m, b;

		double x;



		double its(const line& p) const {

			return (p.b - b) / (1.0 * m - p.m);

		}

	};



	vector<line> lines;

	int s;



	cht() : s(0) { }



	void check(const line& l3) {

		int n;



		while ((n = lines.size()) - s > 1) {

			double x1 = lines[n - 2].its(l3);

			double x2 = lines[n - 2].its(lines[n - 1]);



			if (x1 < x2) lines.pop_back();

			else break;

		}

	}



	void add(ll m, ll b) {

		line p;

		p.m = m; p.b = b;



		check(p);



		if (lines.empty()) p.x = 0;

		else p.x = p.its(lines.back());



		lines.push_back(p);

	}



	ll query(ll x) {

		while (lines.size() - s > 1) {

			if (lines[s + 1].x <= x) s++;

			else break;

		}



		return lines[s].m * x + lines[s].b;

	}

};



const int N = 100100;



int a[N], b[N];



ll dp[N];



int main() {

	int n;

	scanf("%d", &n);



	for (int i = 1; i <= n; i++) {

		scanf("%d", a + i);

	}



	for (int i = 1; i <= n; i++) {

		scanf("%d", b + i);

	}



	cht e;



	dp[1] = 0;

	e.add(b[1], dp[1]);



	for (int i = 2; i <= n; i++) {

		dp[i] = e.query(a[i]);

		e.add(b[i], dp[i]);

	}



	printf("%I64d\n", dp[n]);



	return 0;

}