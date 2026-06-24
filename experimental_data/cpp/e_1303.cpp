#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int nax = 404;

string s,t;
int n,m;
vector<int> dp;
int cut;

void solve(){
	cin>>s>>t;
	n=s.size();
	m=t.size();
	bool can = 0;	
	for(int i=0;i<m;i++){
		dp = vector<int> (i+3,-1);
		dp[0] = 0;
		for(int x=0;x<n;x++){
			for(int j=i;j>=0;j--){
				if(dp[j] == -1)continue;
				if(s[x] == t[j])dp[j+1] = max(dp[j+1] , dp[j]);
				if(s[x] == t[i + dp[j]])dp[j]++;
			}
		}
		if(dp[i] == m-i){
			can = 1;
			break;
		}

	}
	cout << (can ? "YES" : "NO") << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif
	srand(time(0));
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}