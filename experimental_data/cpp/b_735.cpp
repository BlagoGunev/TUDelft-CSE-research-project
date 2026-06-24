/*=================================
# Created time: 2016-11-28 00:28
# Filename: b.cpp
# Description: 
=================================*/
#define me AcrossTheSky&HalfSummer11  
#include <cstdio>  
#include <cmath>  
#include <ctime>  
#include <string>  
#include <cstring>  
#include <cstdlib>  
#include <iostream>  
#include <algorithm>  
  
#include <set> 
#include <stack>  
#include <queue>  
#include <vector>  
 
#define pb push_back 
#define lb lower_bound 
#define sqr(x) (x)*(x) 
#define lowbit(x) (x)&(-x)  
#define Abs(x) ((x) > 0 ? (x) : (-(x)))  
#define FOR(i,a,b) for((i)=(a);(i)<=(b);(i)++)  
#define FORP(i,a,b) for(int i=(a);i<=(b);i++)  
#define FORM(i,a,b) for(int i=(a);i>=(b);i--)  
#define ls(a,b) (((a)+(b)) << 1)  
#define rs(a,b) (((a)+(b)) >> 1)  
#define getlc(a) ch[(a)][0]  
#define getrc(a) ch[(a)][1]  
  
#define maxn 100005 
#define maxm 100005 
#define INF 1070000000  
using namespace std;  
typedef long long ll;  
typedef unsigned long long ull;  
  
template<class T> inline  
void read(T& num){  
    num = 0; bool f = true;char ch = getchar();  
    while(ch < '0' || ch > '9') { if(ch == '-') f = false;ch = getchar();}  
    while(ch >= '0' && ch <= '9') {num = num * 10 + ch - '0';ch = getchar();}  
    num = f ? num: -num;  
} 
int out[100]; 
template<class T> inline 
void write(T x,char ch){ 
	if (x==0) {putchar('0'); putchar(ch); return;} 
	if (x<0) {putchar('-'); x=-x;} 
	int num=0; 
	while (x){ out[num++]=(x%10); x=x/10;} 
	FORM(i,num-1,0) putchar(out[i]+'0'); putchar(ch); 
} 
/*==================split line==================*/ 
const double eps=1e-8; 
int a[maxn];
int n, n1, n2;
double ans = 0;
int main(){ 
	 read(n); read(n1); read(n2);
	 FORP(i, 1, n) read(a[i]);
	 sort(a + 1, a + 1 + n);
	 int n11 = min(n1, n2), n22 = max(n1, n2);
	 double tot = 0;
	 FORM(i, n, n - n11 + 1) tot += a[i];
	 ans = ans + tot / n11;
	 tot = 0;
	FORM(i, n - n11, n - n11 - n22 + 1) tot += a[i];
	ans = ans + tot / n22;
	printf("%.7lf",ans);
}