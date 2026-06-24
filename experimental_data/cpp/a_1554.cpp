#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x = 0, m = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') m = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * m;
}
inline void write(int x){
	if(x < 0){
		putchar('-');
		write(-x);
		return;
	}
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
signed main(){
	int t = read();
	while(t--){
		int n = read(), x = read(), ans = 0;
		for(int i = 2; i <= n; i++){
			int y = read();
			ans = max(ans, x * y);
			x = y;
		}
		write(ans);
		putchar('\n');
	}
}