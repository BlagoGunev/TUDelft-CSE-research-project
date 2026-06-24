#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	int a[105];
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&a[i]);
	}
	int sum = 0;
	int flag = 0;
	for (int i = 0; i < k; ++i) {
		for (int j = i + k; j < n; j += k) {
			if (a[i] != a[j]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (!flag) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < k; ++i) {
		int cnt1 = 0,cnt2 = 0;
		if (a[i] == 1) {
			cnt1 = 1;
		}
		else {
			cnt2 = 1;
		}
		for (int j = i + k; j < n; j += k) {
			if (a[j] == 1) {
				cnt1 ++;
			}
			else {
				cnt2 ++;
			}
		}
		if (cnt1 > cnt2) {
			sum += cnt2;
		} else if (cnt1 < cnt2) {
			sum += cnt1;
		} else {
			sum += cnt1;
		}
	}
	cout << sum << endl;
	return 0;
}