#include<iostream>

using namespace std;

int n,mod=998244353;



int main(){

	long long a=0,b=1,c;

	cin>>n;

	for(int i=0;i<n-1;i++){

		c=a+b;

		a=b;

		b=c%mod;

	} 

	for(int i=0;i<n;i++) b=(b*(mod+1)/2)%mod;

	cout<<b;

}