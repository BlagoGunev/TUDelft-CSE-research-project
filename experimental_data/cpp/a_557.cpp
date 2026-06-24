#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <set>

#include <map>

#include <deque>

#include <queue>

#include <stack>

#include <iomanip>

#include <cmath>



using namespace std;



int main() {

	int n, min1, max1, min2, max2, min3, max3;

	cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;

	int a = min1, b = min2, c = min3;

	if (a + b + c < n)

		a = min(max1, n - b - c);

	if (a + b + c < n)

		b = min(max2, n - a - c);

	if (a + b + c < n)

		c = min(max3, n - a - b);

	cout << a << " " << b << " " << c;

	return 0;

}