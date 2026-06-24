#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N=3e5+7;
int n,m,a[N],fa[N],i,t,l,r,x,x1,u1,u;
long long w[N],ans[N];
priority_queue<pair<int,int>>q;
vector<pair<int,int>> tmp,vc[N];
vector<int> vc1[N];
int find(int x){
    if(x==fa[x]) return x;
    int t=find(fa[x]);
    if(t!=fa[x]) w[x]+=w[fa[x]];
    return fa[x]=t;
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        w[x]-=w[y];
        fa[x]=y;
    }
}
int main(){
    cin>>n;
	for(i=1;i<=n;++i) cin>>a[i];
	cin>>m;
	for(i=1;i<=m;++i){
        fa[i]=i;
        cin>>l>>r>>x;
        vc1[l].push_back(i);
        vc[r].push_back(pair<int,int>(x,i));
	}
	for(i=n;i;--i){
		for(auto j:vc[i]) q.push(j);
		x1=2e9;
		u1=0;
		tmp.clear();
		while(!q.empty()){
			auto [x,u]=q.top();
			if(x<=a[i]) break;
			q.pop();
			w[find(u)]+=1LL*(x-a[i]+1)/2*i;
			x=(x+a[i])/2;
			if(x<x1){
                tmp.push_back(pair<int,int>(x,u));
                x1=x;
                u1=u;
                }
            else merge(u,u1);
		}
		for(auto j:tmp) q.push(j);
		for(auto j:vc1[i]){
            t=find(j);
            ans[j]=j==t?w[t]:w[j]+w[t];
		}
	}
	for(i=1;i<=m;++i) cout<<ans[i]<<'\n';
}