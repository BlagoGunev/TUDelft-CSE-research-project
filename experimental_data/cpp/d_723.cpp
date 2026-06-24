#include <cstdio>

#include <algorithm>

using namespace std;

int const inf=1000000000;

bool vis[55][55];

int id[55][55];

int n,m,k,nid=0;

char G[55][55];

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int c=0;

int dfs(int x,int y) {

	vis[x][y]=true;

	id[x][y]=nid;

	int siz=1;

	for (int i=0;i<4;i++) {

		int x2=x+dx[i],y2=y+dy[i];

		if (x2<1||x2>n||y2<1||y2>m) {

			siz=inf;

			continue;

		}

		else if (G[x2][y2]=='.'&&!vis[x2][y2]) {

			int tmp=dfs(x2,y2);

			if (tmp==inf||siz==inf) siz=inf; else siz+=tmp;

		}

	}

	return siz;

}

pair<int,int> t[2505];

int d=0;

int main() {

	scanf("%d%d%d",&n,&m,&k);

	for (int i=1;i<=n;i++) scanf("%s",G[i]+1);

	for (int i=1;i<=n;i++) {

		for (int j=1;j<=m;j++) {

			if (G[i][j]=='.'&&!vis[i][j]) {

				++nid;

				int tmp=dfs(i,j);

				if (tmp!=inf) c++;

				t[++d]=make_pair(tmp,nid);

			}

		}

	}

	sort(t+1,t+1+d);

	int g=c-k,ans=0;

	for (int p=1;p<=g;p++) {

		int siz=0;

		ans+=t[p].first;

		bool ok=false;

		for (int i=1;i<=n;i++) {

			for (int j=1;j<=m;j++) {

				if (id[i][j]==t[p].second) {

					G[i][j]='*';

					if (++siz==t[p].first) {

						ok=true;

						break; 

					}

				}

			}

			if (ok) break;

		}

	}

	printf("%d\n",ans);

	for (int i=1;i<=n;i++) {

		printf("%s\n",G[i]+1);

	}

	return 0;

}