#include<iostream>

#include<string>

using namespace std;

int main(){

	int n, x=0, X=0, t=0;

	string a;

	cin >> n >> a;

	for (int i = 0; i < a.size(); i++)

		if (a[i] == 'X')

			X++;

		else

			x++;

	for (int i = 0; i < n; i++){

		if (x < X&&a[i] == 'X')

			a[i] = 'x', x++, X--, t++;

		else if (x > X&&a[i] == 'x')

			a[i] = 'X', x--, X++, t++;

	}

	cout << t << endl << a;

	cin >> n;

}