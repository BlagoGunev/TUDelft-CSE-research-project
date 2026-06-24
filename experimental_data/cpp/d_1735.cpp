#include<iostream>

#include<string>

#include<vector>

#include<stack>

#include<queue>

#include<unordered_map>

#include<unordered_set>

#include<math.h>

#include<map>

#include<set>

using namespace std;

char ops(char a, char b) {

	return '0' + 3 - a - b+'0'+'0';

}

int main() {

	cin.tie(0);

	cout.tie(0);

	ios::sync_with_stdio(0);

	int n, k;

	cin >> n; cin >> k;

	vector<string>st(n);

	unordered_map<int, int>mp;

	unordered_map<string, int>mp1;

	unordered_set<int>st2;

	string t(k, '0');

	vector<vector<int>>g(n, vector<int>(3, 0));

	int M = 1000, MM = M * M;

	int tem1, tem2, tem3;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < k; j++) {

			cin >> t[j];

		}

		mp[i] = 0;

		mp1[t] = i;

		st[i] = t;

	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < i; j++) {

			for (int m = 0; m < k; m++) {

				if (st[i][m] == st[j][m]) {

					t[m] = st[i][m];

				}

				else {

					t[m] = ops(st[i][m], st[j][m]);

				}

			}

			if (mp1.count(t)&&mp1[t]!=i&&mp1[t]!=j) {

				tem1 = max(max(i, j), mp1[t]); tem3 = min(min(i, j), mp1[t]); tem2 = i + j + mp1[t] - tem1 - tem3;

				st2.emplace(tem1*MM+tem2*M+tem3);

				mp[i]++;

			}

		}

		for (int j = i + 1; j < n; j++) {

			for (int m = 0; m < k; m++) {

				if (st[i][m] == st[j][m]) {

					t[m] = st[i][m];

				}

				else {

					t[m] = ops(st[i][m], st[j][m]);

				}

			}

			if (mp1.count(t) && mp1[t] != i && mp1[t] != j) {

				tem1 = max(max(i, j), mp1[t]); tem3 = min(min(i, j), mp1[t]); tem2 = i + j + mp1[t] - tem1 - tem3;

				mp[i]++;

				st2.emplace(tem1 * MM + tem2 * M + tem3);

			}

		}

		mp[i] = mp[i] / 2;

	}

	long long ans = 0;

	for (auto it : st2) {

		tem1 = it % M;

		tem2 = ((it - tem1)%MM) / M;

		tem3 = it / MM;

		ans += mp[tem1] + mp[tem2] + mp[tem3] - 3;

	}

	cout << ans/2  << endl;

	return 0; 

}