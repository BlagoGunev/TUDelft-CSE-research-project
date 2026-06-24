#include<cstdio>
long long gcd(long long A, long long B){return A % B ? gcd(B, A % B): B;}
long long N, M;
int main(){
	scanf("%I64d%I64d", &N, &M);
	if(N < M){
		long long tmp = N;
		N = M;
		M = tmp;
	}
	long long G = gcd(N - 1, M - 1);
	printf("%I64d\n", G + 1);
	//scanf(" ");
}