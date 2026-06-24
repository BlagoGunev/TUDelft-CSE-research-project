#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	double s=0, y;
	for (int i=0;i<n;++i) cin>>y>>y, s+=y;
	cout << setprecision(10) << fixed << s/n+5 << endl;
	return 0;
}