#include<iostream>

#include<cstdio>

using namespace std;

int main(){

	int n;

	cin>>n;

	for(int i=0;i*1234567<=n;i++){

		for(int j=0;(i*1234567)+(j*123456)<=n;j++){

			if((n-((i*1234567)+(j*123456)))%1234==0){

				cout<<"YES";

				return 0;

			}

		}

	}

	cout<<"NO";

}