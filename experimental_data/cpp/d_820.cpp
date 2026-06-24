#include <bits/stdc++.h>
using namespace std;
#define M 2000010
#define LL long long
#define rep(i, x, y) for(int i = (x); i <= (y); i ++)
inline int read() {
	char ch = getchar(); int x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	} while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	} return x * f;
}
int b[M], a[M];
int main() {
	int n = read(); LL res = 0, ans = 0, ans1 = 0;
	int change = 0;
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n) {
		if(a[i] >= i) {
			res += a[i] - i;
			change --;
			b[a[i] - i] ++;
		} else {
			res += i - a[i];
			change ++;
			b[a[i] - i + n] ++;
		}
	} ans = res; 
	rep(i, 1, n - 1) {
		change += b[i - 1]; change += b[i - 1];
		res += abs(a[n - i + 1] - 1) - abs(a[n - i + 1] - n ) + 1;
		change -= 2; res += change;
		if(res < ans) ans = res, ans1 = i;
	} cout << ans << " " << ans1 << endl;
	return 0;
}