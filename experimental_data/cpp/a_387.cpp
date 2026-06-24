#include <cstdio>

#include <iostream>



using namespace std;



string s, t;

int x[5], y[5], a[5];



int main(){

	cin >> s >> t;

	for(int i = 0; i < s.size(); i++)

		if(i != 2){

			x[i] = s[i] - '0';

			y[i] = t[i] - '0';

		}

	if(x[0] == 0 && x[1] == 0){

		x[0] = 2;

		x[1] = 4;

	}

	if(x[0] * 10 + x[1] < y[0] * 10 + y[1]){

		x[0] += 2;

		x[1] += 4;

	}

	for(int i = 0; i < s.size(); i++)

		a[i] = x[i] - y[i];

	if(a[4] < 0){

		a[4] += 10;

		a[3]--;	

	}

	if(a[3] < 0){

		a[3] += 6;

		a[1]--;

	}

	if(a[1] < 0){

		a[1] += 10;

		a[0] -= 1;

	}

	if(a[0] == -1){

			a[0] = 2;

			a[1] %= 6;

	}

	if(a[0] == -2){

			a[0] = 1;

			a[1] %= 6;

	}

	if(a[0] == 2 && a[1] == 4){

		a[0] = 0;

		a[1] = 0;

	}

	cout << a[0] << a[1] << ":" << a[3] << a[4] << endl;

	return 0;

}