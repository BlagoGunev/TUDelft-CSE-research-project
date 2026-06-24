#include <iostream>
#include <algorithm>
#include <climits>
#include <random>
#include <vector>

using namespace std;

typedef long long int Z;

mt19937 rng(2134152);

int main() {
	cin.sync_with_stdio(false);
	
	Z n;
	cin >> n;
	
	if(n == 1) {
		cout << "YES\n1\n";
		return 0;
	}
	if(n == 2) {
		cout << "YES\n1\n2\n";
		return 0;
	}
	if(n == 4) {
		cout << "YES\n1\n3\n2\n4\n";
		return 0;
	}
	
	for(Z i = 2; i < n; ++i) {
		if(n % i == 0) {
			cout << "NO\n";
			return 0;
		}
	}
	
	vector<Z> cand(n - 1);
	for(Z i = 1; i < n; ++i) cand[i - 1] = i;
	
	Z root = -1;
	for(Z a : cand) {
		Z p = 1;
		bool ok = true;
		for(Z i = 0; i < n - 2; ++i) {
			p *= a;
			p %= n;
			if(p == 1) {
				ok = false;
				break;
			}
		}
		if(ok) {
			root = a;
			break;
		}
	}
	
	vector<Z> rootpows(n + 5);
	rootpows[0] = 1;
	for(Z i = 1; i < n + 5; ++i) {
		rootpows[i] = root * rootpows[i - 1] % n;
	}
	
	cout << "YES\n";
	Z d = 0;
	for(Z i = 0; i < n - 1; ++i) {
		if(d < 0) {
			cout << rootpows[n - 1 + d] << "\n";
			d = -d;
			++d;
		} else {
			cout << rootpows[d] << "\n";
			++d;
			d = -d;
		}
	}
	cout << n << "\n";
	
	return 0;
}