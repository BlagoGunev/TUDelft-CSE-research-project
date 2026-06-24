//Author : qqqaaazzz 
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int n,q;
char a[200010];
int sa[200010][26];
char b[200010];
int sb[200010][26];

void solve(){
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		for(int j=0;j<26;j++) sa[i][j] = sa[i-1][j]+(a[i]-'a'==j); 
	}
	for (int i=1;i<=n;i++){
		cin >> b[i];
		for(int j=0;j<26;j++) sb[i][j] = sb[i-1][j]+(b[i]-'a'==j); 
	}
	for (int i=1;i<=q;i++){
		int l,r;
		cin >> l >> r;
		int ans = 0;
		for (int j=0;j<26;j++){
			ans += abs((sa[r][j]-sa[l-1][j])-(sb[r][j]-sb[l-1][j]));
		}
		cout << ans/2 << "\n";
	}
	return;
}

signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}