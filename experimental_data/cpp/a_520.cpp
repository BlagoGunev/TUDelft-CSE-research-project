#include <iostream>

#include <algorithm>



using namespace std;



void LowerCase(string &s){

	for (long i = 0; i < s.length(); i++){

		if (s[i] >= 'A' && s[i] <= 'Z') s[i] +=32;

	}

}



int main(){

	string s;

	string x = "hello";

	long d[10000] = {};

	long n;

	long is = 0, ix = 0;

	cin >> n;

	cin >> s;

	LowerCase(s);

	for (long i = 0; i < s.length(); i++){

		d[s[i]] = 1;

 	}

 	for (long i = 'a'; i <= 'z'; i++){

 		if (d[i] == 0){

 			cout << "NO";

 			return 0;

		 }

	 }

	 cout << "YES";

	

	

	return 0;

}