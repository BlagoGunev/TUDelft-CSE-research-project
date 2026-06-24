#include <bits/stdc++.h>

using namespace std;



typedef long long ll;



constexpr int N = 3e5 + 10;

constexpr int inf = 0x3f3f3f3f;



void solve()

{	

    int n;

    cin >> n;



	string s, t;

	cin >> s >> t;



	vector<vector<int>> cnt(26, vector<int>(26));



	for (int i = 0; i < n; i++)

	{

		int l = s[i] - 'a';

		int r = t[n - i - 1] - 'a';



		if (l > r)

			swap(l, r);

		cnt[l][r]++;

	}



	int ans = 0;



	for (int i = 0; i < 26; i++)

	{

		ans += cnt[i][i] & 1;

		for (int j = i + 1; j < 26; j++)

		{

			if (cnt[i][j] & 1)

			{

				cout << "NO" << "\n";

				return;

			}

		}

	}



	if (ans > 1)

		cout << "NO" << "\n";

	else

		cout << "YES" << "\n";



}



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);





	int T;

	cin >> T;



	while (T--)

	    solve();



	return 0;

}