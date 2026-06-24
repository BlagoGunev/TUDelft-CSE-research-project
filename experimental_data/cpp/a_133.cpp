#include <iostream>

#include <string>



using namespace std;



string func(const string& src) {

	if (src.find_first_of("HQ9") != string::npos) return "YES";

	return "NO";

}





int main(int argc, char *argv[])

{

	string input;

	cin >> input;

	cout << func(input);



	cout << endl;

	return 0;

}