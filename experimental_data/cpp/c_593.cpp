#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, t;
vector<int> A(1488), B(1337);

void FF(vector<int> T){
	cout << "abs(";
	for(int i; i < n - 1; i++)
		cout << "(";
	for(int i = 0; i < n; i++){
		cout << "(" << T[i] / 2 << "*((1-abs((t-" << i << ")))+abs((abs((t-" << i << "))-1))))";
		if(i > 0)
			cout << ")";
		if (i + 1 < n)
			cout << "+";
	}
	cout << ")";
	cout << '\n';
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> t;
	FF(A);
	FF(B);
}