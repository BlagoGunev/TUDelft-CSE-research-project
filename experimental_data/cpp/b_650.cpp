#include <bits/stdc++.h>

using namespace std;

const int maxn = 500005;

int see[maxn];

int n, a, b, t;

string str;



bool check(int len){

	//cout << len << endl;

	for (int i=1; i<=len; ++i){

		int t1 = see[i-1];

		int t2 = see[n-1]-see[n-1-len+i];

		int tt = min((i-1)*a, (len-i)*a)+t1+t2;

		if (tt <= t)

			return true;

	}

	return false;

}



int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);

	cin >> n >> a >> b >> t >> str;

	see[0] = 1+(str[0]=='w')*b;

	for (int i=1; i<n; ++i)

		see[i] = see[i-1]+a+1+(str[i]=='w')*b;

	int low=0, high=n;

	while (low < high){

		int mid = (low+high+1)>>1;

		if (check(mid))

			low = mid;

		else

			high = mid-1;

	}

	cout << low << endl;

	return 0;

}