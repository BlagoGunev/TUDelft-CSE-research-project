#include <iostream>

#include <cmath>

#include <string>



using namespace std;



int main()

{

	char c;

	string s[4];

	int cnt1 = 0;

	bool ch[4] = { 0 };

	for (int i = 0; i < 4; i++) {

		cin >> c >> c >> s[i];

	}

	for (int i = 0; i < 4; i++) {

		int cnt = 0;

		for (int j = 0; j < 4; j++) {

			cnt += s[i].size() <= s[j].size() / 2;

		}

		if (cnt == 3) {

			ch[i] = 1;

			cnt1++;

		}

		cnt = 0;

		for (int j = 0; j < 4; j++) {

			cnt += s[i].size() >= s[j].size()*2;

		}

		if (cnt == 3) {

			ch[i] = 1;

			cnt1++;

		}

	}

	if(cnt1>1 || cnt1<1)

	cout << "C" << endl;

	else

		for (int i = 0; i < 4; i++) {

			if (ch[i])cout << char('A' + i);

		}

	return 0;

}