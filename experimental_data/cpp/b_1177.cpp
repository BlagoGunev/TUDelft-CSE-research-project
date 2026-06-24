#include<bits/stdc++.h>
using namespace std;

long long get(int val) {
	return pow(10L, val) - pow(10l, val - 1);
}

char getIthDigit(long long value, int i) {
	return to_string(value)[i - 1];
}

char solve(long long k) {
	vector<long long> digits(13,0);
	for(int i=1;i<=12;i++) {
		digits[i] = get(i) * i + digits[i - 1];
	}
	int dig = 1;
	for(int i = 1;i <= 12;i++) {
		if(digits[i] >= k) {
			dig = i;
				break;
		}
	}
	k -= digits[dig - 1];
	long long realNumber = pow(10L, dig - 1) + (k + dig - 1) / dig - 1;
	int ith = (k % dig) ;
	if(ith == 0) ith = dig;
	return getIthDigit(realNumber, ith);
}

int main() {
	long long k;
	cin >> k;
	cout << solve(k) << endl;
}