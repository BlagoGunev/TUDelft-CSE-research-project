#include <iostream>

#include <string>

using namespace std;



//int y;

int main(){

	int n, m = 0;

	cin >> n;

	string d[n];

	

	for ( int i = 0; i < n; ++i){

		cin >> d[i];

		if ( d[i]=="X++"){

			 m++;

		}

		if ( d[i]=="++X"){

			++m;

		}

		if ( d[i]=="X--"){

			m--;

		}

		if ( d[i]=="--X"){

			--m;

		}

	}

	cout << m << endl;

	return 0;

	

}