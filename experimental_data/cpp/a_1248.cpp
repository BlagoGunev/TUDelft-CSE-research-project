#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define int ll
using namespace std;
int T, n, m;

inline int read() {
	int red = 0, f_f = 1; char ch = getchar();
	while(ch>'9'||ch<'0') {if(ch == '-') f_f = -1; ch = getchar();}
	while(ch>='0'&&ch<='9') red = red * 10+ch-'0', ch = getchar();
	return red * f_f;
}

signed main()
{
	T = read();
	while(T--) {
		int no=0, nj=0, mo=0, mj=0;
		n = read();
		for(int i = 1; i <= n; i++) {
			int a = read();
			no += !(a&1), nj += (a&1);
		}
		m = read();
		for(int i = 1; i <= m; i++) {
			int a = read();
			mo += !(a&1), mj += (a&1);
		}
		printf("%lld\n", mo*no+mj*nj);
	}
	return 0;
}