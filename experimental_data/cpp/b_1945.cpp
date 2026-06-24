#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include <cstring>
#include<algorithm>
using namespace std;
long long gcd(long long a, long long b)
{
	if (a % b == 0)
		return b;
	else return (gcd(b, a % b));	

}

void solove() {
	long long a, b, m;
	cin >> a >> b >> m;
	long long t = a * b / gcd(a, b);
	long long ans = 0;
	ans += m / a + m / b+2;
	cout << ans << endl;
}
int main()
{
	
	int t;
	cin >> t;
	while (t--)
	{
		solove();
	}
}