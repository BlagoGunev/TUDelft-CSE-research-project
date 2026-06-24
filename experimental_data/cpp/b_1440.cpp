#include <bits/stdc++.h>
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
inline int read();
inline long long readl();
inline void write(int x,int ch);
inline void writel(ll x,int ch);
const int maxn=1e6+10;
int a[maxn];

signed main() {
    int n,c1,c2,h;
	int t=read();
	while(t--) {
        int n=read(),k=read();
        for(int i=1;i<=n*k;i++) a[i]=read();
        ll sum=0;
        if(n&1) {
            int x=n-n/2;
            int p=k*n;
            while(k--) {
                sum+=a[p-x+1];
                p-=x;
            }
        } else {
            int x=n-n/2+1;;
            int p=k*n;
            while(k--) {
                sum+=a[p-x+1];
                p-=x;
            }
        }
        writel(sum,1);
	}

}
inline void writel(long long x,int ch) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) {
		writel(x/10,0);
	}
	putchar(x%10+'0');
	if(ch)
		printf("\n");
	return;
}
inline void write(int x,int ch) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) {
		write(x/10,0);
	}
	putchar(x%10+'0');
	if(ch)
		printf("\n");
	return;
}
inline long long readl() {
    long long x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0') {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0') {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}