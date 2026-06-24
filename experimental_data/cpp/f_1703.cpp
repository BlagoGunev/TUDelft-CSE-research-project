#include <bits/stdc++.h>



using namespace std;



void fasterIO()

{

	ios::sync_with_stdio(0);

#ifndef DEBUG

	cin.tie(0);

#endif

}



int main()

{

 	fasterIO();

	

	int t, n;

	cin >> t;





	for(int j = 0; j < t; ++j)

	{

		cin >> n;



		vector<pair<int, int>>vec;

		int a;

		for(int i = 0; i < n; ++i)

		{

			cin >> a;

			if(a < i + 1) vec.push_back({a, i + 1});

		}

		long long ans = 0;

		for(int i = 1; i < vec.size(); ++i) 

		{

			int left = 0, right = i - 1;

			int curr = -1;

			while(left <= right) {

				const int middle = (left + right) / 2;

				if(vec[middle].second < vec[i].first) {

					curr = max(curr, middle);

					left = middle + 1;

				}

				else {

					right = middle - 1;

				}

			}

			

			ans += curr + 1;

		}

		



		cout << ans << '\n';

	}

	return 0;

}