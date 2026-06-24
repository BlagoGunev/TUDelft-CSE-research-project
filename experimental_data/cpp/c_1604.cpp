#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define P pair<int,int>
#define pll pair<long long,long long>
#define pp pair<P,int>
using namespace std;
template<typename T>void write(T x) {
    if(x<0) { putchar('-'); x=-x; }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], str[64];
    int l = SIZE, r = SIZE;
    int read(char *s) {
        while (r) {
            for (; l < r && buf[l] <= ' '; l++);
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        int cur = 0;
        while (r) {
            for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        s[cur] = '\0';
        return cur;
    }
    template<typename type>
    bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        if (flag) x = -x;
        return true;
    }
    template <typename type>
    type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        return flag ? -x : x;
    }
} using FastIO::read;
const int N=1e5+10,INF=0x3f3f3f3f;
int a[N];
int main() {
	int t;
	read(t);
	while (t--) {
		int n,ans=0; read(n);
		bool ok=true;
		for (int i=1; i<=n; i++) {
			read(a[i]);
		}
		while (n) {
			int p=0;
			for (int i=n; i>=1; i--) {
				if (a[i]%(i+1)) {
					p=i; break;
				}
			}
			if (!p) {
				ok=false;
				break;
			}
			while (p<=n) a[p]=a[p+1],++p;
			n-=1;
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}