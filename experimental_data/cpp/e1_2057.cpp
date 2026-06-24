#include<bits/stdc++.h>
using namespace std;
int n,m,q,d[444][444][444],e[444][444],u[444],v[444],w[444],o[444];
vector<int>E[444]; 
void doing(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) E[i].clear();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		o[i]=w[i];
		E[u[i]].push_back(v[i]);
		E[v[i]].push_back(u[i]);
	}
	sort(o+1,o+m+1);
	int V=unique(o+1,o+m+1)-o-1;
	for(int i=1;i<=m;i++) w[i]=lower_bound(o+1,o+V+1,w[i])-o;
	for(int i=1;i<=m;i++) e[u[i]][v[i]]=e[v[i]][u[i]]=w[i];
	for(int i=1;i<=V;i++){
		for(int j=1;j<=n;j++){
			deque<int>q;
			for(int k=1;k<=n;k++) d[i][j][k]=1e9;
			d[i][j][j]=0;
			q.push_back(j);
			while(q.size()){
				int x=q.front();
				q.pop_front();
				for(int k:E[x]){
					if(e[x][k]>=i){
						if(d[i][j][k]>d[i][j][x]+1){
							d[i][j][k]=d[i][j][x]+1;
							q.push_back(k);
						}
					}
					else{
						if(d[i][j][k]>d[i][j][x]){
							d[i][j][k]=d[i][j][x];
							q.push_front(k);
						}
					}
				}
			}
		}
	}
	for(int i=1,u,v,k;i<=q;i++){
		scanf("%d %d %d",&u,&v,&k);
		int l=1,r=V,mid;
		while(l<r){
			mid=l+r+1>>1;
			if(d[mid][u][v]>=k) l=mid;
			else r=mid-1;
		}
		printf("%d\n",o[l]);
	}
	
}
int main(){
	int T;
	cin>>T;
	while(T--) doing();
}