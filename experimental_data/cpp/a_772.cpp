#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main () {
	int n, p;
	
	scanf("%d%d", &n, &p);
	
	vector<int> a(n), b(n);
	long long sumA = 0;
	double tmin = 1e+9;
	
	for (size_t i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		sumA += a[i];
		tmin = min (tmin, (double) b[i] / a[i]);
	}

	if (sumA <= p) {
		cout << "-1\n";
		return 0;
	}

	double tl = tmin;
	double tr = 2e+10; 
	double tm; 
	const double EPS = 3e-6;

	double sumE = 0; 
	while (abs(tr - tl) > EPS) {
		tm = (tl + tr) / 2.0;

		sumE = 0; 
		for (size_t i = 0; i < n; ++i) {
			sumE -= min (0.0, b[i] - a[i] * tm);
		}
		
		if (sumE <= p * tm) {
			tl = tm;
		} else {
			tr = tm; 
		}
	}

	double T = (tl + tr) / 2.0;
	printf("%.10lf\n", T);

	return 0; 
}