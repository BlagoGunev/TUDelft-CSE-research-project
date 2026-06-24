#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 1000 * 100 + 1;
int a, b, x;
int main(){
	fast();
	cin >> a >> b >> x;

	string res = "10";
	a--, b--;
	x--;
	while (x){
		if (res.back() == '1'&&a){
			res += '0';
			x--; a--;
		}
		else if (res.back() == '0'&&b){
			res += '1';
			x--; b--;
		}
		else if (res[0] == '1' &&a){
			res = "0" + res;
			x--; a--;
		}
		else if (res[0] == '0'&&b){
			res = "1" + res;
			x--; b--;
		}
	}
	int idx = -1, idx1 = -1;
	for (int i = 0; i < res.size(); i++){
		if (res[i] == '0'){
			idx = i; break;
		}
	}
	
	while (a){
		a--;
		res.insert(idx, "0");
	}
	for (int i = 0; i < res.size(); i++){
		if (res[i] == '1'){
			idx1 = i; break;
		}
	}
	while (b){
		b--;
		res.insert(idx1, "1");
	}

	cout << res << endl;
	return 0;
}