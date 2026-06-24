#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

inline void R(int &a) {
	char ch=getchar(); a=0; bool f=false;
	for (; ch!='-' && (ch<'0' || ch>'9'); ch=getchar());
	if (ch == '-') {f = true;ch=getchar();}
	for (; ch>='0' && ch<='9'; ch=getchar()) a=a*10+ch-48;
	if (f) a=-a;
}
const int N = 2000005;
int n, m, a[N], opt[N];
struct BIT {
	int c[N], n, tlv;
	inline void pre(int _n) {
		n = _n;
		for (tlv=0; (1<<tlv)<n; ++tlv);
	}
	inline void A(int w, int x) {
		for (; w<=n; w+=w&-w)
			c[w] += x;
	}
	inline int Q(int w) {
		int sum = 0;
		for (; w; w-=w&-w)
			sum += c[w];
		return sum;
	}
	inline int find(int key) {
		int ans = 0, to;
		for (int i=tlv; i>=0; --i) {
			to = ans|(1 << i);
			if (to <= n && c[to] < key)
				ans = to, key -= c[to];
		}
		return ans + 1;
	}
} B;
int main() {
	R(n); R(m);
	B.pre(n); int op;
	for (int i=1; i<=m; ++i) R(a[i]);
	for (int i=1; i<=n; ++i) {
		R(op); opt[i] = op;
		if (op == -1) {
			int pos = upper_bound(a+1, a+m+1, B.Q(n)) - a;
			for (int j=pos-1; j; --j)
				B.A(B.find(a[j]), -1);
		}
		else {
			B.A(i, 1);
		}
	}
	int len = B.Q(n);
	if (len) {
		for (int i=1; i<=len; ++i)
			printf("%d", opt[B.find(i)]);
	} else
		puts("Poor stack!");
	return 0;
}