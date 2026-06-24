#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n, m;
int L, R;

int calc(int a, int b)
{
	return a*a + b*b - a*b;
}

bool check(int x, int i, int p)
{
	return n*(2*x-i) - p*(x+i) - x*(2*x-i) > 0;
	/*int c = calc(n-i, n-p);
	int a = calc(i, x);
	int b = calc(n-x, p);
	return c > a+b;*/
}

int solve(int x)
{
	int ret = 0;
	int p = R;
	for(int i = L; i <= R; i++)
	{
		while(p >= L && !check(x, i, p))
			p --;
		if(p < L)
			break;
		ret += p-L + 1;
	}
	return ret;
}

int MAIN()
{
	while(cin >> n >> m)
	{
		n ++;
		L = m+1, R = n-(m+1);
		long long ans = 0;
		for(int i = L; i <= R; i++)
			if(R-i > i-L)
				ans += 2*solve(i);
			else if(R-i == i-L)
				ans += solve(i);
			else
				break;
		cout << ans * 3 << endl;
	}
	
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}