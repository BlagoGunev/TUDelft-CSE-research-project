#include <iostream>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		string s, t;
		cin >> s >> t;
		bool flag = 0;
		for (int k = 0; k < s.size(); k++) {
			for (int j = 0; j < s.size(); j++) {
				if (s[k] == t[j]) {
					cout << "YES" << endl;
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 0) {
			cout << "NO" << endl;
		}
	}
	

}