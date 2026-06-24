#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<ll> vll;
typedef pair<ll, ll> pll; typedef complex<ll> cll;
#define all(x) begin(x), end(x)
#define pb push_back
template<class A> void addlog( A a ) { cerr << a << endl; }
template<class A, class... B> void addlog( A a, B... b )
{ cerr << a << ' '; addlog(b...); }

char c;
int sum = 0, cur = 0;
int sign = +1;

int main () {
	while (cin >> c) {
		if (c == '+' || c == '-') {
			sum += cur;
			cur = 0;
			if (c == '+') sign = +1;
			if (c == '-') sign = -1;
		} 
			cur = 10 * cur + sign * (c - '0');
		
	} cout << sum + cur << endl;
	return 0;
}