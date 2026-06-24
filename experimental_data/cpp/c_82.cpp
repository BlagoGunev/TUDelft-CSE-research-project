#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#define MAXN 5003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n;
vector<pii> edge[MAXN];
int p[MAXN], fa[MAXN], cap[MAXN];
pii ppl[MAXN];
int pos[MAXN], cur[MAXN], key[MAXN];

void dfs(int u, int p) {
	fa[u]=p;
	for(int i=edge[u].size()-1; i>=0; --i) {
		int v=edge[u][i].first;
		if(v!=p) {
			dfs(v, u);
			cap[v]=edge[u][i].second;
		}
	}
}

struct LIST {
	int id;
	LIST *pre, *next;
}ls[MAXN];

void process() {
	dfs(1, -1);
	cap[1]=0;

	memset(key, 0, sizeof(key));
	int sz=n-1, t=0;
	while(sz) {
		++t;
		for(int i=1; i<=n; ++i) {
			cur[i]=cap[i];
		}

		for(LIST *pp=ls[0].next; pp; pp=pp->next) {
			int u=pp->id;
			int &p=pos[u];
			if(fa[p]!=-1 && cur[p]) {
				--cur[p];
				p=fa[p];
				if(fa[p]==-1) {
					key[u]=t;
					pp->pre->next=pp->next;
					if(pp->next) {
						pp->next->pre=pp->pre;
					}
					--sz;
				}
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("in", "r", stdin);
#endif

    int u, v, c;
    while(scanf("%d", &n)!=EOF) {
    	for(int i=1; i<=n; ++i) {
    		scanf("%d", &p[i]);
    		ppl[i]=make_pair(p[i], i);
    		edge[i].clear();
    		pos[i]=i;
    	}
    	sort(ppl+1, ppl+1+n);

    	for(int i=1; i<=n; ++i) {
    		ls[i].next=&ls[i+1];
    		ls[i].pre=&ls[i-1];
    		ls[i].id=ppl[i].second;
    	}
    	ls[0].next=&ls[1];
    	ls[n].next=NULL;

    	for(int i=1; i<n; ++i) {
    		scanf("%d %d %d", &u, &v, &c);
    		edge[u].push_back( make_pair(v, c) );
    		edge[v].push_back( make_pair(u, c) );
    	}

    	process();

    	printf("%d", key[1]);
    	for(int i=2; i<=n; ++i) {
    		printf(" %d", key[i]);
    	}
    	putchar(10);
    }

    return 0;
}