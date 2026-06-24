#include <bits/stdc++.h>

using namespace std;


int main() {
	int n; cin >> n;
	unsigned long long int a = 2;
	unsigned long long int pow = 2;
	while(--n) {
		a += pow * 2;
		pow *= 2;	
	}
	cout << a;	
	
	return 0;
}