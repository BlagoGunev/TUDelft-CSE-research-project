#include <cstdio>

#include <iostream>



using namespace std;



const int MAX_N = 100 + 10;

int x[MAX_N], y[MAX_N], mx;



int main(){

	int n;

	cin >> n;

	char a[MAX_N][MAX_N];

	for(int i = 0; i < n; i++)

		for(int j = 0; j < n; j++){

			cin >> a[i][j];

			if(a[i][j]== 'C')

				x[i]++;

		}

	for(int i = 0; i < n; i++){

		for(int j = 0; j < n; j++){

			if(a[j][i] == 'C')

				y[i]++;

		}

	}

	for(int i = 0; i < n; i++){

		if(x[i] > 1)

			mx += (x[i] * (x[i] - 1)) / 2;

		if(y[i] > 1)

			mx += (y[i] * (y[i] - 1)) / 2;

	}

	cout << mx << endl;

}