#include <bits/stdc++.h>

#define GOOD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define all(v) v.begin(), v.end()

#define sz(x) (int) (x).size()

#define pb push_back

#define nl "\n"

using namespace std;

using ll = long long;



#ifdef LOCAL

#include "C:\debug.h"

#else

#define dbg(...)

#endif



// both are prefix (--v)

template<typename T> vector<T>& operator-- (vector<T>& v) {for (auto &x : v) x--; return v;}

template<typename T> vector<T>& operator++ (vector<T>& v) {for (auto &x : v) x++; return v;}



//----------------------------------------------------//



void solve() {

	int n, iq;

	cin >> n >> iq;

	vector<int> v(n);



	for (int i = 0; i < n; i++) {

		cin >> v[i];

	}



	/*

	start from the back

	iq should ideally be 0 after last contest

	O(n)

	*/



	vector<int> ans(n);

	int cur_iq = 0;



	for (int i = n-1; i >= 0; i--) {

		if (cur_iq >= v[i])

			ans[i] = 1;

		else if (cur_iq < iq)

			ans[i] = 1, cur_iq++;



		// if (cur_iq < iq) {

		// 	ans[i] = 1;



		// 	if (cur_iq < v[i]) {

		// 		cur_iq++;

		// 	}

		// }

		// else if (cur_iq >= v[i]) {

		// 	ans[i] = 1;

		// }

	}



	for (int x : ans) {

		cout << x;

	}

}



//----------------------------------------------------//



void setIO() {

#ifdef FILE_IO

	freopen(pathToInput, "r", stdin);

    freopen(pathToOutput, "w", stdout);

    freopen(pathToDebug, "w", stderr);



    time_t cur_time = chrono::system_clock::to_time_t(chrono::system_clock::now());

    string cur_time_and_date = ctime(&cur_time);

    string time_text = "Time: " + cur_time_and_date.substr(11, 8);

    cout << time_text << nl;

    cerr << time_text << nl;

#endif

}



int main() {

	GOOD

    setIO();

    int t = 1;

	cin >> t;



	while (t--) {

		solve();

		cout << nl;

	}



	cout << nl << nl;

}



/*

bounds? - what is min and max values for variables?

time complexity?

edge cases?

*/