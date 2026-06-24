#include <iostream>

#include <algorithm>



using namespace std;



int main()

{

	ios_base::sync_with_stdio(false);

	int n, b; 

	cin >> n >> b;

	int a[n], ans(b);

	for (int i(0); i < n; ++i)

		cin >> a[i];

	

	for (int i(0); i < n - 1; ++i)

		for (int j(i + 1); j < n; ++j)

			ans = max(ans, b % a[i] + b / a[i] * a[j]);

	

	cout << ans;

	return 0;

}