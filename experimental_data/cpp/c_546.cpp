#include <iostream>

#include <queue>

using namespace std;

queue <int> q1;

queue <int> q2;

int n, o = 0, m, i, k, a;

int main()

{

	cin >> n >> m;

	for (i = 1; i <= m; i++)

	{

		cin >> a;

		q1.push(a);

	}

	cin >> k;

	for (i = 1; i <= k; i++)

	{

		cin >> a;

		q2.push(a);

	}

	while (q1.size() > 0 && q2.size() > 0)

	{

		if (q1.front() > q2.front())

		{

			q1.push(q2.front());

			q1.push(q1.front());

			q1.pop(); 

			q2.pop();

			o++;

		}

		else

		{

			q2.push(q1.front());

			q2.push(q2.front());

			q1.pop();

			q2.pop();

			o++;

		}

		if (o >= 10001)

		{

			cout << -1 << endl;

			return 0;

		}

	}

	cout << o << " ";

	if (q1.size() > 0) cout << 1 << endl;

	else cout << 2 << endl;

//	system("PAUSE");

	return 0;

}