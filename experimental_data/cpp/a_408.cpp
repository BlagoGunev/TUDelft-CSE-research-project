#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<queue>

#include<stack>

#include<utility>

#include<cmath>

#include<cctype>

#include<stdio.h>



using namespace std;

int main() {

	int n;

	cin >> n;

	vector<int> pe(n);

	vector<int> it(n);

	vector<int> total(n);

	for (int i = 0; i < n; i++) {

		cin >> pe[i];

	}

	int x;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < pe[i]; j++) {

			cin >> x;

			total[i] = total[i] + x * 5;

		}

		total[i] = total[i] + 15 * pe[i];

	}

	sort(total.begin(), total.end());

	cout << total[0] << endl;





	return 0;

}