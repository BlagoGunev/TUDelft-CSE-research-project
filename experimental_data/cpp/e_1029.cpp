#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <functional>
#include <iterator>
#include <random>
#include <list>
#include <queue>
#include <cstdlib>
#include <string>
#include <memory.h>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <cmath>
#include <numeric>
#include <stack>
using namespace std;
#pragma region custom templates
#define break(x) {x;break;}
#define continue(x) {x;continue;}
#define _sort(x) sort(x.begin(), x.end())
#define r_sort(x) sort(x.rbegin(), x.rend())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MOD = 1000000007;
template<typename T>istream& operator>>(istream&i, vector<T>&v)
{
	for (auto&e : v)i >> e;
	return i;
}
template<typename T>ostream& operator<<(ostream&i, vector<T>&v)
{
	for (auto&e : v)i << e << " ";
	return i;
}
template<typename T1, typename T2>istream& operator>>(istream&i, vector<pair<T1, T2>>&v)
{
	for (auto&e : v)i >> e.first >> e.second;
	return i;
}
template<typename T1, typename T2>ostream& operator<<(ostream&i, vector<pair<T1, T2>>&v)
{
	for (auto&e : v)i << e.first << " " << e.second << endl;
	return i;
}
bool isVowel(char x)
{
	return x == 'a' || x == 'e' || x == 'o' || x == 'u' || x == 'i';
}
void _start()
{
#ifdef LOCAL_FREOPEN
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(0);
}
template<typename T>void _end(T out)
{
	cout << out;
#ifdef LOCAL_FREOPEN
	cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	exit(0);
}
#pragma endregion custom templates
vector<vector<int> > v(3e5);
int ans = 0;
int dfs(int n, int s=0, int prev=-1)
{
	int sm = 0;
	bool nizh = 0;
	for (auto&i : v[n])
	{
		if (i != prev)
		{
			int r = dfs(i, s+1, n);
			if (r == 2)
			{
				nizh = 1;
			}
			sm += r==1;
		}
	}
	if (s < 2)
		return 0;
	if (sm > 0)
	{
		ans++;
		return 2;
	}
	return !nizh;
}
int main()
{
	_start();
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	_end(ans);
}