#include<iostream>

#include<bits/stdc++.h>

using namespace std;

int main()

{

	long long int n;

	cin>>n;

	long long int a[n];

	long long int i;

	long long int max1=0;

	long long int x;

	long long int g;

	for(i=0;i<n;i++)

	{

		cin>>x;

		g=__gcd(x,g);

		max1=max(x,max1);

	}

	//cout<<g<<endl;

	cout<<((max1/g-n)%2?"Alice":"Bob");

	cout<<endl;

}