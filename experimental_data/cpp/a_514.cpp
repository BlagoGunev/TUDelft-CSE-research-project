#include <algorithm>

#include <iostream>

#include <cstring>

#include <cstdio>

#include <cmath>

using namespace std;



int main() {

	static char s[1000];

	scanf("%s", s);

	int n = strlen(s);

	for (int i = 0; i < n; ++ i) {

		int x = s[i] - '0';

		int t = 9 - x;

		if (i == 0) {

			if (x < t || !t) putchar(x + '0');

			else putchar(t + '0');

		}

		else {

			if (x < t) putchar(x + '0');

			else putchar(t + '0');

		}

	}

	return 0;

}