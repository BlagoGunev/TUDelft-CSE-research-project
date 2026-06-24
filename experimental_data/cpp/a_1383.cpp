#include <iostream>

#include <cstring>

#include <algorithm>

#include <string>

#include <vector>

#include <set>

#include <map>

using namespace std;

const int N = 20;

int g[N][N];

void slove() {

	int n;

	cin >> n;

	string s, t;

	cin >> s >> t;

	bool flag = true;

	int cnt = 0;

	memset(g, 0, sizeof(g));

	for(int i = 0; i < n; ++ i) {

		if(s[i] != t[i]) {

			++ cnt;

			if(t[i] < s[i]) {

				flag = false;

				break;

			} else {

				g[s[i] - 'a'][t[i] - 'a'] = 1;

			}

		}

	}

	if(!flag) {

		cout << "-1\n";

		return;

	}

	cnt = 0;

	for(int i = 0; i < N; ++ i) {

		for(int j = 0; j < N; ++ j) {

			if(!g[i][j]) continue;

			++ cnt;

			for(int k = j + 1; k < N; ++ k) {

				g[j][k] |= g[i][k];

			}

			break;

		}

	}

	cout << cnt << "\n";

	return;

}

int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	int t;

	cin >> t;

	while(t -- ) {

		slove();

	}

	return 0;

}