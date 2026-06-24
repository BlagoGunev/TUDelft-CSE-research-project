// Problem: C. Anu Has a Function

// Contest: Codeforces - Codeforces Round #618 (Div. 2)

// URL: https://codeforces.com/contest/1300/problem/C

// Memory Limit: 256 MB

// Time Limit: 1000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include <bits/stdc++.h>



using namespace std;



typedef long long ll;

const int maxn = 1e5 + 10;

int a[maxn], num[40];



int main(void)

{

	ios::sync_with_stdio(0);

	cin.tie(0), cout.tie(0);

	

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> a[i];

		int id = 0, tmp = a[i];

		while (tmp > 0) {

			if (tmp & 1) {

				++num[id];

			}

			++id;

			tmp >>= 1;

		}

	}

	int pos = -1;

	for (int i = 39; i >= 0; --i) {

		if (num[i] == 1) {

			pos = i;

			break;

		}

	}

	int ans = 0;

	if (pos != -1) {

		for (int i = 0; i < n; ++i) {

			if (a[i] & (1 << pos)) {

				ans = i;

			}

	    }

	}

	

	cout << a[ans] << " ";

	for (int i = 0; i < n; ++i) {

		if (i == ans) continue;

		cout << a[i] << " ";

	}

	cout << endl;

	

	return 0;

}