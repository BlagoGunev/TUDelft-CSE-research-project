#include<bits/stdc++.h>

using namespace std;

using ll = long long;



#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



int main() {

	fast_io



	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	#endif // Online Judge

	int t;

	cin >> t;

	while(t--) {

		ll a, b;

		cin >> a >> b;

		cout << min(a, min(b, (a + b) / 3)) << '\n';

	}

}