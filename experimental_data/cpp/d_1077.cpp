#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=1;char cc=getchar();
	while(cc<'0' || cc>'9') {if(cc=='-') f=-1;cc=getchar();}
	while(cc>='0' && cc<='9') {x=x*10+cc-'0';cc=getchar();}
	return x*f;
}

int n,k,m,s[200020],a[200020],l,r;

int main(){
	n=read();k=read();
	for(int i=1;i<=n;i++) s[read()]++;
	for(int i=1;i<=200000;i++) if(s[i]) m=i;
	l=1;r=n/k;
	while(l<r){
		int mid=((l+r)>>1)+1;
		int tmp=0;
		for(int i=1;i<=m;i++) tmp+=s[i]/mid;
		if(tmp>=k) l=mid;else r=mid-1;
	}
	int tmp=0;
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=s[i]/l;j++){
			tmp++;printf("%d ",i);
			if(tmp==k) return 0;
		}
	}
}