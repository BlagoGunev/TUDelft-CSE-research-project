#include<bits/stdc++.h>



using namespace std;



int main(){

	int n;

	cin >> n;

	while(n--){

		int a,b;

		cin >> a >> b;

		if(a>3 && b>3){

			cout << "1 1" << endl;

			continue;

		}

		if(a==1 || b==1){

			cout << "1 1" << endl;

		}

		else{

			cout << "2 2" << endl;

			continue;

		}

	}

}