#include <bits/stdc++.h>
using namespace std;
#define N 105
#define fr(i,a,b) for(int i=a;i <= b;i++)

int n,a[N],pos[N];

int main() {
	cin >> n;
	fr(i,1,n) {
		cin >> a[i];
		if(a[i] == 1) {
			pos[i] = 1;
		}
		pos[i] += pos[i-1];
	}
	int ans = max(pos[n],n-pos[n]);
	fr(i,1,n) {
		ans = max(ans,i-pos[i] + pos[n]-pos[i]);
	}
	cout << ans << endl;
}