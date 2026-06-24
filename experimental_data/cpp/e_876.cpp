#include<bits/stdc++.h>
using namespace std;
#define pc(x) putchar(x)
namespace ib {char b[100];}
inline void pi(int x){
	if(x==0) {pc(48); return;}
	if(x<0) {pc('-'); x=-x;}
	char *s=ib::b;
	while(x) *(++s)=x%10,x/=10;
	while(s!=ib::b) pc((*(s--))+48);
}
inline void ri(int &x){
	x=0; static char c; bool t(0);
	while(c=getchar(),c<'0'||c>'9') if(c=='-') t=1; else t=0;
	do x=(x<<1)+(x<<3)+c-'0'; while(c=getchar(),c>='0'&&c<='9');
	if(t) x=-x;
}
const int N=300024;
vector<int> Q[N];
bool vis[N]; queue<int> J;
vector<int> ST[N];
int main(){
	//freopen("0.in","r",stdin);
	int i,j,n,m,l,x; ri(n); ri(m);
	ri(l); for(i=1;i<=l;++i){ri(x); ST[1].push_back(x);}
	for(i=2;i<=n;++i){
		ri(l); for(j=1;j<=l;++j){ri(x); ST[i].push_back(x);}
		int len=min(ST[i-1].size(),ST[i].size());
		for(j=0;j<len;++j) if(ST[i][j]!=ST[i-1][j]) break;
		if(j<len)
		if(ST[i-1][j]<ST[i][j]) Q[ST[i][j]].push_back(ST[i-1][j]);
		else{
			if(!vis[ST[i-1][j]]) vis[ST[i-1][j]]=1,J.push(ST[i-1][j]);
		}
		else if(ST[i-1].size()>ST[i].size()){puts("No"); return 0;}
	}
	while(!J.empty()){
		int x=J.front(); J.pop();
		for(j=0;j<Q[x].size();++j)
		if(!vis[Q[x][j]]){
			vis[Q[x][j]]=1;
			J.push(Q[x][j]);
		}
	}
	for(i=1;i<=n;++i)
	for(j=0;j<ST[i].size();++j) if(vis[ST[i][j]]) ST[i][j]-=200000;
	for(i=2;i<=n;++i){
		int len=min(ST[i-1].size(),ST[i].size());
		for(j=0;j<len;++j) if(ST[i-1][j]!=ST[i][j]) break;
		if(j<len&&ST[i-1][j]>ST[i][j]){
			puts("No"); return 0;
		}
	}
	puts("Yes");
	int gs=0;
	for(i=1;i<=m;++i) if(vis[i]) ++gs;
	cout<<gs<<endl;
	for(i=1;i<=m;++i) if(vis[i]) pi(i),pc(' ');
	return 0;
}