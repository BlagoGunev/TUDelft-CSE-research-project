#include<bits/stdc++.h> 

using namespace std;



const int maxn = 65536 + 10;

int n;

int deg[maxn], sum[maxn];

queue<int> que;



int main(){

	cin >> n;

	int tot = 0;

	for(int i = 0; i < n; i++){

		scanf("%d%d", &deg[i], &sum[i]);

		tot += deg[i];

		if(deg[i] == 1) que.push(i);

	}

	printf("%d\n", tot/2);

	while(!que.empty()){

		int u = que.front(), v = sum[u]; que.pop();

		if(deg[u] != 1 || !deg[v]) continue;

		printf("%d %d\n", u, v);

		sum[v] ^= u; deg[v]--; deg[u]--;

		if(deg[v] >= 1) que.push(v);

	}

	return 0;

}