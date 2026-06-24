#include <iostream>

using namespace std;



int main(){

	int k,r;

	cin >> k >> r;

	for(int x = 1; ; ++x){

		if((k*x)%10 == 0 || (k*x)%10==r){

			cout << x;

			return 0;

		}

	}

}