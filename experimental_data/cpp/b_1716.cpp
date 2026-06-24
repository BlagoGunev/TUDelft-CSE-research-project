// Author : RAJAT SHAHI (@blood_of_dragons)

#include <bits/stdc++.h>

using namespace std;



#ifndef ONLINE_JUDGE

#include"/Users/rajat.shahi/Desktop/CPP/debug.h"

#endif

#ifdef ONLINE_JUDGE

#define debug(...) 42

#endif



#define endl '\n'	//remove for interactive problems 

const int mod = 1e9 + 7;	// 998244353;

#define rep(i,a,b) for(auto i=a;i<=b;i++)

#define per(i,a,b) for(auto i=a;i>=b;i--)

using ll = long long;

using vll = vector<long long>;

const int MAXN = 2e5 + 5;

const int inf = 1001001001;

const long long INF = 1001001001001001001ll;







int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);



	int _t;

	cin >> _t;



	while (_t--)

	{

		int n;

		cin >> n;



		vector<int> v(n);

		iota(v.begin(), v.end(), 1);



		debug(v);



		cout << n << endl;



		for (auto i = 0; i < (n - 1); i++)

		{

			for (auto j = 0; j < n; j++)

			{

				cout << v[j] << " " ;

			}



			swap(v[i], v[i + 1]);

			cout << endl;

		}



		for (auto i : v) cout << i << " ";

		cout << endl;

	}





	return 0;

}