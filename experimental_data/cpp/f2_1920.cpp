#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;const int N=6e5+3;
int n,m,T,f[N],ans[N],dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};vector<char>ch[N];
struct Pair{int x,y;};struct Nod{int x,y,z;};vector<Nod>cur;set<int>Q[N];vector<int>dis[N];
bool Ok(int x,int y){return x>0&&x<=n&&y>0&&y<=m;}
int Num(int x,int y,int z){return z*(n*m)+(x-1)*m+y;}
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
void Merge(int x,int y,int z){
	if((x=F(x))==(y=F(y)))return;
	if(Q[x].size()<Q[y].size())swap(x,y);
	for(int id:Q[y]){
		if(Q[x].count(id))ans[id]=z,Q[x].erase(id);
		else Q[x].insert(id);
	}
	f[y]=x;Q[y].clear();
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>T;int kx=0,ky=0;queue<Pair>q;
	for(int i=1;i<=n;i++)ch[i].resize(m+1),dis[i].resize(m+1),fill(dis[i].begin(),dis[i].end(),1e9);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		cin>>ch[i][j];
		if(ch[i][j]=='v')dis[i][j]=0,q.push({i,j});
		if(ch[i][j]=='#')kx=i,ky=j;
	}
	for(int i=1,x,y;i<=T;++i)cin>>x>>y,Q[Num(x,y,0)].insert(i),Q[Num(x,y,1)].insert(i);
	while(!q.empty()){
		Pair t=q.front();q.pop();
		for(int i=0;i<4;++i){
			int x=t.x+dx[i],y=t.y+dy[i];
			if(Ok(x,y)&&dis[t.x][t.y]+1<dis[x][y])dis[x][y]=dis[t.x][t.y]+1,q.push({x,y});
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)for(int k=0;k<=1;++k){
		int x=i+dx[k],y=j+dy[k];
		if(!Ok(x,y)||ch[i][j]=='#'||ch[x][y]=='#')continue;
		int op=i==kx&&x==kx-1&&y>ky,val=min(dis[i][j],dis[x][y]);
		cur.pb({Num(i,j,0),Num(x,y,op),val});cur.pb({Num(i,j,1),Num(x,y,op^1),val});
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)for(int k=0;k<=1;++k)f[Num(i,j,k)]=Num(i,j,k);
	sort(cur.begin(),cur.end(),[&](Nod a, Nod b){return a.z>b.z;});
	for(Nod t:cur)Merge(t.x,t.y,t.z);
	for(int i=1;i<=T;++i)cout<<ans[i]<<endl;
}