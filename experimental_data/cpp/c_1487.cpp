#include<bits/stdc++.h>
//#define int long long
#ifndef int
#define ll long long
#endif
using namespace std;
inline int read(void) {
	register int x=0;
	register short sgn=1;
	register char c=getchar();
	while(c<48||57<c) {
		if(c==45) sgn=0;
		c=getchar();
	}
	while(47<c&&c<58) {
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return sgn? x:-x;
}
char wrunit[19];
short wrcnt;
inline void write(int x) {
	wrcnt=0;
	if(x==0) {
		putchar('0');
		return ;
	}
	if(x<0) putchar('-'),x=-x;
	while(x!=0) {
		wrunit[++wrcnt]=x%10+48;
		x/=10;
	}
	for(; wrcnt>0; --wrcnt) putchar(wrunit[wrcnt]);
}
int n;
int ans[105][105];
inline void work() {
    n=read();
    if(n&1) {
        for(register int i=1; i<=n; ++i)
            for(register int u=1; u<=n; ++u)
                ans[i][u]=-1;
        for(register int i=1; i<=n/2; ++i) 
            for(register int u=1; u<=n-i; ++u) 
                ans[u][u+i]=1;
    } else {
        for(register int i=1; i<=n; ++i)
            for(register int u=1; u<=n; ++u)
                ans[i][u]=( i+u==n+1 ? 0 : -1 );
        for(register int i=1; i<=n/2; ++i)
            for(register int u=i+1; u<=n/2; ++u)
                ans[i][u]=1;
        for(register int i=1; i<=n/2; ++i)
            for(register int u=n-i+2; u<=n; ++u)
                ans[i][u]=1;
    }
    for(register int i=1; i<=n; ++i)
        for(register int u=i+1; u<=n; ++u)
            write(ans[i][u]),putchar(' ');
    puts("");
    return ;
}
signed main() {
	int T=read();
    while(T--) work();
	return 0;
}