#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define clr(x,y) memset(x,y,sizeof(x))
#define down(i,l,r) for (int i=l;i>=r;i--)
#define pb push_back
#define inf (int)1e9
#define maxn 2005000
using namespace std;
int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
map<int,int> mp;
int a,b,d;
void get(){
	a=read(); b=read();
	d=__gcd(a,b);
	a/=d; b/=d;
	if (d==1){
		if (a==1&&b==1) puts("Yes");
		else puts("No");
		return ;
	}
	if (d%a||d%b) puts("No");
	else {
		d=d/a; d=d/b;
		if (mp[d]) puts("Yes");
		else puts("No");
	}
}
int main(){
	rep(i,1,1000){
		int x=i*i*i;
		mp[x]=1;
	}
	int n=read();
	rep(i,1,n) get();

	
	return 0;
}