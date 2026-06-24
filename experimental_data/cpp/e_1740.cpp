#include<bits/stdc++.h>

#define endl '\n'

#define iloveds std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define all(a) a.begin(),a.end()

using namespace std;

typedef long long ll ;

const int N = 1e5 + 100;



vector<int> g[N];



int n, dp[N][2];



void dfs(int x, int fa){

	dp[x][1] = 1;

	for(auto i : g[x]){

		if(i == fa) continue;

		dfs(i, x);

		dp[x][0] += max(dp[i][0], dp[i][1]);

		dp[x][1] = max(dp[x][1], dp[i][1] + 1);

	}

}

int main(){

	iloveds;

	cin >> n;

	for(int i = 2; i <= n ; i ++){

		int x;

		cin >> x;

		g[i].push_back(x);

		g[x].push_back(i);

	}

	dfs(1, 0);

	cout << max(dp[1][0], dp[1][1]);

}