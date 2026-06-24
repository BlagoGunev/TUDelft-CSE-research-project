#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <set>

#include <map>

#include <deque>

#include <queue>

#include <stack>

#include <iomanip>

#include <cmath>



using namespace std;



int main() {

	int n, s;

	cin >> n >> s;

	int ans = 0;

	bool flag = false;

	for (int i = 0; i < n; i++)

	{

		int x, y;

		cin >> x >> y;

		if (x * 100 + y <= s * 100)

		{

			ans = max(ans, (100 - y) % 100);

			flag = true;

		}

	}

	if (flag)

		cout << ans;

	else

		cout << -1;

	return 0;                      

}