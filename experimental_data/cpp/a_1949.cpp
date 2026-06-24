#include<bits/stdc++.h>
using namespace std;
constexpr int M=400;
double r;bool edge[M][M];
int cnt[M],posx[M],posy[M],idx[M][M];
int n,L,R,tot;vector<int>ans,cur;
void dfs(int x){
	if (cur.size()>ans.size()) ans=cur;
	for (int i=x+1;i<tot;i++){
		if (cnt[i]+cur.size()<=ans.size()) return;
		bool fl=1;
		for (auto x:cur)
			if (edge[x][i])
				{fl=0;break;}
		if (!fl) continue;
		cur.push_back(i);
		dfs(i);
		cur.pop_back();
	}
}
int main(){
	scanf("%d%lf",&n,&r);
	L=ceil(r);R=floor(n-r);
	for (int i=L;i<=R;i++)
		for (int j=L;j<=R;j++)
			posx[tot]=i,posy[tot]=j,
			idx[i][j]=tot++;
	for (int sx=L;sx<=R;sx++)
		for (int sy=L;sy<=R;sy++)
			for (int tx=L;tx<=R;tx++)
				for (int ty=L;ty<=R;ty++)
					edge[idx[sx][sy]][idx[tx][ty]]=(sx-tx)*(sx-tx)+(sy-ty)*(sy-ty)<r*r*4;
	for (int i=tot-1;~i;i--) cur.push_back(i),dfs(i),cur.pop_back(),cnt[i]=ans.size();
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%d %d\n",posx[ans[i]],posy[ans[i]]);
	return 0;
}