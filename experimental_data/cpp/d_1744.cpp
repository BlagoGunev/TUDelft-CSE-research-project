#include <iostream>

#include <algorithm>

#include <string>

#include <cmath>

#include <stack>

#include <vector>

#include <set>

#include <map>

#include <ctime>

#include <chrono>

#include <iterator>

#include <queue>



#define ll long long

#define y first

#define x second

#define ff first

#define ss second

#define pb push_back

#define vi vector<int>

#define vii vector<pair<int, int>>

#define pi pair<int, int>

#define vb vector<bool>

#define watch(x) cout << (#x) << ": " << (x) << endl



using namespace std;



const long long INF = 1e18;

const int inf = 1e9;



const int MOD = (1e9) + 7;



struct triple {

	ll a, b, c;

};



struct edge {

	ll a, b, c;

};



bool comp(int a, int b) {

	return a > b;

}



bool comp1(triple a, triple b) {

	return a.c < b.c;

}





void pre_main() {

	int n, a, b, k = 0, q;

	cin >> n;

	vector<int> v, arr;

	for (int i = 0; i < n; i++) {

		cin >> a;

		b = a;

		while (b % 2 == 0 && b) {

			k++;

			b /= 2;

		}

		b = i + 1;

		q = 0;

		while (b % 2 == 0 && b) {

			q++;

			b /= 2;

		}

		arr.pb(q);

	}

	sort(arr.begin(), arr.end(), comp);

	if (k >= n) {

		cout << 0 << endl;

		return;

	}

	int i = 0, ans = 0;

	while (k < n && i < n) {

		k += arr[i];

		i++;

		ans++;

		if (k >= n) {

			cout << ans << endl;

			return;

		}

	}

	cout << -1 << endl;

}

int main() {

	ios::sync_with_stdio(0);

	cin.tie(0);

	int t;

	cin >> t;

	//t = 1;

	while (t--) {

		pre_main();

	}



	return 0;

}