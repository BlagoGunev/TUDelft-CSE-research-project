#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,num;
	while(~scanf("%d",&n)){
		num= (n+1)/2;
		printf("%d\n",2*n-num);
	}
}