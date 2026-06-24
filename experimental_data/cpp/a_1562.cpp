#include <iostream>

using namespace std;

#define int long long

signed main()

{

	ios_base :: sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	int t;

	cin >> t;

	while(t--)

	{

		int l,r;

		cin >> l >> r;

		if (r < l * 2) 

       		cout << r - l << "\n";

    	else 

        	cout << (r - 1) / 2 << "\n";

	}

}