#include <iostream>

#include <string>

#include <stdio.h>

#include <algorithm>

#include <cmath>

#include <math.h>

#include <set>

#include <vector>

#include <queue>

#include <map>

#include <stack>

#include <sstream>

#include <iomanip>

#include <cstdio>

#include <list>

#include <fstream>

#define ull unsigned long long

#define ll long long

#define ld long double

#define pi 3.1415926536

#define lp(i,n,a) for(ll i=a;i<=n;i++)

#define pl(i,n) for(ll i=n-1;i>=0;i--)

#define w while

#define re return

// Hard Training :D 

// hossam yehia //

using namespace std;

ll n, x, y, f, ff;

int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cin >> n >> x >> y;

	f = n - 1;

	ff = y - f;

	if (f + (ff*ff) >= x && ff>0) {

		lp(i, n, 2)

			cout << "1\n";

		cout << ff << "\n";

	}

	else

		cout << "-1\n";

	cin >> n;

	re 0;

}