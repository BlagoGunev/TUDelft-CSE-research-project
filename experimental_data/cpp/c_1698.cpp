#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;



const int MAX = 200007;

const int MOD = 1000000007;



void solve() {

	int numele;

	cin >> numele;

	vector <int> posnum,negnum,arr;

	int temp;

	int zero = 0;

	for (int i = 0; i < numele; i++) {

		cin >> temp;

		if (temp > 0) {

			posnum.push_back(temp);

		}

		else if (temp < 0) {

			negnum.push_back(temp);

		}

		else if(zero<1) {

			arr.push_back(0);

			zero++;

		}

	}

	if (posnum.size() > 2 || negnum.size() > 2) {

		cout << "NO"<<endl; 

		return;

	}

	for (int i = 0,possize= posnum.size(); i < possize; i++) {

		//cout << posnum.front() << endl;

		arr.push_back(posnum.front());

		posnum.erase(posnum.begin());

	}

	for (int i = 0,negsize=negnum.size(); i < negsize; i++) {

		//cout << negnum.front()<<endl;

		arr.push_back(negnum.front());

		negnum.erase(negnum.begin());

	}

	/*if (arr.size() < 2) {

		cout << "NO" << endl; return;

	}*/

	//cout << "arrsiez" << arr.size()<<endl;

	for (int i = 0; i < arr.size(); i++) {

		for (int j = i + 1; j < arr.size(); j++) {

			for (int k = j + 1; k < arr.size(); k++) {

				bool ok = false;

				//cout << "k " << k << endl;

				for (int l = 0; l < arr.size(); l++) {

					if (arr[i] + arr[j] + arr[k] == arr[l]) {

						//cout << "WTF?" << endl;

						ok = true;

						break;

					}

				}

				if (!ok) { cout << "NO"<<endl; return; }

			}

		}

	}

	cout << "YES"<<endl;

	return;



}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	int tt; cin >> tt; for (int i = 1; i <= tt; i++) { solve(); }

	// solve();

}