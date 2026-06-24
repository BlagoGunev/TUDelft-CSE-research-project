#include<bits/stdc++.h>
using namespace std;

int main(){
	long double n;
	cin >> n;
	long double x,y;
	cin >> x >> y;
	if(sqrt((pow((x-1),2)+pow(y-1,2))) > sqrt((pow((n-x),2)+pow(n-y,2))))
		cout << "Black" << endl;
	else if(sqrt((pow((x-1),2)+pow(y-1,2))) <= sqrt((pow((n-x),2)+pow(n-y,2))))
		cout << "White" << endl;
}