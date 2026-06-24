#include <iostream>

#include <string>

#include <vector>

#include <map>

#include <queue>

#include <stack>

#include <deque> 

#include <set>

#include <sstream>

#include <cmath>

#include <algorithm>

#include <cstdlib>

#include <cstdio>

#include <ctime>

using namespace std;

#define INF 1000010000



struct st{

	int p;

	int x;

	int y;

};



double dist(pair<int, pair<int, int> > x1, pair<int, pair<int, int> > x2){

	return sqrt((x1.second.first - x2.second.first) * (x1.second.first - x2.second.first) + (x1.second.second - x2.second.second) * (x1.second.second - x2.second.second));

}



bool is_square(pair<int, pair<int, int> > x1, pair<int, pair<int, int> > x2, pair<int, pair<int, int> > x3, pair<int, pair<int, int> > x4){

	bool c[6];

	double t;

	t = dist(x1, x2) - dist(x2, x3);

	c[0] = (t > -0.000001 && t < 0.000001);

	t = dist(x2, x3) - dist(x3, x4);

	c[1] = (t > -0.000001 && t < 0.000001);

	t = dist(x3, x4) - dist(x1, x4);

	c[2] = (t > -0.000001 && t < 0.000001);

	t = dist(x1, x3) - dist(x2, x4);

	c[3] = (t > -0.000001 && t < 0.000001);

	return c[0] && c[1] && c[2] && c[3];

}



bool is_rectangle(pair<int, pair<int, int> > x1, pair<int, pair<int, int> > x2, pair<int, pair<int, int> > x3, pair<int, pair<int, int> > x4){

	bool c[6];

	double t;

	t = dist(x1, x2) - dist(x3, x4);

	c[0] = (t > -0.000001 && t < 0.000001);

	t = dist(x1, x4) - dist(x2, x3);

	c[1] = (t > -0.000001 && t < 0.000001);

	t = dist(x1, x3) - dist(x2, x4);

	c[2] = (t > -0.000001 && t < 0.000001);

	return c[0] && c[1] && c[2];

}



int main() {

	//freopen("input.txt","r",stdin);

	//freopen("output.txt","w",stdout);

	vector <pair<int, pair<int,int> > > a;

	for (int i = 0; i < 8; ++i){

		pair<int, pair<int, int> > q;

		q.first = i + 1;

		cin >> q.second.first >> q.second.second;

		a.push_back(q);

	}

	do{

		if (is_square(a[0], a[1], a[2], a[3]) && is_rectangle(a[4], a[5], a[6], a[7])){

			cout << "YES\n";

			cout << a[0].first << " " << a[1].first << " " << a[2].first << " " << a[3].first << "\n";

			cout << a[4].first << " " << a[5].first << " " << a[6].first << " " << a[7].first << "\n";

			return 0;

		}

	} while (next_permutation(a.begin(), a.end()));

	cout << "NO\n";

	return 0;

}