#include<bits/stdc++.h>

using namespace std;



bool check(char c, bool& r, bool& g, bool& b) {

	switch (c)

	{

	case 'r':r = 1; return 1;

	case 'g':g = 1; return 1;

	case 'b':b = 1; return 1;

	case 'R':return r;

	case 'G':return g;

	case 'B':return b;

	}

}



int main()

{

	char rgb[6];

	int t;

	cin >> t;

	while (t--) {

		bool r = 0, g = 0, b = 0, flag = 1;

		for (int i = 0; i < 6; i++) {

			cin >> rgb[i];

			if (flag)

				flag = check(rgb[i], r, g, b);

		}

		cout << (flag ? "YES\n" : "NO\n");

	}

}