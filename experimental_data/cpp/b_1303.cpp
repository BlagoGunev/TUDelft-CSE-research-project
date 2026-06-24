#include<bits/stdc++.h>

using namespace std;



#define int long long

#define pb push_back

#define F first

#define S second

#define endl "\n"

const int N=1e5+2 , inf=2e9;

void solve ()

{

	

}

int32_t main()

{

	ios_base::sync_with_stdio(0);

	cin.tie(NULL);

	cout.tie(NULL);

	

	int test;	cin >> test;

	while (test--)

	{

		int num , good , bad;

		cin >> num >> good >> bad;

		int l,ans;

		l=(num+1)/2 / good;

		if ((num+1)/2 % good == 0)	l--;

		ans=(num+1)/2 + l*bad;

		if (ans>=num)	cout << ans << endl;

		else cout << num << endl;

	}

	return 0;

}