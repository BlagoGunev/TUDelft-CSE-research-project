#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
const int N=100010;
inline int gcd(int a,int b){
	int r=a%b;
	while (r) a=b,b=r,r=a%b;
	return b;
} 
int main(){
	int n=read(),k=read(),now=k;
	for (int i=1;i<=n;++i){
		int x=read();
		now=gcd(now,x);
	}
	int ans=k/now;
	printf("%d\n",ans);
	for (int i=0;i<ans;++i) printf("%d ",i*now);
	return 0;
}