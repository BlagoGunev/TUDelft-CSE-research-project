#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	vector<int>prime;
	prime.push_back(2);
	int r, c;
	cin>>r>>c;
	vector<int> row, col;
	int tar = r + c;
	if(r == 1 && c == 1) {
		cout<<0<<endl;
		return 0;
	}
	if(r == 1 || c == 1) {
		for(int i = 0; i < max(c, r); i++) {
			cout<<i + 2;
			if(r == 1) cout<<" ";
			else cout<<endl;
		}
		if(r==1)cout<<endl;
		return 0;
	}
	int x;
	for(x = 2; row.size() < r; x++) row.push_back(x);
	col.push_back(1);
	for(;col.size() < c; x++) col.push_back(x);

	if((ll)row[r - 1] * (ll)col[c - 1] > 1000000000LL) {
		cout<<0<<endl;
		return 0;
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cout<<row[i] * col[j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}