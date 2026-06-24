/*=================================
# Created time: 2018-07-14 23:30
# Filename: c.cpp
# Description: 
=================================*/
#include <bits/stdc++.h> 
 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define lb lower_bound 
#define ub upper_bound 
#define sqr(x) (x)*(x) 
#define lowbit(x) (x)&(-x) 
#define pii pair<int, int> 
#define ls(a,b) (((a)+(b)) << 1) 
#define rs(a,b) (((a)+(b)) >> 1) 
#define fin(a) freopen(a,"r",stdin); 
#define fout(a) freopen(a,"w",stdout); 
#define FORP(i,a,b) for(int i=(a);i<=(b);i++) 
#define FORM(i,a,b) for(int i=(a);i>=(b);i--) 
 
#define maxn 100005 
#define maxm 100005 
#define MOD 1000000007 
#define INF 1070000000 
using namespace std; 
typedef long long ll; 
typedef unsigned long long ull; 
 
template<class T> inline   
void read(T& num){   
    num = 0; bool f = 1;char ch = getchar();   
    while(ch < '0' || ch > '9') { if(ch == '-') f = 0;ch = getchar();}   
    while(ch >= '0' && ch <= '9') {num = num * 10 + ch - '0';ch = getchar();}   
    num = f ? num: -num;   
}  
template<class T> inline 
void write(T x,char ch){ 
	int s[100]; 
	if (x==0) {putchar('0'); putchar(ch); return;} 
	if (x<0) {putchar('-'); x=-x;} int num=0; 
	while (x){ s[num++]=(x%10); x=x/10;} 
	FORM(i,num-1,0) putchar(s[i]+'0'); putchar(ch); 
} 
/*==================split line==================*/ 
const double pi = acos(-1); 
const double eps = 1e-8; 
 
int main(){ 
	ll n, m, ans = 0;
	read(n); read(m);
	ll dmax = n * (n - 1) / 2, dmin;
	if (n & 1) dmin = (n / 2 + 1) * (n / 2);
	else dmin = (n / 2) * (n / 2 - 1) / 2 + (n / 2 + 1) * (n / 2) / 2;
	FORP(i, 1, m) {
		int x, y; read(x); read(y);
		ans += x * n;
		if (y > 0) ans += y * dmax;
		else ans += y * dmin;
	}
	printf("%.7lf\n",(double) ans / (double) n);
}