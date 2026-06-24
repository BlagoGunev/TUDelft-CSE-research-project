#include <bits/stdc++.h> 



using std :: cin; 

using std :: cout; 

using std :: vector; 



constexpr int M = 1e6 + 5, mod = 1e9 + 7; 

constexpr int INF = 0x3f3f3f3f; 



typedef long long ll; 

typedef unsigned long long ull; 

typedef double db; 



inline int read() {

	int f = 1, s = 0; char ch = getchar(); 

	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar(); 

	while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();  

	return f * s; 

} 



namespace Solver {

	inline int add(int x, int y) {

		return (x += y) >= mod ? x - mod : x; 

	}

	inline int dec(int x, int y) {

		return (x -= y) < 0 ? x + mod : x; 

	}

	char str[M]; 

	int n, m, cnt[M], dp[M], sum[M], lst[M]; 

	inline void mian() {

		scanf("%s", str + 1), n = strlen(str + 1); m = 1; 

		for(int i = 1; i <= n; ++i) {

			if(str[i] == '0') cnt[m] ++; 

		    else cnt[++m] = 0; 

		}

		if(m == 1) return printf("%d\n", n), void(); 

	    sum[1] = dp[0] = 1; 

	    for(int i = 0; i <= n; ++i) lst[i] = 1; 

	    for(int i = 2; i < m; ++i) {

	        for(int j = 0; j <= cnt[i]; ++j) dp[i] = add(dp[i], dec(sum[i - 1], sum[lst[j] - 1])), lst[j] = i; 

	        sum[i] = add(sum[i - 1], dp[i]); 

		} 

		cout << (ll)sum[m - 1] * (cnt[1] + 1) % mod * (cnt[m] + 1) % mod; 

	}

} ; 



int main() 

{

	Solver :: mian(); 

	return 0; 

}