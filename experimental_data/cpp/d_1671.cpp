//author: towrist

#include <iostream>

#include <iomanip>

#include <vector>

#include <functional>

#include <cmath>

#include <algorithm>

#include <set>

#include <utility>

#include <queue>

#include <map>

#include <assert.h>

#include <stack>

#include <climits>

#include <string>

#include <ctime>

#include <chrono>

#include <random>

#define int long long int

using namespace std;



//only need to worry about 1 and x placement, by construction



const int INF = 1e9;



void solve()

{

	int n, x;

	cin >> n >> x;

	vector<int> a(n);



	int mn = INF, mx = 0;



	for (int z = 0; z < n; z++)

	{

		cin >> a[z];

		mn = min(mn, a[z]);

		mx = max(mx, a[z]);

	}



	int base = 0;

	for (int z = 1; z < n; z++) base += abs(a[z] - a[z - 1]);

	int add = INF;



	auto place = [&](int r)->int

	{

		int res = INF;

		res = min(res, abs(a[0] - r));

		res = min(res, abs(a[n - 1] - r));

		for (int z = 0; z < n - 1; z++)

		{

			res = min(res, abs(a[z] - r) + abs(a[z + 1] - r)-abs(a[z]-a[z+1]));

		}

		return res;

	};



	auto place2 = [&](int A, int B)->int

	{

		int res = INF;

		int sex = abs(A - B);

		res = min(res, abs(a[0] - B) + sex);

		for (int z = 0; z < n - 1; z++)

		{

			res = min(res, abs(a[z] - A) + sex + abs(a[z + 1] - B)-abs(a[z]-a[z+1]));

		}

		return res;

	};



	if (mn > 1 && mx < x)

	{

		add = min(add, place2(1, x));

		add = min(add, place2(x, 1));

		vector<int> pos1, posX;

		pos1.push_back(abs(a[0] - 1));

		for (int z = 0; z < n - 1; z++)

		{

			pos1.push_back(abs(a[z] - 1) + abs(a[z + 1] - 1)-abs(a[z]-a[z+1]));

		}

		pos1.push_back(abs(a[n - 1] - 1));





		posX.push_back(abs(a[0] - x));

		for (int z = 0; z < n - 1; z++)

		{

			posX.push_back(abs(a[z] - x) + abs(a[z + 1] - x)-abs(a[z]-a[z+1]));

		}

		posX.push_back(abs(a[n - 1] - x));



		vector<int> prefX((int)posX.size()), suffX((int)posX.size());

		prefX[0] = posX[0];

		for (int z = 1; z < (int)posX.size(); z++)

		{

			prefX[z] = min(prefX[z - 1], posX[z]);

		}



		suffX[(int)suffX.size() - 1] = posX.back();

		for (int z = (int)suffX.size() - 2; z >= 0; z--)

		{

			suffX[z] = min(suffX[z + 1], posX[z]);

		}



		add = min(add, pos1[0] + suffX[1]);

		add = min(add, pos1.back() + prefX[(int)prefX.size() - 1]);

		for (int z = 1; z < (int)pos1.size() - 1; z++)

		{

			add = min(add, pos1[z] + min(prefX[z - 1], suffX[z + 1]));

		}

	}

	else if (mn == 1 && mx >= x)

	{

		add = 0;

	}

	else if (mn > 1)

	{

		add = place(1);

	}

	else if (mx < x)

	{

		add = place(x);

	}



	cout << base + add << '\n';

	return;

}



signed main()

{

	ios::sync_with_stdio(0);

	cin.tie(NULL); cout.tie(NULL);

	int t;

	cin >> t;

	//t=1;

	//cout<<'\n';

	while (t--)

	{

		solve();

	}

	return 0;

}