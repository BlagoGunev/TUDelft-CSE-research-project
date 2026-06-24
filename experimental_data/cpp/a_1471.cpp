#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;


long long A;
long long S;
long long C;
long n;
long long x;


long long ceilDiv(long long a, long long b){
	if (a % b > 0) return a / b + 1;
	return a / b;
}



void doTest(){
	scanf("%ld%lld", &n, &x);
	C = 0;
	S = 0;
	for (long i = 0; i < n; ++i){
		scanf("%lld", &A);
		S += A;
		C += ceilDiv(A, x);
	}
	printf("%lld %lld\n", ceilDiv(S, x), C);
	
}

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i){
		doTest();
	}
	return 0;
}