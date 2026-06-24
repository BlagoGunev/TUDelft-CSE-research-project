#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <time.h>
#include <assert.h>
#include <cmath>
#include <stack>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll R, C;
	cin >> R >> C;
	ll k;
	cin >> k;
	if (2 * R*C%k) {
		puts("NO");
		return 0;
	}
	puts("YES");
	k = 2 * R*C / k;
	if (k == R*C) {
		puts("0 0");
		cout << R << " " << 0 << endl;
		cout << 0 << " " << C << endl;
		return 0;
	}
	if (k%R == 0) {
		puts("0 0");
		cout << R << " " << 0 << endl;
		cout << 0 << " " << k / R << endl;
		return 0;
	}
	puts("0 0");
	cout << R << " " << 1 << endl;
	cout << (R*C - k) % R << " " << 1 + k / R << endl;
	return 0;
}