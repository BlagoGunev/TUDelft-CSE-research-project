#include<bits/stdc++.h>

using namespace std;

int main()

{

	int a[]={2,7,2,3,3,4,2,5,1,2};

	int x;

	cin>>x;

	cout<<a[x/10]*a[x%10];

	return 0;

}