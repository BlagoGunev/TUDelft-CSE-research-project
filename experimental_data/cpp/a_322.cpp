#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
using namespace std;

void _ad(int &p){ static int i = 0; p = i++; }
#define fi123(x) for_each (all(x),_ad)
#define outv(x) copy(all(x), ostream_iterator<int>(cout," "))

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int n, m;

int main( )
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cin >> n >> m;

	vector<pair<int,int> > res;
	if (n <= m)
	{
		for (int i = 0; i < m; i++)
		{
			res.push_back (mp(1,i + 1));
		}
		for (int i = 2; i <= n; i++)
		{
			res.push_back (mp(i,1));
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			res.push_back (mp(i + 1,1));
		}
		for (int i = 2; i <= m; i++)
		{
			res.push_back (mp(1,i));
		}
	}
	cout << res.size () << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].first << " " << res[i].second << endl;
	}


	return 0;
}