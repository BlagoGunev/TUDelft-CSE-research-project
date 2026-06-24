#define _CRT_SECURE_NO_DEPRECATE
//#pragma comment(linker, "/STACK:25000000")
#include <iostream>
#include <vector>
#include <cmath>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
ull md = 1e9 + 7;
ull pw(ull k, ull n) {
	if(n == 0)
		return 1;
	ull tmp = n / 2;
	ull tmp2 = pw(k, tmp);
	tmp2 *= tmp2;
	tmp2 %= md;
	if(n % 2)
		tmp2 *= k;
	tmp2 %= md;
	return tmp2;
}
int main() {
	ull n;
	cin >> n;
	if(n == 0)
		cout << 1 << endl;
	else
		cout << (pw(2, n - 1) * (pw(2, n) + 1) ) % md << endl;
    return 0;
}