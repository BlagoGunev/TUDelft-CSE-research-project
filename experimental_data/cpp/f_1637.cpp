#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 200003;

int n, h[N], rt;

vector<int> E[N];

LL ans;

int dfs(int x, int f){

	vector<int> tmp = {0};

	for(int v : E[x]) if(v != f) tmp.push_back(dfs(v, x));

	sort(tmp.begin(), tmp.end());

	ans += max(h[x] - tmp.back(), 0);

	if(x == rt){tmp.pop_back(); ans += max(h[x] - tmp.back(), 0);}

	return max(h[x], tmp.back()); 

}

int main(){

	ios::sync_with_stdio(0);

	cin >> n;

	for(int i = 1;i <= n;++ i) cin >> h[i];

	for(int i = 1, u, v;i < n;++ i){

		cin >> u >> v;

		E[u].push_back(v);

		E[v].push_back(u);

	}

	rt = max_element(h + 1, h + n + 1) - h;

	dfs(rt, 0); printf("%lld\n", ans);

}