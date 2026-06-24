#include<iostream>

#include<cstring>

#include<algorithm>

#include<cstdio>

#include<cmath>

using namespace std;

long long n,m,q,a[200005],kk;

long long gcd(long long x, long long y){ return !y?x:gcd(y,x%y);}

inline int get(){

	int sum = 0, t = 1; char ch = getchar();

	while(ch < '0' || ch > '9'){ if(ch == '-') t = -1; ch = getchar(); }

	while(ch >= '0' && ch <= '9'){ sum = sum * 10 + ch - '0'; ch = getchar(); }

	return sum * t;

}

long long f(long long x,long long y){

	int k=(y-x+n*m*100)%m;

	return a[k]*n+x;

}

long long ask(long long x,long long y){

	long long k=min(min(f(x,y),f(n-x,m-y)),min(f(n-x,y),f(x,m-y)));

	return k<=kk?k:-1;

}

int main(){

	n=get();m=get();q=get();

	kk=n*m/gcd(n,m);n*=2;m*=2;

	for(int i=m-1;~i;i--) a[i]=0x3f3f3f3f;

	for(int i=m;~i;i--) a[i*n%m]=i;

	for(int i=1,x,y;i<=q;i++){

		x=get();y=get();

		printf("%I64d\n",ask(x,y));

	}

	return 0;

}