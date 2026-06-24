#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int MAXN=300000;

int n,m,p[MAXN+1];
vector<int> e[MAXN+1]; 
int chk[MAXN+1];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[v].push_back(u);
	}
	
	int idx=1;
	for(int i=1;i<=n;i++) chk[i]=0;
	for(auto x:e[p[n]]) chk[x]=1;
	
	int ans=0;
	for(int i=n-1;i>=1;i--){
		if(chk[p[i]]==idx){
			ans++;
			continue;
		}else{
			for(auto x:e[p[i]])
				if(chk[x]==idx)
					chk[x]=idx+1;
			idx++;
		}
	}
	printf("%d\n",ans);
}