#include<bits/stdc++.h>
#define int long long
//#define double long double
#define y1 yyyyyyyyyyyyyyyy1
using namespace std;
const int N = 5e5 + 5, M = 7001, inf = 2e15, mod = 1e18;
const int AQX = 9;
//mt19937 rnd(time(0) ^ clock());
//int random(int l, int r){
//	return rnd() % (r - l + 1) + l;
//}
//const double eps = 1e-8, pi = 3.1415926;
/*
		    	           _      _        _          
			       ____  _| |_   | |_  ___| |___ _ _  
			      |_ / || | ' \  | ' \/ -_) / -_) ' \ 
			      /__|\_, |_||_|_|_||_\___|_\___|_||_|
			          |__/    |___|                              
				       
*/

//int head[N], tot = 1;
//struct edge{
//	int t, f;
//	int d;
//	int next;
//}e[N << 1];
//void edge_add(int u, int v){
//	e[++tot].next = head[u];
//	e[tot].t = v;
//	e[tot].f = u;
//	head[u] = tot;
//}
//int qmr(int x, int a){
//	x %= mod;
//	int ret = 1, p = x;
//	while(a){
//		if(a & 1)ret = ret * p % mod;
//		p = p * p % mod;
//		a >>= 1;
//	}
//	return ret;
//}

int n, ans;
int gcd(int x, int y){
	if(!y)return x;
	return gcd(y, x % y);
}
void dfs(int x, int y, int p){
	if(!y)return;
	x %= y;
	ans += x * p;
//	cout << ans << " " << x << endl;
	dfs(x, y / 2, p * 2);
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;ans = 0;
		int x = gcd(a, b);
		a /= x;
		b /= x;
		if(1 << (int)(log2(b)) != b){
			printf("-1\n");
			continue;
		}
		dfs(a, b, x);
		printf("%lld\n", ans);
	}
	return 0;
}