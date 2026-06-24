//Copyright(c)2016 liuchenrui
#include<bits/stdc++.h>
using namespace std;
inline void splay(int &v){
	v=0;char c=0;int p=1;
	while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
	v*=p;
}
vector<int>s[300010];
int a[300010],b[300010];
int n,m;
int main(){
	splay(n),splay(m);
	for(int i=1;i<=n;i++){
		splay(a[i]);b[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y;splay(x),splay(y);
		x=b[x],y=b[y];
		if(x>y)swap(x,y);
		s[y].push_back(x);
	}
	int l=0;long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i].size();j++){
			l=max(l,s[i][j]);
		}
		ans+=(long long)(i-l);
	}
	cout<<ans<<endl;
}