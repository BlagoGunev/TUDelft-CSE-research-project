#include <bits/stdc++.h>
using namespace std;
inline void R(int &v) {
	static char ch;
	v = 0;
	bool p = 0;
	do {
		ch = getchar();
		if (ch == '-') p = 1;
	} while (!isdigit(ch));
	while (isdigit(ch)) {
		v = (v + (v << 2) << 1) + (ch^'0');
		ch = getchar();
	}
	if (p) v = -v;
}
inline void R(double &v) {
	static char ch;
	v = 0;
	bool p = 0;
	do {
		ch = getchar();
		if (ch == '-') p = 1;
	} while (!isdigit(ch));
	while (isdigit(ch)) {
		v = v * 10 + (ch^'0');
		ch = getchar();
	}
	if (p) v = -v;
}
int main() {
	int x, a, b;
	R(x), R(a), R(b);
	int n;
	R(n);
	int y;
	int ans = 0;
	for(int i =1; i<=n;++i) {
		R(y);
		if(y>a&&y<b) {
			++ans;
		}
	}
	cout<<ans;
	return 0;
}