#include <iostream>

#include <algorithm>

using namespace std;

void Solve();

int main()

{

	Solve();

//	system("pause");

	return 0;

}

void Solve()

{

	int n, m, a[51], b[51], c[51], h = 0, count = 0,max=-1,x;

	cin >> n;

	for (int i = 0; i < n; i++)

		cin >> a[i];

	cin >> m;

	for (int i = 0; i < m; i++)

		cin >> b[i];

	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < m; j++)

		{

			if (b[j] % a[i] == 0)

			{

				x = b[j] / a[i];

			}

			if (max < x)

				max = x;

		}

	}

	for (int i = 0; i < m; i++)

	{

		for (int j = 0; j < n; j++)

		{

			if (b[i] % a[j] == 0 && b[i] / a[j] == max)

			{

				count++;

			}

		}

	}

	cout << count << "\n";

}