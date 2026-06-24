#include <stdio.h>

#include <ctype.h>

#include <algorithm>

/** \brief fast get integer

\return the integer from stdin.

\author Teng K. J.

*/

int fgi() {

	int result = 0, sgn = 0, ch;

	while (!isdigit(ch = getchar())) if (ch == '-') sgn ^= 1;

	do result = (result << 3) + (result << 1) + (ch - '0');

	while (isdigit(ch = getchar()));

	return sgn ? -result : result;

}

#define N 300000

int a[N];

int main(void) {

	int n;

	n = fgi();

	for (int i = 0; i < n; i++) {

		a[i] = fgi();

	}

	std::sort(&a[0], &a[n]);

	printf("%d", a[(n - 1) / 2]);

	return 0;

}