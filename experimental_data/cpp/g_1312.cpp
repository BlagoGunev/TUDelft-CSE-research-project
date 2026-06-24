#include<bits/stdc++.h>

#define endl '\n'

#define iloveds std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define all(a) a.begin(),a.end()

using namespace std;

typedef long long ll ;

const int N = 1e6 + 100;



int n, ch[N][26], k, a[N], b[N], dfn[N], ans[N], f[N];

int tot, dp[N], val;



void dfs(int x){

	if(f[x]) {

		dfn[x] = ++ tot;

	}

	for(int i = 0 ; i < 26; i ++){

		if(ch[x][i]){

			dfs(ch[x][i]);

			dfn[x] = min(dfn[x], dfn[ch[x][i]]);

		}

		

	}

}



void dfs2(int x){

	for(int i = 0 ; i < 26; i ++){

		int tmp = val;

		if(ch[x][i]) {

			if(f[ch[x][i]]){

				dp[ch[x][i]] = min(dp[x] + 1, dfn[ch[x][i]] + val);

			}else{

				dp[ch[x][i]] = dp[x] + 1;

			}

			val = min(val, dp[ch[x][i]] - dfn[ch[x][i]] + 1);

			dfs2(ch[x][i]);

		}

		val = tmp;

	}



}





// dp[fa] - dfn[fa] + 1 + dfn[x];

int main(){

	iloveds;

	cin >> n;

	for(int i = 1; i <= n ; i ++){

		int x;

		char c;

		cin >> x >> c;

		ch[x][c - 'a'] = i;

	}

	cin >> k;

	for(int i = 1; i <= k ; i ++){

		cin >> a[i];

		f[a[i]] = 1;

	}

	for(int i = 1; i <= n ; i ++) {

		dp[i] = 0x3f3f3f3f;

		dfn[i] = 0x3f3f3f3f;

	}

	dfs(0);

	val = 0;

	dfs2(0);

	for(int i = 1; i <= k ; i ++) cout << dp[a[i]] << " ";

}