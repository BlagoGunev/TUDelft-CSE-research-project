#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <set>

#include <map>

#include <deque>

#include <queue>

#include <stack>

#include <iomanip>

#include <cmath>



using namespace std;



int main() {

	int n;

	cin >> n;

	vector <string> s(10);

	s[0] = "zero";

	s[1] = "one";

	s[2] = "two";

	s[3] = "three";

	s[4] = "four";

	s[5] = "five";

	s[6] = "six";

	s[7] = "seven";

	s[8] = "eight";

	s[9] = "nine";

	if (n / 10 == 0)

	{

		cout << s[n];

		return 0;

	}

	if (n / 10 == 1)

	{

		if (n == 10)

			cout << "ten";

		if (n == 11)

			cout << "eleven";

		if (n == 12)

			cout << "twelve";

		if (n == 13)

			cout << "thirteen";

		if (n == 15)

			cout << "fifteen";

		if (n == 18)

			cout << "eighteen";

		if (n == 14 || n == 16 || n == 19 || n == 17)

			cout << s[n % 10] << "teen";

		return 0;

	}

	if (n / 10 == 2)

		cout << "twenty";

	if (n / 10 == 3)

		cout << "thirty";

	if (n / 10 == 4)

		cout << "forty";

	if (n / 10 == 5)

		cout << "fifty";

	if (n / 10 == 8)

		cout << "eighty";

	if (n / 10 == 9 || n / 10 == 6 || n / 10 == 7)

		cout << s[n / 10] << "ty";

	if (n % 10 > 0)

		cout << "-" << s[n % 10];

	return 0;

}