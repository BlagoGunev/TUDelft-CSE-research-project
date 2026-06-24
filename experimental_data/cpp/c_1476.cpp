#include<bits/stdc++.h>
#define LL long long
#define MAXN 1001000
using namespace std;
template<typename T> void Read(T &cn)
{
	char c; int sig = 1;
	while(!isdigit(c = getchar())) if(c == '-') sig = 0;
	if(sig) {cn = c-48; while(isdigit(c = getchar())) cn = cn*10+c-48; }
	else    {cn = 48-c; while(isdigit(c = getchar())) cn = cn*10+48-c; }
}
template<typename T> void Write(T cn)
{
	int wei = 0; T cm = 0; int cx = cn%10; cn/=10;
	if(cn < 0 || cx < 0) {putchar('-'); cn = 0-cn; cx = 0-cx; }
	while(cn)cm = cm*10+cn%10,cn/=10,wei++;
	while(wei--)putchar(cm%10+48),cm/=10;
	putchar(cx+48);
}
template<typename T> void WriteL(T cn) {Write(cn); puts(""); }
template<typename T> void WriteS(T cn) {Write(cn); putchar(' '); }
template<typename T> void Max(T &cn, T cm) {cn = cn < cm ? cm : cn; }
template<typename T> void Min(T &cn, T cm) {cn = cn < cm ? cn : cm; }
int t, n;
LL a[MAXN+1], b[MAXN+1], c[MAXN+1];
LL f[MAXN+1];
void zuo()
{
	Read(n);
	for(int i = 1;i<=n;i++) Read(c[i]);
	for(int i = 1;i<=n;i++) Read(a[i]);
	for(int i = 1;i<=n;i++) Read(b[i]);
	f[n] = c[n]-1+2; LL ans = 0;
	for(int i = n-1;i>=1;i--)
	{
		Max(ans, f[i+1]+abs(a[i+1]-b[i+1]));
		if(a[i+1] == b[i+1]) f[i] = c[i]-1+2;
		else f[i] = (c[i]-1-abs(a[i+1]-b[i+1])+2) + max(abs(a[i+1]-b[i+1]), f[i+1]);
//		printf("f[%d] = %lld ans = %lld %lld %lld\n",i,f[i],ans,(c[i]-1-abs(a[i+1]-b[i+1])+2) , max(abs(a[i+1]-b[i+1]), f[i+1]));
	}
	WriteL(ans);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	Read(t); while(t--) zuo();
	return 0;
}