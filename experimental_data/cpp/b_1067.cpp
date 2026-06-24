#include <bits/stdc++.h>
using namespace std;

int n , ver[100010] , nxt[200010] , to[200010] , tot;
void addedge(int from , int t){
	nxt[++tot] = ver[from];
	to[tot] = t;
	ver[from] = tot;
}

int q[100010] , l , r;
int d[100010] , pre[100010];
int bfs(int o){
	l = r = 0;
	q[r++] = o;
	for(int i = 1 ; i <= n ; i++)
		d[i] = -1;
	d[o] = 0;pre[o] = -1;
	while(l < r){
		int now = q[l++];
		for(int i = ver[now] ; i ; i = nxt[i]){
			if(d[to[i]] == -1){
				pre[to[i]] = now;
				d[to[i]] = d[now] + 1;
				q[r++] = to[i];
			}
		}
	}
	return q[r - 1];
}

bool dfscheck(int o , int fa , int k){
	if(k == 0){
		int deg = 0;
		for(int i = ver[o] ; i ; i = nxt[i]){
			if(to[i] == fa)continue;
			deg++;
		}
		if(deg == 0)return true;
		return false;
	}

	int deg = 0;
	for(int i = ver[o] ; i ; i = nxt[i]){
		if(to[i] == fa)continue;
		deg++;
		if(!dfscheck(to[i], o, k - 1))return false;
	}
	if(deg < 3)
		return false;
	return true;
}

int main(){
	int k;
	scanf("%d%d" , &n , &k);
	for(int i = 1 ; i < n ; i++){
		int u , v;scanf("%d%d" , &u , &v);
		addedge(u , v);
		addedge(v , u);
	}

	int u = bfs(1);
	int v = bfs(u);
	if(d[v] % 2 != 0){
		puts("No");
		return 0;
	}

	int center = v;
	for(int i = 1 ; i <= d[v] / 2 ; i++)
		center = pre[center];

	if(dfscheck(center, -1, k))
		puts("Yes");
	else
		puts("No");
	return 0;
}