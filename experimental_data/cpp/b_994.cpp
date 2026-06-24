#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
#define ll long long
struct node{
	int p, c, id;
}a[N];
int n, k;
ll ans[N], tot;
priority_queue<int, vector<int>, greater<int>> heap;
bool cmp(node x, node y){ return x.p < y.p; }
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	  scanf("%d", &a[i].p);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i].c);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		heap.push(a[i].c);
		tot += a[i].c;
		ans[a[i].id] = tot;
		if(heap.size() > k){ tot -= heap.top(); heap.pop(); }
	}
	for(int i = 1; i <= n; i++)
	  printf("%lld ", ans[i]);
	puts("");
	return 0;
}