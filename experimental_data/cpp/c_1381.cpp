#include<bits/stdc++.h>

#define all(x) begin(x), end(x)

using namespace std;



int main() {

	cin.tie(0)->sync_with_stdio(0);

	int T;

	cin >> T;

	while(T--) {

		int n, x, y;

		cin >> n >> x >> y;

		vector<vector<int>> pos(n + 1);

		vector<int> a(n), out(n, -1), ord(n + 1), L;

		for(int i = 0; i < n; i++) {

			cin >> a[i];

			a[i]--;

			pos[a[i]].push_back(i);

		}

		

		

		int extra = 0;

		while(pos[extra].size())

			extra++;

		

		int CAP = (n - x) / 2;

		for(int t = 0; t < 2; t++) {

			for(int i = 0; i <= n; i++) {

				while(pos[i].size() && x && (t || pos[i].size() > CAP)) {

					out[pos[i].back()] = i;

					pos[i].pop_back();

					x--;

				}

			}

		}

		

		iota(all(ord), 0);

		sort(all(ord), [&](int i, int j) {

			return pos[i].size() > pos[j].size();

		});

		for(auto i : ord) {

			for(int j = pos[i].size(); j--;)

				L.push_back(i);

		}

		int shift = pos[ord[0]].size();

		for(int i = 0; i < L.size(); i++) {

			int j = (i + shift) % L.size();

			out[pos[L[i]].back()] = L[i] == L[j] ? extra : L[j];

			pos[L[i]].pop_back();

		}

		

		int Y = n - max(2*shift - (int)L.size(), 0);

		for(int i = 0; i < n; i++) {

			if(Y > y && out[i] != extra && out[i] != a[i]) {

				out[i] = extra;

				Y--;

			}

		}

		if(Y < y) cout << "NO\n";

		else {

			cout << "YES\n";

			for(auto i : out) cout << 1 + i << " "; cout << '\n';

		}

	};

	

}