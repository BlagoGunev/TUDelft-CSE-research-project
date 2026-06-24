// LUOGU_RID: 101835956
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline char getC() { //Don't use it in interactive problems!!!
	static char *p1, *p2, buf[1<<20];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<20, stdin), p1==p2?'\n':*p1++):*p1++;
}
inline char getc() {
	char c; while (isspace(c=getC()));
	return c;
}
inline void read(char *s) {
	char c; while (isspace(c=getC()));
	while (!isspace(c)) (*s++)=c, c=getC(); (*s++)='\0';
}
inline int read() {
	int f=1, r=0; char c=getC();
	while (!isdigit(c)) f^=c=='-', c=getC();
	while (isdigit(c)) r=r*10+c-48, c=getC();
	return f?r:-r;
}
#define mk make_pair
#define pii pair<int, int>
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e6+7, mod=998244353;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, K, fac[N], ifac[N];
inline int C(int n, int m) {
	if (m<0 || n<m) return 0;
	return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
inline void init_C(int n) {
	fac[0]=1;
	for (int i=1; i<=n; i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n], mod-2);
	for (int i=n; i; i--) ifac[i-1]=(ll)ifac[i]*i%mod;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), K=read();
	if (n==K) puts("1"), exit(0);
	init_C(n);
	int l=K==n, r=K, sum=!l, ans=sum;
	for (int i=1; i<=K; i++) {
		if (2*i>=n) {inc(ans, C(n-i-1, K-i)); continue;}
		sum=(2ll*sum+mod-C(i-1, r)+C(i-1, l-1))%mod;
		int L=K-i-min(n-2*i-1, K-i), R=K-i;
		while (l>L) inc(sum, C(i, --l));
		while (r<R) inc(sum, C(i, ++r));
		while (l<L) dec(sum, C(i, l++));
		while (r>R) dec(sum, C(i, r--));
		inc(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}