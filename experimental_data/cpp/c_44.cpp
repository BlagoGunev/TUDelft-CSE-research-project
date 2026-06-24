#include <bits/stdc++.h>

using namespace std;



int main()

{

	int n, m, a, b, i; cin >> n >> m;

	vector<int> c(n+1);

	while (m--)

	{

		cin >> a >> b;

		for (i=a; i<=b; i++) c[i]++;

	}

	for (i=1; i<=n; i++)

		if (c[i] != 1) 

			cout << i << " " << c[i], exit(0);

	cout << "OK";

}