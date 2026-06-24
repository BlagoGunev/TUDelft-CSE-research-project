#include <iostream>

#define MULTI int _T; cin >> _T; while(_T--)

using namespace std;

typedef long long ll;

 

int n, k;

 

int main () {

	ios::sync_with_stdio(0);

	cin.tie(0);

	

	MULTI {

		cin >> n >> k;

		int l = 1, r = n, _ = 1;

		while (l <= r) cout << ((_ ^= 1) ? l++ : r--) << ' ';

		cout << endl;

	}

}