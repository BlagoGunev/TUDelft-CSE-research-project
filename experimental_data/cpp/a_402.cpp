#include<iostream>

#include<vector>

#include<string>

#include<queue>

#include<algorithm>

#include<set>

#include<map>

#include<cmath>



using namespace std;



#define ll long long



//ifstream cin("input.txt"); ofstream cout("output.txt");

ll maxl(ll a, ll b) {

	if (a < b) return b;

	else return a;

}

ll minl(ll a, ll b) {

	if (a < b) return a;

	else return b;

}

int main(){

	int k, n, b, v;

	cin >> k >> n >> b >> v;

	int kol = 0;

	while (n >0 && b >=0) {

		n -= (min(b+1,k))*v;

		kol++;

		b = b - k + 1;

	}

	kol += max(0, (n+v-1)/v);

	cout << kol;

	return 0;

}