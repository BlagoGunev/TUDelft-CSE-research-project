#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXH = 3200;
const int MAX = 130;

int n, k, P[MAXN][5], perm[5], perm2[5], nperm[5], H[MAXN], code[MAXH], nxt[MAXN];
int nxt_perm[MAX][MAX];
vector <int> v, order, to_push;
bool vis[MAX];

vector <int> w;
void dfs(int u){
	to_push.push_back(u);
	vis[u] = true;
	for(int x : w){
		if(!vis[nxt_perm[u][x]]){
			dfs(nxt_perm[u][x]);
		}
	}
}

int main(){
	scanf("%d %d", &n, &k);
	
	int pi = 0;
	for(int i = 0; i < k; i++)
		perm[i] = i;
	
	do{
		int h = 0;
		for(int i = 0; i < k; i++)
			h = h * k + perm[i];
		code[h] = pi;
		pi++;
	}while(next_permutation(perm, perm + k));
	
	for(int i = 0; i < k; i++)
		perm[i] = i;

	do{
		int h1 = 0;
		for(int i = 0; i < k; i++)
			h1 = h1 * k + perm[i];
		
		for(int i = 0; i < k; i++)
			perm2[i] = i;
		do{
			int h2 = 0;
			for(int i = 0; i < k; i++)
				h2 = h2 * k + perm2[i];
				
			for(int i = 0; i < k; i++)
				nperm[i] = perm2[perm[i]];
			int hn = 0;
			for(int i = 0; i < k; i++)
				hn = hn * k + nperm[i];
				
			nxt_perm[code[h1]][code[h2]] = code[hn];
		}while(next_permutation(perm2, perm2 + k));
	}while(next_permutation(perm, perm + k));
	
	for(int i = 0; i < n; i++){
		int h = 0;
		for(int j = 0; j < k; j++){
			scanf("%d", &P[i][j]);
			P[i][j]--;
			
			h = h * k + P[i][j];
		}
		H[i] = code[h];
	}
	
	long long res = 0;
	for(int i = n - 1; i >= 0; i--){
		nxt[i] = i + 1;
		
		int j = nxt[i], prv = i;
		while(j != n){
			if(H[j] == H[i]){
				nxt[prv] = nxt[j];
				break;
			}else{
				prv = j;
				j = nxt[j];
			}
		}
			
		memset(vis, 0, sizeof vis);
		
		vis[0] = true;
		v.clear();
		v.push_back(0);
		w.clear();
		
		j = i;
		while(j != n){
			if(!vis[H[j]]){
				w.push_back(H[j]);
				order.clear();
				
				int cur = H[j];
				while(true){
					if(cur == 0)break;
					if(!vis[cur])order.push_back(cur);
					
					cur = nxt_perm[cur][H[j]];
				}
				
				to_push.clear();
				for(int x : v){
					for(int y : order){
						if(!vis[nxt_perm[x][y]])dfs(nxt_perm[x][y]);
					}
				}
				for(int x : to_push){
					v.push_back(x);
					vis[x] = true;
				}
				
			}
			
			res += 1LL * v.size() * (nxt[j] - j);
			j = nxt[j];
		}
		
	}
	printf("%lld\n", res);
	
	return 0;
}