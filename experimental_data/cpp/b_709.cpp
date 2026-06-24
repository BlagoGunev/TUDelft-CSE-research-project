/* Teng K. J. */

#include <cstdio>

#include <cctype>

#include <cstdlib>

#include <algorithm>

using namespace std;

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

int calculate_distance(int start, int left, int right) {

	if (left > start) return right - start;

	if (right < start) return start - left;

	if (start - left < right - start) return right - left + start - left;

	return right - left + right - start;

}

int main(void) {

	int n = fgi();

	int a = fgi();

	int left[2], right[2], x, y;

	if (n == 1) {

		putchar('0');

		return 0;

	}

	if (--n == 1) {

		x = fgi();

		y = fgi();

		printf("%d", min(abs(x - a), abs(y - a)));

		return 0;

	}

	x = fgi();

	y = fgi();

	if (x > y) {

		left[0] = right[1] = y;

		right[0] = left[1] = x;

	} else {

		left[0] = right[1] = x;

		right[0] = left[1] = y;

	}

	while (0 < --n) {

		x = fgi();

		if (x < left[1]) {

			left[1] = x;

			if (left[1] < left[0]) {

				swap(left[1], left[0]);

			}

		}

		if (x > right[1]) {

			right[1] = x;

			if (right[1] > right[0]) {

				swap(right[1], right[0]);

			}

		}

	}

	printf("%d", min(calculate_distance(a, left[1], right[0]), calculate_distance(a, left[0], right[1])));

	return 0;

}