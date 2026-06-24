#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <deque>
#include <map>

using namespace std;

typedef long long ll;

pair<vector<ll>::iterator, int> findforward(vector<ll>& v, ll k)
{
	for (auto it = v.begin(); it != v.end(); it++)
		if (*it == (ll)k * 2 || k % 3 == 0 && *it == k / 3)
			return pair<vector<ll>::iterator, int>(it, it - v.begin());
	
	return pair<vector<ll>::iterator, int>(v.begin(), -1);
}

pair<vector<ll>::iterator, int> findbackward(vector<ll>& v, ll k)
{
	for (auto it = v.begin(); it != v.end(); it++)
		if (*it == (ll)k * 3 || k % 2 == 0 && *it == k / 2)
			return pair<vector<ll>::iterator, int>(it, it - v.begin());

	return pair<vector<ll>::iterator, int>(v.begin(), -1);
}

int main()
{
	int n;
	cin >> n;

	vector<ll> v(n);
	ll a;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	deque<ll> res;

	res.push_back(v.front());
	v[0] = -1;

	pair<vector<ll>::iterator, int> u;

	while (1) 
	{
		u = findforward(v, res.back());
		if (u.second == -1) break;
		res.push_back(v[u.second]);
		v.erase(u.first);
	}

	while (1) 
	{
		u = findbackward(v, res.front());
		if (u.second == -1) break;
		res.push_front(v[u.second]);
		v.erase(u.first);
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

	return 0;
}