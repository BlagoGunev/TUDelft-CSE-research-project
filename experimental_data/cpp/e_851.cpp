#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

vector<int> data;
map<int, int> cache;

int CheckWinner(int powers) {
	if (cache.count(powers)) {
		return cache[powers];
	}
	int high = 0;
	while (powers >= (1 << high)) {
		high++;
	}
	set<int> res;
	for (int i = 0; i < high; ++i) {
		// if (!(powers & (1 << i))) {
		// 	continue;
		// }
		int sub_power = (powers >> (i + 1)) | (powers & ((1 << i) - 1));
		res.insert(CheckWinner(sub_power));
	}
	int i;
	for (i = 0; res.count(i); ++i) {
	}
	cache[powers] = i;
	return i;
}

int main() {
	int n;
	cin >> n;
	data.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}
	map<int, int> divisors;
	for (int i = 0; i < n; ++i) {
		for (int j = 2; data[i] != 1 && j * j <= data[i]; ++j) {
			int k;
			for (k = 0; data[i] % j == 0; ++k, data[i] /= j) {
			}
			if (k > 0) {
				divisors[j] |= 1 << (k - 1);
			}
		}
		if (data[i] != 1) {
			divisors[data[i]] |= 1;
		}
	}
	cache[0] = 0;
	int res = 0;
	for (auto it: divisors) {
		res ^= CheckWinner(it.second);
	}
	if (res) {
		cout << "Mojtaba" << endl;
	} else {
		cout << "Arpa" << endl;
	}
}