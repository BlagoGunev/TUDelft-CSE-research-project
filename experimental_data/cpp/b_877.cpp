#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
using namespace std;
string AB;
int DP[5001][3];//0 - 첫번째 1- 두번쨰 2-세번쨰
int main() {
	cin >> AB;
	int size = AB.length();
	for (int i = 1; i <= size; i++) {
		if (AB[i - 1] == 'a') {
			// 0 or 2
			DP[i][0] = DP[i - 1][0] + 1;
			DP[i][1] = max(DP[i - 1][0], DP[i - 1][1]);//cannot
			DP[i][2] = max(DP[i - 1][0], max(DP[i - 1][1], DP[i - 1][2])) + 1;
		}
		else {
			// 1
			DP[i][0] = DP[i - 1][0];
			DP[i][1] = max(DP[i - 1][0], DP[i - 1][1]) + 1;
			DP[i][2] = DP[i - 1][2];
		}
	}
	int result = max(DP[size][0], max(DP[size][1], DP[size][2]));
	cout << result << endl;
	//bbbb- aaaa
}