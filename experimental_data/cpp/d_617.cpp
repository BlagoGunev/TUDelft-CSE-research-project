#include <iostream>

#include <stdio.h>

#include <cmath>

#include <math.h>

#include <string>

#include <algorithm>

#include <functional>

#include <stack>

#include <list>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <iomanip>

#include <unordered_set>

#include <unordered_map>

#include <bitset>

#include <regex>

#include <sstream>



#define PI 3.1415926535 

#define ll long long

#pragma comment(linker, "/STACK:16777216")



using namespace std;



const ll MAXN = 200005;

const ll INF = (ll)1e15 + 100;

const ll MOD = 1000000007;

string failMessage;



void fail()

{

	cout << failMessage;

	exit(0);

}



struct Point

{

	ll x, y;



	void read()

	{

		cin >> x >> y;

	}

};



void solve()

{

	Point a[3];

	for (ll i = 0; i < 3; i++)

		a[i].read();



	if (a[0].x == a[1].x && a[1].x == a[2].x || a[0].y == a[1].y && a[1].y == a[2].y)

	{

		cout << 1;

		return;

	}



	sort(a, a + 3, [](Point c, Point d) { return c.x < d.x || c.x == d.x && c.y < d.y; });

	if (a[0].x == a[1].x && (a[2].y <= a[0].y || a[2].y >= a[1].y) || 

		a[1].x == a[2].x && (a[0].y <= a[1].y || a[0].y >= a[2].y))

	{

		cout << 2;

		return;

	}



	sort(a, a + 3, [](Point c, Point d) { return c.y < d.y || c.y == d.y && c.x < d.x; });

	if (a[0].y == a[1].y && (a[2].x <= a[0].x || a[2].x >= a[1].x) ||

		a[1].y == a[2].y && (a[0].x <= a[1].x || a[0].x >= a[2].x))

	{

		cout << 2;

		return;

	}



	cout << 3;

}



int main()

{

	const string FILENAME = "digits";

#ifndef LOCAL

	//freopen((FILENAME + ".in").data(), "r", stdin);

	//freopen((FILENAME + ".out").data(), "w", stdout);

#endif // !LOCAL

	ios_base::sync_with_stdio(0);

	cout.precision(15);

	solve();

}