// Problem: G. Restore the Permutation

// Contest: Codeforces - Codeforces Round  #834 (Div. 3)

// URL: https://codeforces.com/problemset/problem/1759/G

// Memory Limit: 256 MB

// Time Limit: 1000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

int a[N], res[N];

int cnt[N];

//升序队列 小根堆

//priority_queue <int,vector<int>,greater<int> > q;

//降序队列	大根堆

//priority_queue <int,vector<int>,less<int> >q;





int lcm(int x, int y)

{

	return x / __gcd(x, y) * y;

}



void solve()

{

	int n;

	cin >> n;

	bool flag = true;

	for(int i = 1; i <= n; i ++)	cnt[i] = 0;

	for(int i = 1; i <= n / 2; i ++)

	{

		cin >> a[i]; cnt[a[i]] ++;	res[2 * i] = a[i];

		if(cnt[a[i]] > 1)	flag = false;

	}

	if(!flag)	cout << "-1\n";

	else

	{

		set<int> st;

		for(int i = 1; i <= n; i ++)	if(!cnt[i])	st.insert(i);

		for(int i = n - 1; i >= 1; i -= 2)

		{

			int j = i + 1;

			auto t = st.lower_bound(res[j]);

			t --;

			cnt[*t] ++;

			if(cnt[*t] > 1)

			{

				cout << "-1\n";

				return;

			}

			res[i] = *t;

			st.erase(*t);

		}

		for(int i = 1; i <= n / 2; i ++)

		{

			if(max(res[2*i-1], res[2*i]) != a[i])

			{

				cout << "-1\n";

				return;

			}

		}

		for(int i = 1; i <= n; i ++)	cout << res[i] << " ";

		cout << "\n";

	}

	

}

signed main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);cout.tie(0);

	int t;

	cin >> t;

	while( t -- )

    	solve();

    return 0;

}