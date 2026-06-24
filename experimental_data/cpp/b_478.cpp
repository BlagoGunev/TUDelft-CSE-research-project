#include <bits/stdc++.h>
using namespace std;

long long sum(long long a)
{
	if(a == 0) {
		return 0;
	}
	a -= 1;
	return (a+1)*(a/2) + (a%2)*(a-a/2);
}
int main ()
{
	long long m, n;
	cin >> n >> m;
	long long k_min, k_max;
	k_max = sum(n - m + 1);
	k_min = sum(n/m)*(m-n%m) + sum(n/m+1)*(n%m);
	cout << k_min << " " << k_max;
	
	return 0;
}