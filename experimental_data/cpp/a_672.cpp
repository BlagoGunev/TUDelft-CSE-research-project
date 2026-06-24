#include<iostream>

#include<cstdio>

using namespace std;

int main(){

	int n,z=0,i=1;

	cin>>n;

	while(z<n){

		if(i>99)

			z++;

		if(z==n)

			cout<<i/100;

		if(i>9)

			z++;

		if(z==n)

			cout<<(i/10)%10;

		z++;

		if(z==n)

			cout<<i%10;

		i++;

	}

}