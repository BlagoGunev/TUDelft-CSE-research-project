#include <bits/stdc++.h>



using namespace std;



set <int> ans;



int main()

{

	int n, s, k, a;

	cin >> n >> s;

	for(int i = 1; i <= n; i++) {

		cin >> k;

		for(int j = 0; j < k; j++) {

			cin >> a;

			if(a < s)

				ans.insert(i);

		}

	}

	cout << ans.size() << "\n";

	for(set<int>::iterator i = ans.begin(); i != ans.end(); i++)

		cout << *i << " ";

	return 0; 

}