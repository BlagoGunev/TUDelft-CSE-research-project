#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <cstdio> 
#include <map> 
#include <set> 
#include <cstdlib> 
#include <utility> 
#include <iomanip> 
#include <cmath>
#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <math.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	string s;
	while(t--){
		cin >> s;
		//string s;
		//s = to_string(n);
		int cnt = s.size();
		int z = s[0] - '0';
		for (int i = 1; i < s.size(); i++) {
			if (s[i] - '0' > z) break;
			if (s[i] - '0' < z) {
				z = max(z - 1, 0);
				break;
			}
			
		}
		cnt = max((cnt-1) * 9, 0) + z;
		cout << cnt << "\n";
	}
}