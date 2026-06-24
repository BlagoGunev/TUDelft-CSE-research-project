#include <bits/stdc++.h>

using namespace std;

typedef long long itype;
typedef double ftype;

const ftype pi = acosl(-1); // 3.1415926535897932384626433832795l
const ftype radian = 180 / pi; // 57.295779513082320876798154814105l
const ftype eps = 1e-12l;
const int inf = 0x7f7f7f7f;
const long long infll = 0x7f7f7f7f7f7f7f7fll;
const ftype infl = 1e20l;

template <class T>
inline int sgn(const T & x)
{
	return (x > eps) - (x < -eps);
}

template <class T>
inline T non_negative(const T & x)
{
	if (x < 0)
		return 0;
	else
		return x;
}

template <class T>
inline T trigonometric(const T & x)
{
	if (x < -1)
		return -1;
	else if (x < 1)
		return x;
	else
		return 1;
}

template <class T>
inline T sqr(const T & x)
{
	return x * x;
}

#define Vector Point
#define Complex Point

template <class T, class U = ftype>
class Point
{
public:
	T x, y;

	Point(void) : x(0), y(0)
	{

	}

	Point(const T & x, const T & y) : x(x), y(y)
	{

	}

	template <class S>
	Point(const Point<S> & src) : x(src.x), y(src.y)
	{

	}

	Vector operator + (const Vector & rhs) const
	{
		return Vector(x + rhs.x, y + rhs.y);
	}

	Vector operator - (const Vector & rhs) const
	{
		return Vector(x - rhs.x, y - rhs.y);
	}

	U length(void) const
	{
		return sqrtl(x * x + y * y);
	}

	T length2(void) const
	{
		return x * x + y * y;
	}

	U distance(const Point & rhs) const
	{
		return (rhs - *this).length();
	}

	T distance2(const Point & rhs) const
	{
		return (rhs - *this).length2();
	}

	Vector operator * (const T & rhs) const
	{
		return Vector(x * rhs, y * rhs);
	}

	Vector operator / (const T & rhs) const
	{
		return Vector(x / rhs, y / rhs);
	}

	T operator * (const Vector & rhs) const
	{
		return x * rhs.y - y * rhs.x;
	}

	T operator & (const Vector & rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}

	T cross(const Point & lhs, const Point & rhs) const
	{
		return (lhs - *this) * (rhs - *this);
	}

	T dot(const Point & lhs, const Point & rhs) const
	{
		return (lhs - *this) & (rhs - *this);
	}

	U operator ^ (const Vector & rhs) const
	{
		U l1 = length(), l2 = rhs.length();
		if (sgn(l1) == 0 || sgn(l2) == 0)
			return 0;
		int s = sgn(*this * rhs);
		U a = acosl(trigonometric(U(*this & rhs) / l1 / l2));
		return s < 0 ? -a : a;
	}

	U angle(void) const
	{
		return atan2l(y, x);
	}

	U angle(const Point & rhs) const
	{
		return (rhs - *this).angle();
	}

	U angle(const Point & lhs, const Point & rhs) const
	{
		return (lhs - *this) ^ (rhs - *this);
	}

	bool operator == (const Point & rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator != (const Point & rhs) const
	{
		return x != rhs.x || y != rhs.y;
	}

	int quadrant(void) const
	{
		if (x == 0 && y == 0)
			return -1;
		else if (y < 0 || y == 0 && x > 0)
			return 0;
		else
			return 1;
	}

	bool operator < (const Vector & rhs) const
	{
		int lq = quadrant(), rq = rhs.quadrant();
		if (lq != rq)
			return lq < rq;
		else
		{
			int s = sgn(*this * rhs);
			return s != 0 ? s > 0 : length2() - rhs.length2() < 0;
		}
	}

	Vector unit(const T & n = 1) const
	{
		T l = abs(__gcd(x, y));
		return l == 0 ? Vector(n, 0) : Vector(x / l * n, y / l * n);
	}

	Vector normal(const bool & rht = false) const
	{
		return rht ? Vector(y, -x) : Vector(-y, x);
	}

	Vector moderate(void) const
	{
		return y > 0 || y == 0 && x >= 0 ? Vector(x, y) : Vector(-x, -y);
	}

	Complex conjugate(void) const
	{
		return Complex(x, -y);
	}

	Complex operator << (const Complex & rhs) const
	{
		return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
	}

	U distance_to_line(const Point & p, const Point & q) const
	{
		if (p == q)
			return distance(p);
		else
			return cross(p, q) / p.distance(q);
	}

	U distance_to_halfline(const Point & p, const Point & q) const
	{
		if (p == q)
			return distance(p);
		else if (p.dot(q, *this) < 0)
			return distance(p);
		else
			return fabsl(distance_to_line(p, q));
	}

	U distance_to_segment(const Point & p, const Point & q) const
	{
		if (p == q)
			return distance(p);
		else if (p.dot(q, *this) < 0)
			return distance(p);
		else if (q.dot(p, *this) < 0)
			return distance(q);
		else
			return fabsl(distance_to_line(p, q));
	}

	bool on_line(const Point & p, const Point & q) const
	{
		if (p == q)
			return *this == p;
		else
			return cross(p, q) == 0;
	}

	bool on_halfline(const Point & p, const Point & q, const bool & inclusive = true) const
	{
		if (*this == p)
			return inclusive;
		else
			return on_line(p, q) && p.dot(q, *this) >= 0;
	}

	bool on_segment(const Point & p, const Point & q, const bool & inclusive = true) const
	{
		if (*this == p || *this == q)
			return inclusive;
		else
			return on_line(p, q) && dot(p, q) <= 0;
	}

	bool in_triangle(const Point & u, const Point & v, const Point & w, const bool & inclusive = true) const
	{
		Point p[3] = {u, v, w};
		if (u.cross(v, w) < 0)
			reverse(p, p + 3);
		for (int i = 0; i < 3; i++)
		{
			if (on_segment(p[i], p[(i + 1) % 3]))
				return inclusive;
			else if (cross(p[i], p[(i + 1) % 3]) < 0)
				return false;
		}
		return true;
	}

	bool in_angle(const Point & o, const Point & p, const Point & q, const bool & inclusive = true) const
	{
		if (on_halfline(o, p) || on_halfline(o, q))
			return inclusive;
		else if (o.cross(p, q) == 0 && o.dot(p, q) > 0)
			return false;
		int vp = o.cross(p, *this), vq = o.cross(*this, q);
		if (o.cross(p, q) >= 0)
			return vp > 0 && vq > 0;
		else
			return vp > 0 || vq > 0;
	}
};

template <class T>
inline bool xycmp(const Point<T> & lhs, const Point<T> & rhs)
{
	if (lhs.x != rhs.x)
		return lhs.x < rhs.x;
	else
		return lhs.y < rhs.y;
}

template <class T>
inline bool yxcmp(const Point<T> & lhs, const Point<T> & rhs)
{
	if (lhs.y != rhs.y)
		return lhs.y < rhs.y;
	else
		return lhs.x < rhs.x;
}

template <class T>
inline bool azmcmp(const Vector<T> & lhs, const Vector<T> & rhs)
{
	int s = sgn(lhs * rhs);
	return s != 0 ? s > 0 : lhs.length2() - rhs.length2() < 0;
}


template <class T>
int line_line_intersection(const Point<T> & p1, const Point<T> & p2, const Point<T> & q1, const Point<T> & q2, Point<T> & ans)
{
	T pv1 = p1.cross(p2, q1), pv2 = p1.cross(p2, q2);
	if (sgn(pv1 - pv2) == 0)
	{
		if (sgn(pv1) == 0)
		{
			ans = p1;
			return 2;
		}
		else
			return 0;
	}
	else
	{
		ans = q1 * (-pv2 / (pv1 - pv2)) + q2 * (pv1 / (pv1 - pv2));
		return 1;
	}
}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << fixed << setprecision(20);
	
	int n, q;
	cin >> n;
	vector <Point<ftype>> P(n);
	map<Point<ftype>, int> id;
	for (int i = 0; i < n; i ++) cin >> P[i].x >> P[i].y, id[P[i]] = i;
	
	auto g = [&](auto cmp) -> Point<ftype> {
		int l = 0, r = n - 1, md;
		if (cmp(P[l], P[r])) {
			while (l + 1 < r) {
				md = (l + r) / 2;
				((cmp(P[md], P[l]) && cmp(P[md], P[md - 1])) ? l : r) = md;
			}
			return P[l];
		} else {
			while (l + 1 < r) {
				md = (l + r) / 2;
				((cmp(P[md], P[r]) && cmp(P[md], P[md + 1])) ? r : l) = md;
			}
			return P[r];
		}
	};
	
	auto f = [&](Point<ftype> A) -> vector <Point<ftype>> {
		if (id.count(A)) return {P[(id[A] + 1) % n], P[(id[A] - 1 + n) % n]};
		if (A.on_segment(P[0], P[n - 1])) return {P[0], P[n - 1]};
		return {g([&](Point<ftype> x, Point<ftype> y) { return sgn(A.cross(x, y)) > 0; }),
				g([&](Point<ftype> x, Point<ftype> y) { return sgn(A.cross(y, x)) > 0; })};
	};
	
	cin >> q;
	while (q --) {
		Point<ftype> A, B;
		cin >> A.x >> A.y >> B.x >> B.y;
		vector <Point<ftype>> v1 = f(A), v2 = f(B);
//		cerr << v1[0].x << " " << v1[0].y << " " << v1[1].x << " " << v1[1].y << endl;
//		cerr << v2[0].x << " " << v2[0].y << " " << v2[1].x << " " << v2[1].y << endl;
		int f = 0;
		if (sgn(A.cross(v1[0], B)) <= 0 || sgn(A.cross(v1[1], B)) >= 0) f = 1;
		if (sgn(B.cross(v2[0], A)) <= 0 || sgn(B.cross(v2[1], A)) >= 0) f = 1;
//		cerr << f << endl;
		if (f) cout << A.distance(B) << "\n";
		else {
			ftype ans = infl;
			Point<ftype> R;
			for (auto u : v1) {
				for (auto v : v2) {
					if (line_line_intersection(A, u, B, v, R) == 1) {
						ans = min(ans, A.distance(R) + B.distance(R));
					}
				}
			}
			if (sgn(ans - infl) == 0) cout << -1 << "\n";
			else cout << ans << "\n";
		}
	}
	return 0;
}