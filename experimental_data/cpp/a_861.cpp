#include <bits/stdc++.h>

using namespace std;

long int quick_pow10(int n)
{
    static long int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    return pow10[n]; 
}

long long int gcd(long long int a, long int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int k,i;
	long long int n,n2;
	i=0;
	scanf("%lld %d",&n,&k);

	printf("%lld\n",(n*quick_pow10(k))/gcd(n,quick_pow10(k)));
	return 0;
}