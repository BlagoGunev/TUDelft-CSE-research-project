#include <bits/stdc++.h>
#define rep(i , x , y) for(register int i = (x) , _## i = (y + 1) ; i < _## i ; i ++)
#define Rep(i , x , y) for(register int i = (x) , _## i = (y - 1) ; i > _## i ; i --)
using namespace std ;
#define int long long
using ll = long long ;
using pii = pair < int , int > ;
const static int _ = 1 << 20 ;
char fin[_] , * p1 = fin , * p2 = fin ;
inline char gc() { return (p1 == p2) && (p2 = (p1 = fin) + fread(fin , 1 , _ , stdin) , p1 == p2) ? EOF : * p1 ++ ; }
inline int read() {
	bool sign = 1 ; char c = 0 ; while(c < 48) ((c = gc()) == 45) && (sign = 0) ;
	int x = (c & 15) ; while((c = gc()) > 47) x = (x << 1) + (x << 3) + (c & 15) ;
	return sign ? x : -x ;
}
template < class T > void print(T x , char c = '\n') {
	(x == 0) && (putchar(48)) , (x < 0) && (putchar(45) , x = -x) ;
	static char _st[100] ; int _stp = 0 ;
	while(x) _st[++ _stp] = x % 10 ^ 48 , x /= 10 ;
	while(_stp) putchar(_st[_stp --]) ; putchar(c) ;
}
template < class T > void cmax(T & x , T y) { (x < y) && (x = y) ; }
template < class T > void cmin(T & x , T y) { (x > y) && (x = y) ; }

int n ;
const int N = 3e5 + 10 ;
signed main() {
#ifdef _WIN64
	freopen("testdata.in" , "r" , stdin) ;
#endif
	n = read() ; int cur = 0 ;
	int ans1 = 0 , ans2 = 0 ;
	rep(i , 1 , n) {
		cur ^= 1 ; int x = read() ;
		if(cur) {
			ans1 += (x >> 1) ;
			ans2 += x - (x >> 1) ;
		} else {
			ans2 += (x >> 1) ;
			ans1 += x - (x >> 1) ;
		}
	}
	print(min(ans1 , ans2)) ;
	return 0 ;
}