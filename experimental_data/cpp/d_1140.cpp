#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;
	cin>>n;
	n--;
	long long int val;
	val=pow(n,3)+(pow(n,2)*3)+(n*2);
	cout<<val/3-2;
	return 0;
}