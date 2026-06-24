#include<bits/stdc++.h>

#include <iostream>

using namespace std;



int main() {

	int n,c;

	long long int l=0,g=0,time=0,sum=0;

	cin>>n>>c;

	int a[n],t[n];

	int i=0;

	for(i=0;i<n;i++)

	{

		cin>>a[i];

	}

	for(i=0;i<n;i++)

	{

		cin>>t[i];

	}

	for(i=0;i<n;i++)

	{

		time+=t[i];

		if(a[i]-time*c>0)

		l+=(a[i]-(time*c));

	

	}



 	time=0;

 	for(i=n-1;i>=0;i--)

	{

		time+=t[i];

		if(a[i]-time*c>0)

		g+=(a[i]-(time*c));

	

	}

	if(l>g)cout<<"Limak\n";

	else if(l<g)cout<<"Radewoosh\n";

	else cout<<"Tie\n";

	return 0;

}