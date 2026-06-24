#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define LL long long 
using namespace std;
LL l,r,a;

LL gcd(LL a,LL b){
	if (b==0) return a;
	return gcd(b,a%b);
}

int main(){
	scanf("%lld%lld",&l,&r);
	if ((r-l+1)%2==1) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (LL i=l;i<=r;i+=2)	printf("%lld %lld\n",i,i+1);
	 
}