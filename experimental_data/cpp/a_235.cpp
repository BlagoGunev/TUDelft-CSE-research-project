#include <iostream>

#include <cstdlib>

#include <cstdio>

#include <string>

#include <vector>

#include <map>

#include <set>

#include <cmath>

#include <iterator>

#include <algorithm>

#include <iterator>

#define ll long long

using namespace std;







int main(){

	int n;

	cin >> n;

	if (n < 3) cout << n;

	else{

		ll a, m = n;

		if (n % 2){

			a = m*(m - 1)*(m - 2);

		}

		else if (n % 3){

			a = m*(m - 1)*(m - 3);

		}

		else a = (m - 1)*(m - 2)*(m - 3);

		cout << a;

	}

	//system("pause");

	return 0;

}