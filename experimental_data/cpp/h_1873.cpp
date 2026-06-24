#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>g[N];
int de[N];
int n,a,b;
void top(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(de[i]==1)q.push(i);
	}
	while(q.size()){
		int id=q.front();
		q.pop();
		for(auto c:g[id]){
			if(de[c]>1){
				de[c]--;
				if(de[c]==1)q.push(c);
			}
		}
	}
}
void bfs(vector<int>&d,int x){
	fill(d.begin(),d.end(),-1);
	d[x]=0;
	queue<int>q;
	q.push(x);
	while(q.size()){
		int id=q.front();
		q.pop();
		for(auto c:g[id]){
			if(d[c]==-1){
				d[c]=d[id]+1;
				q.push(c);
			}
		}
	}
}
void solve(){
	cin>>n>>a>>b;
	memset(de,0,sizeof de);
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		de[x]++;
		de[y]++;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	top();
	vector<int>circle;
	for(int i=1;i<=n;i++){
		if(de[i]>=2)circle.push_back(i);
	} 
	vector<int>da(n+1);
	vector<int>db(n+1);
	bfs(da,a);
	bfs(db,b);
	int f=0;
	for(int i=0;i<circle.size();i++){
		if(da[circle[i]]>db[circle[i]]){
			f=1;
			break;
		}
	}
	if(f){
		cout<<"YES\n";
	}else{
		cout<<"NO\n"; 
	}
	for(int i=1;i<=n;i++)g[i].clear();
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	for(int i=1;i<=t;i++)solve();
	return 0;
}