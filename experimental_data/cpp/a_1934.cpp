#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &i : a)
			cin >> i;
		sort(a.begin(), a.end());
		cout << 2 * (a[n - 1] + a[n - 2]) - 2 * (a[0] + a[1]) << "\n";
	}
	return 0;
}