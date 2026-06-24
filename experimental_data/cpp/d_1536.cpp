#include <bits/stdc++.h>



#define int long long



using namespace std;



signed main(void)

{

	ios_base::sync_with_stdio(false);

	

	cin.tie(0);

	

	int q;

	

	cin >> q;

	

	while(q--)

	{

		int n;

		

		cin >> n;

		

		set <int> s;

		

		s.insert(-2e9);

		

		s.insert(2e9);

		

		vector <int> a(n);

		

		bool ans = true;

		

		for(int i=0;i<n;i++)

		{

			cin >> a[i];

		}

		

		auto it = s.insert(a[0]).first;

		

		for(int i=1;i<n;i++)

		{

			if( *prev(it) <= a[i] && *next(it) >= a[i] )

			{

				it = s.insert(a[i]).first;

			}

			else

			{

				ans = false;

				

				break;

			}

		}

		

		if( ans == false ) cout << "NO\n";

		

		else cout << "YES\n";

	}

	

	return 0;

}