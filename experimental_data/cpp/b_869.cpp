#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull a, b;
ull ans = 1;
int main()
{
	scanf("%lld%lld", &a, &b);
	for(ull i = a+1; i <= b; i++) {
		ans *= i;
		ans %= 10;
		if(!ans)
			break;
	}
	printf("%lld\n", ans);
	return 0;
}