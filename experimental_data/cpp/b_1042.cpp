#include <iostream>
#include <string>
using namespace std;

int main(){

	int n;
	string str;

	cin >> n;

	int num;
	int a, b, c;
	int ab, bc, ac;

	bool A = false, B = false, C = false;

	int minA = 1000000, minB = 1000000, minC = 1000000;
	int minAB = 1000000, minBC = 1000000, minAC = 1000000, minABC = 1000000;
	int min = 100000000;

	int arr[11];

	for(int i = 0; i < n; i++){

		cin >> num >> str;

		if(str == "A" && num < minA){
			minA = num;
			A = true;
		}

		else if(str == "B" && num < minB){
			minB = num;
			B = true;
		}

		else if(str == "C" && num < minC){
			minC = num;
			C = true;
		}

		else if((str == "AB" || str == "BA") && num < minAB){
			minAB = num;
			A = true;
			B = true;
		}

		else if((str == "AC" || str == "CA") && num < minAC){
			minAC = num;
			A = true;
			C = true;
		}

		else if((str == "BC" || str == "CB") && num < minBC){
			minBC = num;
			B = true;
			C = true;
		}

		else if((str == "ABC" || str == "ACB" || str == "BAC" || str == "CAB" || str == "CBA" || str== "BCA") && num < minABC){
			minABC = num;
			A = true;
			B = true;
			C = true;
		}

	}

	if(A == true && B == true && C == true){

		arr[0] = minA + minB + minC;

		arr[1] = minAB + minC;

		arr[2] = minAC + minB;

		arr[3] = minBC + minA;

		arr[4] = minABC;

		arr[5] = minAB + minBC;

		arr[6] = minAB + minAC;

		arr[7] = minBC + minAC;

		arr[8] = minBC + minAB;

		arr[9] = minAC + minAB;

		arr[10] = minAC + minBC;

		for(int i = 0; i < 11; i++){
			if(arr[i] < min)
				min = arr[i];
		}

		cout << min;
	}

	else
		cout << -1;



}