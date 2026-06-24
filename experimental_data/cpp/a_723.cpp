#include <iostream>

#include <cmath>

#include <cstdio>

#include <algorithm>

#include <string>

#include <stdlib.h>

#include <vector>

#include <map>

#include <queue>

#include <set>



#define ll long long

#define F first

#define S second

#define pb push_back

#define mp make_pair

#define INF 2e9

#define pii pair <int, int>



using namespace std;



int x, x2, x3, maxi = INF;



int main()

{

	//freopen("a.in", "r", stdin);

	//freopen("a.out", "w", stdout);	



	ios_base::sync_with_stdio(false);

	cin.tie(NULL);



	cin >> x >> x2 >> x3;



	for (int i = 1; i <= 100; i++)

	{

		int cur_s = abs(i - x) + abs(i - x2) + abs(i - x3);

		maxi = min(maxi, cur_s);

	}

	cout << maxi;

	return 0;

}