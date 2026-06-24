#include <bits/stdc++.h>
#include<bits/stdc++.h>
#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
using namespace std;

char gc() {
//	static char buf[100000],*p1,*p2;
//	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,100000,stdin))?EOF:*p1++;
	return getchar();
}

template<class T>
int read(T &ans) {
	T f=1;ans=0;
	char ch=gc();
	while(!isdigit(ch)) {
		if(ch==EOF) return EOF;
		if(ch=='-') f=-1;
		ch=gc();
	}
	while(isdigit(ch))
		ans=ans*10+ch-'0',ch=gc();
	ans*=f;return 1;
}

template<class T1,class T2>
int read(T1 &a,T2 &b) {
	return read(a)==EOF?EOF:read(b);
}

template<class T1,class T2,class T3>
int read(T1 &a,T2 &b,T3 &c) {
	return read(a,b)==EOF?EOF:read(c);
}

typedef long long ll;
const int Maxn=1100000;
const int inf=0x3f3f3f3f;
const ll mod=998244353;

ll n,m,k,x,zd,cd;

int main() {
	read(n,m,k);
	for(int i=1;i<=n;i++) {
		read(x);
		if(x>zd) cd=zd,zd=x;
		else qmax(cd,x);
	}
	x=m/(k+1);
	printf("%lld\n",zd*(m-x)+cd*x);
	return 0;
}