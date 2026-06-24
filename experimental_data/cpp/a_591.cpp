#include<iostream>

#include<iomanip>

using namespace std;

int main(){

	

	

	int n, a, b;

	cin>> n >> a >> b;

	

	int sum= a+b;

	int mult= n*10000;

	

	double sumul= (double) mult /sum;

	sumul*=a;

	double ans= (double) sumul/10000;

	cout<< ans ;

	

	

	

}