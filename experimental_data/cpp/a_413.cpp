#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m,mn,mx; cin>>n>>m>>mn>>mx;
	vector<int> t(m);
	int mn2=1e9, mx2=0;
	for (int i=0; i<m; i++) {
		int x; cin>>x;
		if(x<mn||x>mx) { cout << "Incorrect" << endl; return 0; }
		mn2=min(mn2,x);
		mx2=max(mx2,x);
	}

	int ret=0;
	if(mn2!=mn) ret++;
	if(mx2!=mx) ret++;

	if(n-m>=ret) cout << "Correct" << endl;
	else cout << "Incorrect" << endl;
	return 0;
}