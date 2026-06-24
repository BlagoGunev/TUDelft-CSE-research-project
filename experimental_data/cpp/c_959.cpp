#include<complex>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <time.h>
#include <cstdio>
#include <numeric>
#define LL long long
#define rei(x) scanf("%d",&x)
#define reii(x,y) scanf("%d%d",&x,&y)
#define reiii(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define rel(x) scanf("%I64d",&x);

#define ref(x) scanf("%lf",&x)
#define rec(x) scanf("%c",&x)
#define res(x) scanf("%s",x)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define f(i, a, b) for(int i = a; i <= b; i++)
#define ms(Arr) memset(Arr,0,sizeof(Arr));
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
#define bit(a , b) (((a)>>(b))&1)
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
#define fout1 freopen("out1.txt","w",stdout)
#define ftest freopen("in.txt","w",stdout)
#define lson (id << 1)
#define rson (id << 1 | 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
using namespace std;
const int INF = 0x3f3f3f3f;
const LL mod = 1000000007;
const double e = 2.718281828459;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;




LL gcd(LL a, LL b)
{
	if (!b)return a;
	return gcd(b, a%b);
}

LL gcd1(int a, int b)
{
	if (!b)return a;
	return gcd(b, a%b);
}


LL pow_mod(LL a, LL b, LL c)
{
	LL ans = 1;
	a = a % c;
	while (b > 0)
	{
		if (b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	return ans;
}


int pow_int(int a, int b)
{
	int ans = 1;
	while (b > 0)
	{
		if (b % 2 == 1)
			ans = ans * a;
		b = b / 2;
		a = a * a;
	}
	return ans;
}

LL pow_llong(LL a, LL b)
{
	LL ans = 1;
	while (b > 0)
	{
		if (b % 2 == 1)
			ans = ans * a;
		b = b / 2;
		a = a * a;
	}
	return ans;
}

const int dx[9] = { 0, 1, 1, 1, 0,-1,-1,-1, 0 };
const int dy[9] = { 0, 1, 0,-1,-1,-1, 0, 1, 1 };

int Scan()
{
	int res = 0, flag = 0;
	char ch;
	if ((ch = getchar()) == '-')
	{
		flag = 1;
	}
	else if (ch >= '0' && ch <= '9')
	{
		res = ch - '0';
	}
	while ((ch = getchar()) >= '0' && ch <= '9')
	{
		res = res * 10 + (ch - '0');
	}
	return flag ? -res : res;
}

void Out(int a)
{
	if (a < 0)
	{
		putchar('-');
		a = -a;
	}
	if (a >= 10)
	{
		Out(a / 10);
	}
	putchar(a % 10 + '0');
}

LL jc_mod(LL a, LL b, LL mod)
{
	LL ans = 1;
	b = max(b, a - b);
	for (LL i = a; i > b; i--)
	{
		ans *= i;
		ans %= mod;
	}
	return ans;
}

double lg(double a)
{
	return (log(a) / log(10.0));
}

int lowbit(int x)
{
	return x & -x;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//long long：-9223372036854775808~9223372036854775807
//int：-2147483648~2147483647
//double：-1.7*10^-308~1.7*10^308，15~16位有效数字
//long double：-1.2*10^-4932~1.2*10^4932，18~19位有效数字
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




inline int read()
{
	int f = 1, x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x*f;
}






/*******************************************************
自定义结构体排序
struct Struct_Name
{
int variable;
bool operator <(const Struct_Name &other)const   //升序排序
{
return variable > other.variable;
}
};
*******************************************************/






//离散化///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//离散化///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//离散化///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAXNN 100010
void lisan(int *x, int n) {
	//首先c++调用一个数组直接打这个数组的类型就好了。
	int data[MAXNN];
	f(i, 1, n)data[i] = x[i];
	sort(data + 1, data + 1 + n);//排序是肯定要的。
	int o = unique(data + 1, data + 1 + n) - data - 1;//给data数组[1..n]去重，黑科技
	f(i, 1, n)x[i] = lower_bound(data + 1, data + 1 + o, x[i]) - data;//找到x[i]在data中的位置再赋值为这个位置，如果不-data就是返回这个值。
}
////////////////////////////////////////////////////end/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////end/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////end/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////三分框架 左闭右开////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////三分框架 左闭右开////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////三分框架 左闭右开////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calc(int M)
{
	return 1;
}
int sanfen(int L, int R)
{
	int M, RM;
	while (L + 1 < R)
	{
		M = (L + R) / 2;
		RM = (M + R) / 2;
		if (calc(M) < calc(RM)) //计算最小值,若为最大值则>  
			R = RM;
		else
			L = M;
	}
	return L;
}

int CaculateWeekDay(int y, int m, int d)
{
	if (m == 1 || m == 2) {
		m += 12;
		y--;
	}
	int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	return iWeek;
}

////////////////////////////////////////////////////e nd/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////end/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////end/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	int n;
	rei(n);
	if (n < 6)
		printf("-1\n");
	else
	{
		printf("1 2\n2 3\n2 4\n1 5\n1 6\n");
		for (int i = 6; i < n; i++)
			printf("1 %d\n", i + 1);
	}
	f(i, 2, n)
	{
		printf("1 %d\n", i);
	}
	return 0;
}