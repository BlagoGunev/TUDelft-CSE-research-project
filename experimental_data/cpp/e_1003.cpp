#include <bits/stdc++.h>
#define left lef
using namespace std;
const int N =  400001;

int n,d,k,cnt,left;
vector <int> g[N];
vector <pair<int,int> > ans;

void go(int node,int levels){
	while (g[node].size() < k && left > 0 && levels > 0){
		g[node].push_back(cnt);
		g[cnt].push_back(node);
		ans.push_back(make_pair(node,cnt));
		left--;
		cnt++;
		go(cnt-1,levels-1);
	}
}

int main() {
	
	scanf("%d%d%d",&n,&d,&k);
	if (d > n-1){
		puts("NO");
		return 0;
	}
	for (int i = 1;i<=d;i++){
		g[i].push_back(i+1);
		g[i+1].push_back(i);
		ans.push_back(make_pair(i,i+1));
	}
	left = n - d - 1,cnt = d+2;
	for (int i = 2;i<=d;i++){
		int lev = min(i - 1,d-i+1);
		go(i,lev);
	}	
	if (left > 0){
		puts("NO");
		return 0;
	}
	int mx = 0;
	for (int i = 1;i<=n;i++){
		mx = max(mx,(int)g[i].size());
	}
	if (mx > k){
		puts("NO");
		return 0;
	}

	puts("YES");
	for (int i = 0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	
	return 0;
}