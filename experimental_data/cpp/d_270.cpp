// I'm the Topcoder
//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//C++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <deque>
#include <set>
using namespace std;

//*************************OUTPUT*************************
#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

//**************************CONSTANT***********************
#define INF 0x3f3f3f3f
#define eps 1e-8
#define PI acos(-1.)
#define PI2 asin (1.);
typedef long long LL;
//typedef __int64 LL;   //codeforces
typedef unsigned int ui;
typedef unsigned long long ui64;
#define MP make_pair
typedef vector<int> VI;
typedef pair<int, int> PII;
#define pb push_back
#define mp make_pair

//***************************SENTENCE************************
#define CL(a,b) memset (a, b, sizeof (a))
#define sqr(a,b) sqrt ((double)(a)*(a) + (double)(b)*(b))
#define sqr3(a,b,c) sqrt((double)(a)*(a) + (double)(b)*(b) + (double)(c)*(c))

//****************************FUNCTION************************
template <typename T> double DIS(T va, T vb) { return sqr(va.x - vb.x, va.y - vb.y); }
template <class T> inline T INTEGER_LEN(T v) { int len = 1; while (v /= 10) ++len; return len; }
template <typename T> inline T square(T va, T vb) { return va * va + vb * vb; }

// aply for the memory of the stack
//#pragma comment (linker, "/STACK:1024000000,1024000000")
//end

#define CY 5005

int ar[CY], c[CY];
int N, M;

void input(int n) {
	double x;
	for (int i = 0; i < n; ++i) {
		scanf("%d%lf", &ar[i], &x);
	}
}

int binary_search(int c[],int len,int v){
	int left=1,right=len,mid=left+(right-left)/2;
	while(left<=right){
		mid = (left + right) >> 1;
		if(v >= c[mid])   left=mid+1;
		else right=mid-1;
	}
	return left;
}

int LIS(int n){
	int i,j,len=1;       //j指的是i之前的最长递增子序列   len指的是当前的最长递增子序列
	c[0]=-1,c[1]=ar[0];       
	for(i=1;i<n;i++){
		j=binary_search(c,len,ar[i]);
		c[j]=ar[i];         //c[j]=a[i]指的是长度为j的子序列中的最大的元素的值
		if(j>len)   len=j;
	}
	return len;
}

void solve(int n) {
	int ans = LIS(n);
	printf("%d\n", n - ans);
}

int main(void) {
	while (2 == scanf("%d%d", &N, &M)) {
		input(N);
		solve(N);
	}
	return 0;
}