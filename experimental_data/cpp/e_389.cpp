#include<stdio.h>

#include<algorithm>

#include<vector>

using namespace std;



int main()

{

	int n, a = 0, b = 0;

	scanf("%d", &n);

	vector<int> v;

	for (int i = 0, s; i < n; i++)

	{

		scanf("%d", &s);

		for (int j = 0, c; j < s; j++)

		{

			scanf("%d", &c);

			if (!(s & 1) || j * 2 != s - 1)

				(j < (s + 1) / 2 ? a : b) += c;

			else

				v.push_back(c);

		}

	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < v.size(); i++)

		(i & 1 ? b : a) += v[i];

	printf("%d %d\n", a, b);

}