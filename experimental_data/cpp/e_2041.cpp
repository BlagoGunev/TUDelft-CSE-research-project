#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f


signed main(){
	int a,b;
	scanf("%lld%lld",&a,&b); 
	printf("3\n");
	a*=3;
	printf("%lld %lld ",b,b); 
	a-=2*b;
	printf("%lld",a);
	return 0;
}