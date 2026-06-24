#include <bits/stdc++.h>
using namespace std;
long long t,a,b;

int main() {
	cin >> t;
	while(t--) {
		cin >> a >> b;
		if ((a+b)%2==0) {
			cout << "Bob" << endl;
		}
		else {
			cout << "Alice" << endl;
		}
	}
}