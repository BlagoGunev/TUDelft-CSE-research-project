#include <bits/stdc++.h>
using namespace std;
int n,a=4;
bool prime(int x){
	for(int i=2;i<=sqrt(x);i++)if(x%i==0)return false;
	return true;
}
int main(){
	scanf("%d",&n);
	while(prime(a)||prime(a+n))a++;
	printf("%d %d",a+n,a);
	return 0;
}