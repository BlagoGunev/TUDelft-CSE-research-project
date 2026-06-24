#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define LL long long
const int MAX = 5e5 + 20;
int INF = 1e8;
int a[MAX];
int vis[MAX];
int c[MAX];
int head[MAX];

int k = 0;
struct Edge
{
	int to;
	int next;
} edge[MAX * 2];

void add(int a, int b){
	edge[k].to = b;
	edge[k].next = head[a];
	head[a] = k++;
}

int cnt = 0;
void dfs(int rt, int v){
	vis[rt] = 1;
	c[rt] = v;
	cnt += v;
	for(int i = head[rt]; i != -1; i = edge[i].next){
		int to = edge[i].to;
		if(vis[to]){
			continue;
		}
		dfs(to, v ^ 1);
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);

	while(t--){
		k = 0;
		cnt = 0;
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++){
			head[i] = -1;
			vis[i] = c[i] = 0;
		}
		for(int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b);
			add(b, a);
		}

		dfs(1, 1);
		//printf("cnt = %d\n", cnt);
		if(cnt <= n / 2){
			printf("%d\n", cnt);
			//printf("888\n");
			for(int i = 1; i <= n; i++){
				if(c[i]){
					printf("%d ", i);
				}
			}
			printf("\n");
		} else{
			printf("%d\n", n - cnt);
			for(int i = 1; i <= n; i++){
				if(c[i] == 0){
					printf("%d ", i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}