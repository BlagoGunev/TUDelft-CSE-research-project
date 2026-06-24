#include <bits/stdc++.h>

#define fname ""

#define f first

#define s second

#define pb push_back

#define mp make_pair

const int MAXN = 1e5 + 1;

typedef long long ll;

using namespace std; 

int f(int num) {

        int ret = 0;

        int ten = 1;

        while (num) {

                int dig = num % 10;

                num /= 10;

                if (dig) {

                        ret += dig * ten;

                        ten *= 10;

                }

        }

        return ret;

}

 

int main() {

	#ifndef ONLINE_JUDGE

	freopen(fname".in", "r", stdin);

	freopen(fname".out", "w", stdout);

	#endif

	int a, b, c;

	cin >> a >> b;

	c = a + b;

	a = f(a);

	b = f(b);

	c = f(c);

	if (a + b == c) {

		cout << "YES";

	} else {

		cout << "NO";

	}

   	return 0;

}