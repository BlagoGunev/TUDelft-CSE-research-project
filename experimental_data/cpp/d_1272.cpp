#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int M=2e5+5;

int n,ans=0,a[M],nxt[M],last[M];

int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	last[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) last[i]=last[i-1];
		else last[i]=i;
		ans=max(ans,i-last[i]+1);
	}
	nxt[n]=n;
	for(int i=n-1;i>=1;i--){
		if(a[i]<a[i+1]) nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	for(int i=1;i<=n-2;i++){
		if(a[i]<a[i+2]){
			ans=max(ans,(i-last[i]+1)+(nxt[i+2]-i-2+1));
		}
	}
	printf("%d\n",ans);
}