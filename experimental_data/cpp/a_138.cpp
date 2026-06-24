//#include<iostream>

//#include<cstring>

//#include<map>

//#include<deque>

#include<bits/stdc++.h>

#include<tr1/unordered_map>

using namespace std;

const long long MODA = 10000000000009ll;



inline void print(char pt) {

	printf("%c\n", pt);

}

inline void print(int pt) {

	printf("%d\n", pt);

}

inline void print(long long pt) {

	printf("%I64d\n", pt);

}

inline void print(double pt) {

	printf("%.20f\n", pt);

}

inline void print(char pt[]) {

	printf("%s\n", pt);

}



inline void scan(int &pt) {

	scanf("%d", &pt);

}

inline void scan(char &pt) {

	scanf("%c", &pt);

}

inline void scan(long long &pt) {

	scanf("%I64d", &pt);

}

inline void scan(double &pt) {

	scanf("%lf", &pt);

}

inline void scan(char pt[]) {

	scanf("%s", pt);

}



struct str {

	char val[1005];

	str() {

		memset(val, 0, sizeof(val));

	}

	friend int operator<(str a, str b) {

		return strcmp(a.val, b.val) < 0;

	}

};



//int gcd(int x, int y) {

//	return y ? gcd(y, x % y) : x;

//}

//int lcm(int x, int y) {

//	return x * (y / gcd(x, y));

//}

int gcd(int x, int y) {

	return y ? gcd(y, x % y) : x;

}

long long lcm(long long x, long long y) {

	return x * (y / gcd(x, y));

}



int bits[50];

void getbits() {

	for (int i = 0; i < 30; i++) {

		bits[i] = 1 << i;

	}

}



long long Q_pow(long long x, long long y) {

	long long res = 1;

	while (y) {

		if (y % 2 == 1) {

			res *= x;

			res %= MODA;

		}

		x = x * x;

		x %= MODA;

//		if(x<=1e-5){

//			return 0;

//		}

		y /= 2;

	}

	return res;

}



//返回d=gcd(a,b);和对应于等式ax+by=d中的x,y

long long extend_gcd(long long a, long long b, long long &x, long long &y) {

	if (a == 0 && b == 0)

		return -1; //无最大公约数

	if (b == 0) {

		x = 1;

		y = 0;

		return a;

	}

	long long d = extend_gcd(b, a % b, y, x);

	y -= a / b * x;

	return d;

}

//*********求逆元素*******************

//ax = 1(mod n)

long long mod_reverse(long long a, long long MOD) {

	long long x, y;

	long long d = extend_gcd(a, MOD, x, y);

	if (d == 1)

		return (x % MOD + MOD) % MOD;

	else

		return -1;

}



struct point {

	long long x, y;

	int index;

};

long long cross(point a1, point a2, point b1, point b2) {

	a2.x -= a1.x;

	a2.y -= a1.y;



	b2.x -= b1.x;

	b2.y -= b1.y;



	return 1ll * a2.x * b2.y - 1ll * b2.x * a2.y;

}



point C;

int point_cmp(point a, point b) {

//先按象限排序，再按极角排序，再按远近排序

	a.x -= C.x;

	a.y -= C.y;

	b.x -= C.x;

	b.y -= C.y;

//	if (a.y == 0 && b.y == 0 && a.x * b.x <= 0)

//		return a.x > b.x;

//	if (a.y == 0 && a.x >= 0 && b.y != 0)

//		return 1;

//	if (b.y == 0 && b.x >= 0 && a.y != 0)

//		return 0;

//	if (1ll * b.y * a.y <= 0)

//		return a.y > b.y;

	point one;

	one.y = one.x = 0;

	long long ansa = cross(one, a, one, b);

	if (ansa != 0)

		return ansa > 0;

	return abs(a.x - C.x) < abs(b.x - C.x);

}



struct pii {

	int a;

	int b;

	friend int operator<(pii a, pii b) {

		if (a.a != b.a)

			return a.a < b.a;

		return a.b < b.b;

	}

};



int n, k;

char stra[10008];

long long hasha[10];

int ifa[10];

int main() {

	scan(n);

	scan(k);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 4; j++) {

			scan(stra);

			hasha[j] = 0;

			for (int pos = strlen(stra) - 1, l = 0;; pos--) {

				hasha[j] *= 29;

				hasha[j] += stra[pos] - 'a';

				if (hasha[j] > MODA)

					hasha[j] %= MODA;

				if (stra[pos] == 'a' || stra[pos] == 'e' || stra[pos] == 'i'

						|| stra[pos] == 'o' || stra[pos] == 'u') {

					l++;

					if (l == k)

						break;

				}

			}

		}

		if (hasha[0] == hasha[1] && hasha[1] == hasha[2]

				&& hasha[2] == hasha[3]) {

			ifa[0] = 1;

		} else if (hasha[0] == hasha[1] && hasha[2] == hasha[3]) {

			ifa[1] = 1;

		} else if (hasha[0] == hasha[2] && hasha[1] == hasha[3]) {

			ifa[2] = 1;

		} else if (hasha[0] == hasha[3] && hasha[1] == hasha[2]) {

			ifa[3] = 1;

		} else {

			print("NO");

			return 0;

		}



		if (ifa[1] + ifa[2] + ifa[3] > 1) {

			print("NO");

			return 0;

		}

	}



	if (ifa[0] && !ifa[1] && !ifa[2] && !ifa[3]) {

		print("aaaa");

	} else if (ifa[1]) {

		print("aabb");

	} else if (ifa[2]) {

		print("abab");

	} else if (ifa[3]) {

		print("abba");

	} else {

		print("NO");

	}

	return 0;

}