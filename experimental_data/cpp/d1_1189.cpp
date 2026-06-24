#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 100010
using namespace std;

int read(){
	int x=0;char a=getchar();
	while(a>'9'||a<'0') a=getchar();
	while(a>='0'&&a<='9') x=(x<<1)+(x<<3)+a-48,a=getchar();
	return x;
}

int deg[N];
int u,v,n;

int main(){
	n=read();
	for(int i=1;i<n;i++){
		u=read(),v=read();
		++deg[u],++deg[v];
	}

	bool flag=true;
	for(int i=1;i<=n;i++){
		if(deg[i]==2) flag=false;
	}

	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}