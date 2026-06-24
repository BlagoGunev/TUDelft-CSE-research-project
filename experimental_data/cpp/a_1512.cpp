#include <bits/stdc++.h>

using namespace std;

 

int main() {

	int n;

	cin >> n;

	for(int i=0; i<n; i++){

		int a;

		cin >> a;

		int arr[a];

		for(int j=0; j<a; j++){

			cin >> arr[j];

		}

		int total[101]={0};

		for(int i=0; i<a; i++) {

			total[arr[i]]++;

		}

		for(int i=0; i<a; i++) {

			if(total[arr[i]]==1) {

				cout << i+1 << endl;

			}

		}

	}

}