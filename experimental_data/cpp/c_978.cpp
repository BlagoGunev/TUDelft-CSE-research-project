#include <bits/stdc++.h>
using namespace std;

long long read(){
	char c;while(c=getchar(),(c<'0'||c>'9')&&c!='-');
	long long x=0,y=1;c=='-'?y=-1:x=c-'0';
	while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';
	return x*y;
}

const int Maxn=2*1e5+5;
long long N,M,A[Maxn],Sum[Maxn],Now;

int main()
{
	N=read(),M=read();
		for(int i=1;i<=N;i++)A[i]=read(),Sum[i]=Sum[i-1]+A[i];
	Sum[N+1]=2e15;
		for(int i=1;i<=M;i++){
			long long x=read();
			while(x>Sum[Now])Now++;
			printf("%lld %lld\n",Now,x-Sum[Now-1]);
		}
}