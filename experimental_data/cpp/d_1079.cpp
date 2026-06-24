#include <iostream>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;

using Point = pair<double, double>;

Point line_intersection(double A1, double B1, double C1, double A2, double B2, double C2) {
return {
	(B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1),
 	(A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1)};
}

const Point INVALID{1000000001, 1000000001};
const double eps = 1e-6;

double dist(Point a, Point b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	int a, b;
	double c;
	Point A, B;
	cin >> a >> b >> c;
	cin >> A.first >> A.second >> B.first >> B.second;
	double ans = abs(A.first - B.first) + abs(A.second - B.second);
	if (a && b) {
		if (A.second > B.second) {
			swap(A, B);
		}
		if (A.first > B.first) {
			double t = (-c - a * A.first) / b;
			a = -a;
			c = -(a * A.first + b * t);
			B.first = A.first * 2 - B.first;
		}
		Point upper = line_intersection(a, b, c, 0, 1, -B.second);
		Point lower = line_intersection(a, b, c, 0, 1, -A.second);
		Point left = line_intersection(a, b, c, 1, 0, -A.first);
		Point right = line_intersection(a, b, c, 1, 0, -B.first);

		if (upper.first < A.first - eps || upper.first > B.first + eps) {
			upper = INVALID;
		}
		if (lower.first < A.first - eps || lower.first > B.first + eps) {
			lower = INVALID;
		}
		if (left.second < A.second - eps || left.second > B.second + eps) {
			left = INVALID;
		}
		if (right.second < A.second - eps || right.second > B.second + eps) {
			right = INVALID;
		}

		// cout << a << " " << b << " " << c << endl;
		// cout << A.first << " " << A.second << " " << B.first << " " << B.second << endl;
		// cout << (upper == INVALID) << " " << (lower == INVALID) << " " << (left == INVALID) << " " << (right == INVALID) << endl;

		if (left != INVALID && upper != INVALID) {
			ans = (left.second - A.second) + (B.first - upper.first) + dist(left, upper);
		} else if (right != INVALID && lower != INVALID) {
			ans = (lower.first - A.first) + (B.second - right.second) + dist(right, lower);
		} else if (left != INVALID && right != INVALID && left.second < right.second) {
			ans = (left.second - A.second) + (B.second - right.second) + dist(left, right);
		} else if (upper != INVALID && lower != INVALID && lower.first < upper.first) {
			ans = (lower.first - A.first) + (B.first - upper.first) + dist(lower, upper);
		}
	}
	cout << setprecision(10);
	cout << ans << endl;
}