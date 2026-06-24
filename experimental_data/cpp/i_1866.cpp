#include"bits/stdc++.h"
using namespace std;
const int maxn = 200010;
vector<int>L[maxn];
int n,m,q,W;
set<int,greater<int> >s;
int main(){
	cin>>n>>m>>q;
	if(n==1&&m==1)puts("Bhinneka"),exit(0);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y,L[x].push_back(y);
		if(min(x,y)==1)puts("Chaneka"),exit(0);
	}
	L[n].push_back(m);
	for(int i=1;i<=m;i++)s.insert(i);
	for(int i=n;i>=1;i--){
		if(s.empty())break;
		if(!L[i].empty()){
			sort(L[i].begin(),L[i].end(),greater<int>() );
			W=L[i][0];
		}else W=0;
		if(*s.begin()>W){
			if(i==1&&*s.begin()==1)break;
			W=*s.begin(),s.erase(s.begin());
		}
		for(int j=0;j<L[i].size();j++)
			if(s.find(L[i][j])!=s.end())
				s.erase(L[i][j]);
	}
	if(s.find(1)==s.end()||W)puts("Chaneka");
	else puts("Bhinneka");
}