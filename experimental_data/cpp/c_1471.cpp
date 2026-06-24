#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 3e5 + 5;

inline int read(){
	int ans = 0, f = 1;
	char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') f = -1, c = getchar();
	while (isdigit(c)) ans = ans * 10 + c - '0', c = getchar();
	return ans * f;
}

int n, m, k[N], c[N], a[N];

int main(){
	int t;
	t = read();
	while (t -- ){
		LL ans = 0;
		n = read(); m = read();
		for (int i = 1; i <= n; i ++ ) k[i] = read();
		for (int i = 1; i <= m; i ++ ) c[i] = read();
		for (int i = 1; i <= n; i ++ ) a[i] = c[k[i]], ans += a[i];
		sort(a + 1, a + n + 1); sort(c + 1, c + m + 1);
		int i = n, j = 1;
		//for (int i = 1; i <= n; i ++ ) cout << a[i] << ' '; cout << endl;
		while (i >= 1 && j <= m){
			if (c[j] >= a[i]) break;
			ans = ans - a[i] + c[j];
			i --;
			j ++;
		}
		cout << ans << endl;
	}
	return 0;
}