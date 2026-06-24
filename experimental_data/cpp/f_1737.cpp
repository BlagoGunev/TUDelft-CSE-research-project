#import<bits/stdc++.h>

#define endl '\n'

using namespace std;



int m, t, b[18], check[18], cnt[5];

vector<int>v;

vector<vector<int>>a;



void initialize(int m)

{

	fill(b, b + m + 1, 0);

	fill(check, check + m + 1, 0);

	fill(cnt, cnt + 5, 0);

	v.clear();

	a.clear();

}

void insert1(int p1, int c1)

{

	v[p1] = c1;

	a.push_back(v);

}

void insert2(int p1, int p2, int c1, int c2)

{

	v[p1] = c1;

	v[p2] = c2;

	a.push_back(v);

}



void f1(int x)

{

	int n = a.size();

	for(int i = 0; i < n; i++)a.push_back(a[i]);

	for(int i = 0; i < n; i += 2)

	{

		a[i + 1][x] = 1;

		a[i + n][x] = 1;

	}

	swap(a[n / 2], a[n]);

}

void f2(int x)

{

	int n = a.size();

	for(int i = 0; i < n; i++)a.push_back(a[i]);

	for(int i = 1; i < n; i += 2)

	{

		a[i + 1][x] = 1;

		a[i + n][x] = 1;

	}

	a[n][x] = 1;

}

void f3(int x)

{

	int n = a.size();

	for(int i = 0; i < n; i++)a.push_back(a[i]);

	for(int i = 0; i < n; i += 2)

	{

		a[i + 1][x] = 1;

		a[i + n][x] = 1;

	}

	swap(a[n], a[2 * n - 1]);

}



int main()

{

	ios::sync_with_stdio(0);

	cin.tie(0);

	for(cin >> t; t--;)

	{

		cin >> m;

		for(int i = 1; i <= m; i++)

		{

			cin >> b[i];

			cnt[min(b[i], 4)]++;

		}

		if(cnt[4] || cnt[3] >= 2 || cnt[3] && cnt[2] || cnt[2] >= 3)

		{

			cout << -1 << endl;

			initialize(m);

			continue;

		}

		

		for(int i = 1; i <= m; i++)v.push_back(0);

		a.push_back(v);

		

		if(cnt[2])

		{

			int p1 = -1, p2 = -1;

			for(int i = 1; i <= m; i++)

			{

				if(b[i] == 2)

				{

					if(~p1)p2 = i - 1;

					else p1 = i - 1;

				}

			}

			if(~p2)

			{

				insert2(p1, p2, 2, 2);

				insert2(p1, p2, 0, 1);

				insert2(p1, p2, 2, 1);

				insert2(p1, p2, 0, 2);

				insert2(p1, p2, 1, 1);

				insert2(p1, p2, 2, 0);

				insert2(p1, p2, 1, 2);

				insert2(p1, p2, 1, 0);

				check[p1 + 1] = check[p2 + 1] = 1;

			}

			else

			{

				insert1(p1, 2);

				insert1(p1, 1);

				check[p1 + 1] = 1;

			}

			for(int i = 1; i <= m; i++)

			{

				if(check[i])continue;

				if(a.size() % 2)f2(i - 1);

				else f3(i - 1);

			}

		}

		else

		{

			if(cnt[3])

			{

				int p = 0;

				for(int i = 1; i <= m; i++)

				{

					if(b[i] == 3)p = i - 1;

				}

				insert1(p, 3);

				insert1(p, 1);

				insert1(p, 2);

				check[p + 1] = 1;

			}

			else

			{

				insert1(0, 1);

				check[1] = 1;

			}

			for(int i = 1; i <= m; i++)

			{

				if(!check[i])f1(i - 1);

			}

		}

		

		for(auto &v: a)

		{

			if(*max_element(v.begin(), v.end()))

			{

				for(auto &p: v)cout << p << ' ';

				cout << endl;

			}

		}

		initialize(m);

	}

}