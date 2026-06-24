#include<stdio.h>
#include<cstring>
#include<algorithm>
#define re register int
using namespace std;
typedef long long ll;
int read() {
	re x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(const int x) {
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const int Size=100005;
const int INF=0x3f3f3f3f;
int n,q;
bool a[3][Size];
int main() {
	n=read();
	q=read();
	int ans=0;
	while(q--) {
		int x=read();
		int y=read();
		int pos=3-x;
		int sum=a[pos][y-1]+a[pos][y]+a[pos][y+1];
		ans+=a[x][y]?-sum:sum;
		a[x][y]^=1;
		if(ans) {
			puts("No");
		} else {
			puts("Yes");
		}
	}
	return 0;
}
/*
1
10 2 6
1 2 3 4 5 7
*/