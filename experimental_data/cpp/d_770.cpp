#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <fstream>
#include <set>
#include <map>
using namespace std;
typedef long long int ll;

#define op(i) s[i] == '['
#define cl(i) s[i] == ']'

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> depth(n);
	int mx = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		depth[i] = cur;
		if (op(i)) {
			cur++;
			mx = max(mx, cur);
		}
		else {
			depth[i]--;
			cur--;
		}
	}
	/*vector<int> count(n);
	vector<int> stack;
	stack.reserve(n);
	for (int i = 0; i < n; i++) {
		if (op(i)) {
			for (int j = 0; j < stack.size(); j++) {
				count[stack[j]]++;
			}
			stack.push_back(i);
		}
		else {
			stack.pop_back();
		}
	}*/
	for (int i = 0; i <= mx; i++) {
		for (int j = 0; j < n; j++) {
			if (op(j) && depth[j] == i) {
				cout << "+-";
			}
			else if (cl(j) && depth[j] == i) {
				cout << "-+";
			}
			else if (depth[j] < i) {
				cout << "|";
				if (op(j) && j < n - 1 && cl(j + 1)) {
					cout << "   ";
				}
			}
			else if (depth[j] > i) {
				cout << " ";
				if (j < n - 1 && cl(j) && op(j + 1)) {
					cout << "  ";
				}
			}
			if (depth[j] >= i && op(j) && j < n - 1 && cl(j + 1)) {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = mx - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (op(j) && depth[j] == i) {
				cout << "+-";
			}
			else if (cl(j) && depth[j] == i) {
				cout << "-+";
			}
			else if (depth[j] < i) {
				cout << "|";
				if (op(j) && j < n - 1 && cl(j + 1)) {
					cout << "   ";
				}
			}
			else if (depth[j] > i) {
				cout << " ";
				if (j < n - 1 && cl(j) && op(j + 1)) {
					cout << "  ";
				}
			}
			if (depth[j] >= i && op(j) && j < n - 1 && cl(j + 1)) {
				cout << " ";
			}
		}
		cout << endl;
	}
#ifdef _MSC_VER
	system("pause");
#endif
	return 0;
}