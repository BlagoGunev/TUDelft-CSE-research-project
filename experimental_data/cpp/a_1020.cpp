#include<cstdio>
#include<cstring>
#include<algorithm>
#define rd read()
using namespace std;

int n, h, m, a, b;

int read() {
	int X = 0 ,p = 1; char c = getchar();
	for(; c > '9' || c < '0'; c = getchar() ) if( c == '-' ) p = -1;
	for(; c >= '0' && c <= '9'; c = getchar() ) X = X * 10 + c - '0';
	return X * p;
}

int ab( int x, int y ) {
	return x > y ? x - y : y - x;
}

int work( int x, int y ) {
	if(x > y) swap(x, y);
	if( x < a && y < a) return 2 * a - x - y;
	if( x > b && y > b) return x + y - 2 * b;
	return y - x;
}

int main()
{
	n = rd; h = rd; a = rd; b = rd; m = rd;
	for( int i = 1; i <= m; ++i) {
		int ta, tb, fa, fb, ans;
		ta = rd; fa = rd;
		tb = rd; fb = rd;
		ans = ab( ta , tb );
		if( ta != tb ) ans += work( fa, fb );
		else ans += ab( fa, fb );
		printf("%d\n", ans);
	}
}