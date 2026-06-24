#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;



#define int long long

#define pll pair<long long,long long>

#define vvi vector<vector<int>>



#define in(x) long long x;cin>>x

#define pb push_back

#define F first

#define S second

#define endl "\n"



#define test() int t;cin>>t;while(t--)

#define KStest() int t,t1;cin>>t;t1=t;while(t--)

#define KScout cout<<"Case #"<<t1-t<<": "

#define deb(x) cout<<#x<<" "<<x<<endl;

#define setbits __builtin_popcountll



const long long mod = 1e9 + 7;

const int MAX = INT_MAX;

const long long inf = 1e18;

const double pi = 3.14159265358979323846;



int dirX[] = {1, -1, 0, 0};

int dirY[] = {0, 0, 1, -1};



using namespace std;

void print_bool(bool zeman_modnar)

{

	if (zeman_modnar)

		cout << "Yes" << endl;

	else

		cout << "No" << endl;

}

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//order_of_key   ==> number of elements whose value is less than the given element

//find_by_order ==> kth element in the set (counting from 0)



int32_t main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif



	test()

	{

		in(c);

		vector<string> v(2);

		for (int i = 0; i < 2; i++) {

			cin >> v[i];

			v[i] = '.' + v[i];

		}

		c++;



		int l = inf, r = -inf;



		for (int i = 0; i < 2; i++)

		{

			for (int j = 0; j < c; j++)

			{

				if (v[i][j] == '*') {

					l = min(l, j);

					r = max(r, j);

				}

			}

		}



		// cout << v[0] << endl << v[1] << endl;



		// cout << l << " " << r << endl;



		vvi dp(2, vector<int>(c + 1, inf));



		for (int i = 0; i < 2; i++)

		{

			if (v[i][l] == '*')

			{

				if (v[(i + 1) % 2][l] == '.')

					dp[i][l] = 0;

				else

					dp[i][l] = 1;

			}

			else

			{

				dp[i][l] = 1;

			}

		}

		for (int j = l + 1; j <= r; j++)

		{

			for (int curr = 0; curr <= 1; curr++)

			{

				for (int prev = 0; prev <= 1; prev++)

				{

					int moves = dp[prev][j - 1] + 1;

					if (curr != prev)

						moves++;

					else

					{

						if (v[(curr + 1) % 2][j] == '*')

							moves++;

					}

					dp[curr][j] = min(dp[curr][j], moves);

				}

			}

		}



		// for (int i = 0; i < 2; i++)

		// {

		// 	for (int j = 0; j < c; j++)

		// 	{

		// 		if (dp[i][j] == inf)

		// 			cout << "- ";

		// 		else

		// 			cout << dp[i][j] << " ";

		// 	}

		// 	cout << endl;

		// }

		cout << min(dp[0][r], dp[1][r]) << endl;

	}



	return 0;

}