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



const int N = 1e6 + 10, INF = 1e18; 



int n, m; 

string s;



void solve()

{

	int t = 0;

	cin >> n >> m >> s;

	

	vector<int> row(n * m, 0);

	vector<int> col(n * m, 0);

	vector<int> ans(n * m, 0);

	

	for(int i = 0; i < n * m; i ++ )

	{

		if(s[i] == '1')

		{

			if(col[i % m] == 0) col[i % m] = 1, t ++ ;

		}

		ans[i] += t;

	}

	

	int last = -1;

	

	for(int i = 0; i < n * m; i ++ )

	{

		if(s[i] == '1') last = i;

		if(i < m) 

		{

			if(last != -1) row[i] = 1;

        }   

		else

		{

			if(i - last < m) row[i] = row[i - m] + 1;

			else row[i] = row[i - m];

        }   

        ans[i] += row[i];

	}

	

	for(int i = 0; i < n * m; i ++ ) cout << ans[i] << " ";

	cout << endl;

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