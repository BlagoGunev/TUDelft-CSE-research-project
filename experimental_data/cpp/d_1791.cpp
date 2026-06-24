#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define MOD 1000000007



// cuoi Thao



void solve(){

	int n,ans=0,now; cin >> n;

	string s; cin >> s;

	int v[26]={0}; int p[26]={0};

	for(int i=0;i<n;i++) v[s[i]-'a']++;

	for(int i=0;i<n-1;i++){

		now=0;

		++p[s[i]-'a']; --v[s[i]-'a'];

		for(int j=0;j<26;j++){

			now+= min(1, v[j])+min(1, p[j]);

		}

		ans = max(ans, now);

	}

	cout << ans << endl;

}



int main(){

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	int t; cin >> t;

	while(t--){

		solve();

	}

	return 0;

}