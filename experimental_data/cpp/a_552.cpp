#include<iostream>

using namespace std;

int main(){

	

	int n ;

	long long sum = 0;

	cin>>n;

	

	int x1, y1 , x2, y2;	

	

	for(int i = 0 ; i<n ; i++){

		cin>> x1 >> y1 >> x2 >> y2;

		sum= sum + (x2 - x1 + 1)*(y2 - y1 + 1);

	}

	

	cout<<sum;

	return 0;

	

}