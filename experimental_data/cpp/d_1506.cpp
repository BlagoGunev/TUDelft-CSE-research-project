#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
template<class T>
inline void read(T &x){
	x=0; int sign=1; char c;
	do{c=getchar(); if(c=='-') sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0',c=getchar();}while(isdigit(c));
	x*=sign;
}
int t,n,a[200005];
int main(){
	read(t);
	while(t--){
		read(n);
		for(int i=0;i<n;++i) read(a[i]);
		sort(a,a+n);
		int ans=n,cnt=0,pos=-1;
		for(int i=0,j=n-1;i<j;i++,j--) if(a[i]==a[j]){
			pos=i;
			break;
		}
		for(int i=0,j=n-1;i<j;i++,j--){
			if(a[i]!=a[j]){
				if(pos!=-1&&a[i]!=a[pos]&&a[j]!=a[pos]) cnt++;
				if(pos==-1) cnt++;
				ans-=2;
			}
			else if(cnt) cnt--,ans-=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}