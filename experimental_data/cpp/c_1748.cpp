#include <bits/stdc++.h>



using namespace std;



#define sz(x) (int)(x).size()

const int INF = 1e9 + 7;

const int mod = 1e9+7;

const int mxN = 2e5 + 1;



int main()

{

	ios::sync_with_stdio(0); cin.tie(0);

	

	int test; cin >> test;

	while(test--)

	{

		int n; cin >> n;

		vector<int> a(n);

		vector<long long> pre(n);

		for (int& x : a)

			cin >> x;

		pre[0] = a[0];

		for (int i = 1; i < n; ++i)			

			pre[i] += pre[i-1] + a[i];



		vector<int> zeros; zeros.reserve(n);

		for (int i = 0; i < n; ++i)

			if (a[i] == 0)

				zeros.push_back(i);

		

		//for (auto x : zeros) 

		//	cout << x+1 << " ";

		//cout << "\n"; 



		//for (int i = 0; i < n; ++i)	

		//	cout << pre[i] << " ";

		//cout << "\n";

		int ans = 0;

		for (int i = 0; i < (zeros.empty() ? n : zeros[0]); ++i)

			ans += (pre[i] == 0);

		for (int i = 0; i < sz(zeros); ++i)

		{

			int last = (i+1 < sz(zeros) ? zeros[i+1] : n);

			map<long long,int> cnt;

			long long mxNum; int mxCount = 0;

			for (int j = zeros[i]; j < last; ++j)

			{

				auto it = cnt.find(pre[j]);

				if (it == cnt.end())

				{

					cnt[pre[j]] = 1;

					if (mxCount == 0)

					{

						mxNum = pre[j];

						mxCount = 1;

					}

				}

				else

				{

					++(it->second);

					if (mxCount < it->second)

					{

						mxNum = pre[j];

						mxCount = it->second;

					}

				}

			}

			//cout << "Max occuring between [" << zeros[i]+1 << ", " << last << "): " 

			//<< mxNum << "," << mxCount << "\n";

			ans += mxCount;

		}

		//cout << "ans: ";

		cout << ans << "\n";

		//cout <<"-------------------------------------\n";

		//cout <<"\n-------------------------------------\n";

	}	



}