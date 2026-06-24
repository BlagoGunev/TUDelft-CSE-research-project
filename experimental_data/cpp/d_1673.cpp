#include <set>

#include <map>

#include <cmath>

#include <queue>

#include <cstdio>

#include <vector>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <unordered_map>



#define x first

#define y second

#define endl '\n'

#define int long long



using namespace std;



typedef long long ll;

typedef pair<int, int> PII;



const int N = 1e6 + 10, INF = 1e18, mod = 1e9 + 7; 



int n, m; 

int b1, d1, n1, c2, d2, n2;



void solve()

{

	int res = 0;

	cin >> b1 >> d1 >> n1 >> c2 >> d2 >> n2;

	

	if(d2 % d1 || abs(b1 - c2) % d1 || b1 > c2 || b1 + (n1 - 1) * d1 < c2 + (n2 - 1) * d2) {cout << "0" << endl; return;}

	

	if(c2 - d2 < b1 || c2 + n2 * d2 > b1 + (n1 - 1) * d1) {cout << "-1" << endl; return;}

	

	for(int i = 1; i * i <= d2; i ++ )

	{

		if(d2 % i) continue;

		if((i * d1) / __gcd(i, d1) == d2) res = (res + d2 / i * d2 / i) % mod;

		if(i * i != d2)

		{

			int t = d2 / i;

			if(t * d1 / __gcd(t, d1) == d2) res = (res + d2 / t * d2 / t) % mod;

		}

	}

	cout << res << endl;

	return;

}



signed main()

{

	ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

	int t = 1;

	cin >> t;

	

	while(t -- ) solve();

	

	return 0;

}