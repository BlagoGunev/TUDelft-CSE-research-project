#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0;
	T f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
inline void d_read(double &x) {
	x = 0.0;
	int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	if (c == '.'){
		double num = 1.0;
		c = getchar();
		for (; isdigit(c); c = getchar()) x = x + (num /= 10) * (c ^ 48);
	}
	x *= f;
}

template <typename T>
inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x, char c) {
	if (x < 0){
		putchar('-');
		x = -x;
	}
	w(x);
	putchar(c);
}
int a[100005];
vector <int> v;
int main(){
	int t;
	read(t);
	while(t --) {
		v.clear();
		int n, x, opt = 0;
		read(n);
		for (int i = 1; i <= n; i ++) {
			read(a[i]);
		}
		v.push_back(a[1]);
		for (int i = 2; i <= n - 1; i ++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) v.push_back(a[i]);
			else if (a[i] < a[i - 1] && a[i] < a[i + 1]) v.push_back(a[i]);
		}
		v.push_back(a[n]);
		int len = v.size();
		write(len, '\n');
		for (int i = 0; i < len - 1; i ++) {
			write(v[i], ' ');
		}
		write(v[len - 1], '\n');
	}
	return 0;
}