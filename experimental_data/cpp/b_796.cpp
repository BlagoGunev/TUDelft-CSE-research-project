#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 1123456
int w[N];
int h[N];
int s(int x){ return max(x,-x);}
int main(){
	int n=getint(),m=getint(),k=getint(); int z=1;
	for(int i=1;i<=m;i++) {
		int x=getint();
		h[x]=1;
	}
	for(int i=1;i<=k;i++){
		if(h[z]){
			printf("%d\n",z); return 0;
		}
		int x=getint(),y=getint();
		if(z==x) z=y; else if(z==y) z=x;
	}
	cout<<z<<endl;
}