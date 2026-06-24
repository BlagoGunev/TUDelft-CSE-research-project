//Wrong answer on test inf.
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define inf 1000000001
#define y1 y1___
using namespace std;
char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
ll read(){
	char ch=gc();ll x=0;int op=1;
	for (;!isdigit(ch);ch=gc()) if (ch=='-') op=-1;
	for (;isdigit(ch);ch=gc()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}
#define N 100005
int n,a[N],b[N];ll suma,sumb,A,B;
int main(){
	n=read();
	rep (i,1,n) suma+=(a[i]=read());sort(&a[1],&a[n+1],greater<int>());
	rep (i,1,n) sumb+=(b[i]=read());sort(&b[1],&b[n+1],greater<int>());
	// A=suma;B=sumb;
	A=suma,B=sumb;
	int x=1,y=1;
	while (x<=n||y<=n){
		if (!((x+y)&1)){
			if (x<=n&&a[x]>b[y]) x++;else B-=b[y++];
		} else{
			if (x<=n&&a[x]>b[y]) A-=a[x++];else y++;
		}
	}
	cout<<A-B<<'\n';
	return 0;
}