#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define sq(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define _c1(x) cout<<(x)<<endl
#define _c2(x,y) cout<<(x)<<" "<<(y)<<endl
#define _c3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define _c4(x,n) do{for(int _=0;_<n;cout<<x[_++]<<" ");puts("");}while(0)
#define _c5(x,n,m) do{for(int __=0;__<n;__++)_c4(x[__],m);puts("");}while(0)
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned int U;
typedef pair<int, int> P;

const int N = 1000;
char s[N];
int Len(LL x) {
	int ret = 0;
	while (x) {
		ret ++;
		x /= 10;
	}
	return ret;
}

LL Pow10(int n) {
	LL ret = 1;
	for (int i = 0; i < n; i++) ret *= 10;
	return ret;
}

int main(){
	int t;
	scanf("%d\n", &t);
	while (t--) {
		scanf("IAO'%s\n", s);
		//_c1(s);
		int len = strlen(s);
		//_c1(len);
		LL pre = 1989, step = 1;
		for (int i = 0; i < len-1; i++) {
			step *= 10; pre += step;
		}
		//_c1(pre);

		LL x = 0;
		for (int i = 0; i < len; i++) {
			x = x * 10 + s[i] - '0';
		}

		LL ans;
		for (int i = 0; i < 10000; i++) {
			ans = i * Pow10(len) + x;
			if (ans >= pre) {
				printf("%I64d\n", ans); break;
			}
		}
	}

    return 0;
}