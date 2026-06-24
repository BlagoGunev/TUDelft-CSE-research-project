// Source: https://usaco.guide/general/io



#include <bits/stdc++.h>

using namespace std;



int main() {

	string s;

	cin >> s;

	int n = (int)s.size();



	if(n == 1) {

		if(s[0] == '0' || s[0] == 'X' || s[0] == '_') {

			cout << 1 << endl;

		} else {

			cout << 0 << endl;

		}

		return 0;

	}



	if(s[0] == '0') {

		cout << 0 << endl;

		return 0;

	}



	long long uFactor = 1;

	int xFactor = 1;

	for(int i = 0; i < n - 2; i++) {

		if(s[i] == '_') {

			if(i == 0) {

				uFactor *= 9;

			} else {

				uFactor *= 10;

			}

		}

		else if(s[i] == 'X') {

			if(xFactor == 1) {

				if(i == 0) {

					xFactor = 9;

				} else {

					xFactor = 10;

				}

			}

		}

	}



	long long ans = 0;

	int xValue = -1;

	for(int i = 0; i < 100; i += 25) {

		xValue = -1;

		int ones = i % 10;

		int tens = i / 10;



		bool onesOk = false;

		bool tensOk = false;



		// ones

		if(s[n - 1] == '_') {

			onesOk = true;

		}

		else if(s[n - 1] == 'X') {

			onesOk = true;

			xValue = ones;

		} else {

			// cout << (s[n - 1] - '0') << endl;

			onesOk = (s[n - 1] - '0') == ones;

		}



		// tens

		if(s[n - 2] == '_') {

			tensOk = true;

		} 

		else if(s[n - 2] == 'X') {

			// Check if ones already used the X

			if(xValue != -1) {

				tensOk = (tens == xValue);

			} else {

				tensOk = true;

				xValue = tens;

			}

		} else {

			tensOk = (s[n - 2] - '0') == tens;

		}



		// cout << i << ", tensok: " << tensOk << ", onesOk: " << onesOk << endl;



		if(xValue == 0 && s[0] == 'X') continue;

		if(tens == 0 && n == 2) continue;



		if(tensOk && onesOk) {

			if(xValue == -1) {

				ans += xFactor * uFactor;

			} else {

				ans += uFactor;

			}

		}

	}



	cout << ans << endl;

}