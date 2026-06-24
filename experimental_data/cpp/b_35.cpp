#include <iostream>

#include <cstdio>

#include <cmath>

#include <vector>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <string>

#include <algorithm>

#include <fstream>

#include <utility>

#include <ctime>

#define ft first

#define sc second

#define mp make_pair

#define forn(i, n) for (int i = 0; i < n; (i++))

#define two(k) (k << 1)

using namespace std;

ifstream fin("INPUT.txt");

ofstream fout("OUTPUT.txt");

typedef int INT;

//#define int long long

#define double long double

typedef pair<int, int> pii;

typedef pair<long long, long long> pll;

typedef long long ll;

typedef unsigned long long ull;





const int N = 40;

const long M = 10000000;

const long long INF = 1000000000000000000;

int mod = 1000000007;



int n, m, k, x, y;



string a[N][N];



INT main()

{

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);

	cout.precision(10);

	cin >> n >> m >> k;

	string s;

	while (k--)

	{

		cin >> s;

		if (s == "+1")

		{

			cin >> x >> y;

			x--, y--;

			cin >> s;

			for (int i = x; i<n; i++)

				for (int j = (i == x ? y : 0); j < m; j++)

					if (a[i][j].size() == 0)

					{

						a[i][j] = s;

						goto metk;

					}

					metk:

					{



					}

		}

		else

		{

			cin >> s;

			for (int i = 0; i<n; i++)

				for (int j = 0; j<m; j++)

					if (a[i][j] == s)

					{

						cout << i + 1 << ' ' << j + 1 << endl;

						a[i][j].clear();

						goto metk2;

					}

			cout << -1 << ' ' << -1 << endl;

		}



		metk2:

		{



		}

	}

//	cin >> n;

	return 0;

}