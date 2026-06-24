#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int N = 105;


int n, m;
char mat[N][N];
vector<ii> ans[3];

void solve(vector<ii> v){
	int cnt = 0;
	for(auto x : v){
		cnt += mat[x.ff][x.ss];
	}
	if(cnt == 0) return;
	if(cnt == 3){
		for(auto x : v){
			if(mat[x.ff][x.ss]){
				////cerr << "!!" << endl;
				ans[cnt-1].pb(x);
				mat[x.ff][x.ss] ^= 1;
				cnt--;
			}
		}
		return;
	}
	else if(cnt == 2){
		int cnt1 = 1;
		int cnt0 = 2;
		int id = 0;
		for(auto x : v){
			if(mat[x.ff][x.ss] == 1 && cnt1){
				ans[id].pb(x);
				mat[x.ff][x.ss] ^= 1;
				id++;
				cnt1--;
			}
			else if(mat[x.ff][x.ss] == 0 && cnt0){
				ans[id].pb(x);
				mat[x.ff][x.ss] ^= 1;
				id++;
				cnt0--;
			}
		}
	}
	else if(cnt == 1){
		int cnt1 = 1;
		int cnt0 = 2;
		int id = 0;
		for(auto x : v){
			if(mat[x.ff][x.ss] == 1 && cnt1){
				ans[id].pb(x);
				mat[x.ff][x.ss] ^= 1;
				id++;
				cnt1--;
			}
			else if(mat[x.ff][x.ss] == 0 && cnt0){
				ans[id].pb(x);
				mat[x.ff][x.ss] ^= 1;
				id++;
				cnt0--;
			}
		}
	}
	else if(cnt == 4){
		cnt = 3;
		for(auto x : v){
			if(mat[x.ff][x.ss] && cnt >= 1){
				//cerr << x.ff << " " << x.ss << endl;
				ans[cnt-1].pb(x);
				mat[x.ff][x.ss] ^= 1;
				cnt--;
			}
		}
	}
	solve(v);
}	

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		ans[0].clear();
		ans[1].clear();
		ans[2].clear();
		for(int i = 0; i < n; i++){
			scanf("%s", mat[i]);
			for(int j = 0; j < m; j++){
				mat[i][j] -= '0';
			}
		}
		for(int i = 0; i < n-2; i++){
			for(int j = 0; j < m-1; j += 2){
				if(mat[i][j] == 1 && mat[i][j+1] == 1){
					ans[0].pb({i, j});
					ans[1].pb({i, j+1});
					ans[2].pb({i+1, j});
					mat[i][j] ^= 1;
					mat[i][j+1] ^= 1;
					mat[i+1][j] ^= 1;
				}
				else if(mat[i][j] == 1){
					ans[0].pb({i, j});
					ans[1].pb({i+1, j+1});
					ans[2].pb({i+1, j});
					mat[i][j] ^= 1;
					mat[i+1][j+1] ^= 1;
					mat[i+1][j] ^= 1;
				}
				else if(mat[i][j+1] == 1){
					ans[0].pb({i, j+1});
					ans[1].pb({i+1, j+1});
					ans[2].pb({i+1, j});
					mat[i][j+1] ^= 1;
					mat[i+1][j+1] ^= 1;
					mat[i+1][j] ^= 1;
				}
			}
			if(m%2){
				int j = m-2;
				if(mat[i][j] == 1 && mat[i][j+1] == 1){
					ans[0].pb({i, j});
					ans[1].pb({i, j+1});
					ans[2].pb({i+1, j});
					mat[i][j] ^= 1;
					mat[i][j+1] ^= 1;
					mat[i+1][j] ^= 1;
				}
				else if(mat[i][j] == 1){
					ans[0].pb({i, j});
					ans[1].pb({i+1, j+1});
					ans[2].pb({i+1, j});
					mat[i][j] ^= 1;
					mat[i+1][j+1] ^= 1;
					mat[i+1][j] ^= 1;
				}
				else if(mat[i][j+1] == 1){
					ans[0].pb({i, j+1});
					ans[1].pb({i+1, j+1});
					ans[2].pb({i+1, j});
					mat[i][j+1] ^= 1;
					mat[i+1][j+1] ^= 1;
					mat[i+1][j] ^= 1;
				}
			}
		}
		int i = n-2;
		for(int j = 0; j < m-1; j++){
			if(mat[i][j] == 1 && mat[i+1][j] == 1){
				ans[0].pb({i, j});
				ans[1].pb({i+1, j});
				ans[2].pb({i+1, j+1});
				mat[i][j] ^= 1;
				mat[i+1][j] ^= 1;
				mat[i+1][j+1] ^= 1;
			}
			else if(mat[i][j] == 1){
				ans[0].pb({i, j});
				ans[1].pb({i+1, j+1});
				ans[2].pb({i, j+1});
				mat[i][j] ^= 1;
				mat[i+1][j+1] ^= 1;
				mat[i][j+1] ^= 1;
			}
			else if(mat[i+1][j] == 1){
				ans[0].pb({i, j+1});
				ans[1].pb({i+1, j+1});
				ans[2].pb({i+1, j});
				mat[i][j+1] ^= 1;
				mat[i+1][j+1] ^= 1;
				mat[i+1][j] ^= 1;
			}
		}
		int j = m-2;
		solve(vector<ii>({{i, j}, {i, j+1}, {i+1, j}, {i+1, j+1}}));
		printf("%d\n", (int)ans[0].size());
		assert((int)ans[0].size() <= n * m);
		for(int i = 0; i < (int)ans[0].size(); i++){
			printf("%d %d %d %d %d %d\n", ans[0][i].ff+1, ans[0][i].ss+1, ans[1][i].ff+1, ans[1][i].ss+1, ans[2][i].ff+1, 1+ans[2][i].ss);
		}
	}
	return 0;
}