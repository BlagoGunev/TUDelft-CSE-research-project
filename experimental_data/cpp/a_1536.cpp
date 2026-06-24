#include <iostream>

#include <cmath>

using namespace std;

int main() {

	int t,n,flag=0;

	int a[305];

	cin>>t;

	for(int i=0; i<t; i++) {

		cin>>n;

		for(int j=0; j<n; j++) {

			cin>>a[j];

			if(a[j]<0)flag=1;

		}

		if(flag)cout<<"NO"<<endl;

		else {

			cout<<"YES"<<endl<<101<<endl;

			for(int i=0; i<101; i++)cout<<i<<' ';

			cout<<endl;

		}

		flag=0;

	}



}