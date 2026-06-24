#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M=2e7+5,JYY=998244353;

int max(int x,int y){ return x>y?x:y; }
int min(int x,int y){ return x<y?x:y; }

int read(){
	int x=0,y=1;char ch=getchar();
	while(ch<'0'||ch>'9') y=(ch=='-')?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*y;
}

void solve(){
	int n=read(),d=read(),mn1=1e9,mn2=1e9,mx=0;
	for(int i=1;i<=n;i++){
		int x=read();mx=max(mx,x);
		if(x<=mn1) mn2=mn1,mn1=x;
		else mn2=min(mn2,x);
	}
	if(mn1+mn2<=d||mx<=d) printf("YES\n");
	else printf("NO\n");
}

signed main(){
	int T=read();
	while(T--) solve();
}