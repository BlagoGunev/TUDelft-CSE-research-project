#include <bits/stdc++.h>
#define N 800015
using namespace std;
const int o=200005;
int n,pos_a[N],pos_b[N],cnt;
struct node{
	int a,b,u,v,w,id;
	node(int A,int B,int U=0,int V=0,int W=0){ a=A,b=B,u=U,v=V,w=W; }
};
queue<int> q;
vector<node> ans,cc;
bool tag[N];
int to(int x){ return o+o-x; }
bool cmp(node x,node y){ 
	return abs(x.a-o)==abs(y.a-o)?abs(x.b-o)<abs(y.b-o):abs(x.a-o)<abs(y.a-o);
}
void print(int x){
	if(cc[x].u==0) cout<<cc[x].a-o<<' '<<cc[x].b-o<<'\n';
	else print(cc[x].u),print(cc[x].v),print(cc[x].w);
}
int main(){
	cin>>n;
	int x,y; cc.push_back(node(0,0));
	for(int i=1;i<=n+n;i++){
		cin>>x>>y; x+=o,y+=o;
		++cnt,cc.push_back(node(x,y)); pos_a[x]=i,pos_b[y]=i;
		cc[i].id=i;
		if((x<o&&o<y)||(y<o&&o<x)) q.push(i);
	}
	while(!q.empty()){
		x=q.front(); q.pop();
		if(tag[x]) continue;
		int u=pos_a[to(cc[x].a)],v=pos_b[to(cc[x].b)];
		if(u==v){ cout<<"NO"; return 0; }
		if(cc[x].a>o) ++cnt,cc.push_back(node(cc[v].a,cc[u].b,v,x,u));
		else ++cnt,cc.push_back(node(cc[v].a,cc[u].b,u,x,v));
		tag[v]=tag[u]=tag[x]=1; 
		pos_a[cc[cnt].a]=cnt,pos_b[cc[cnt].b]=cnt;
		cc[cnt].id=cnt;
		if((cc[cnt].a<o&&o<cc[cnt].b)||(cc[cnt].b<o&&o<cc[cnt].a)) 
			q.push(cnt);
	}
	for(int i=1;i<=cnt;i++) if(!tag[i]) ans.push_back(cc[i]);
	sort(&ans[0],&ans[ans.size()],cmp);
	for(int i=0;i<ans.size();i+=2){
		if(ans[i].a!=to(ans[i+1].a)||ans[i].b!=to(ans[i+1].b)){ cout<<"NO"; return 0; }
		if(ans[i].a<o&&ans[i].b>o){ cout<<"NO"; return 0; }
		if(ans[i].a>o&&ans[i].b<o){ cout<<"NO"; return 0; }
		if(ans[i].a<o) swap(ans[i],ans[i+1]);
	}
	cout<<"YES\n";
	for(int i=0;i<ans.size();i++) print(ans[i].id);
}