#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 300005
#define M 15000005
using namespace std;
#define _(d) while(d((ch=getchar()-48)>=0))
int get(){
	char ch;_(!);int v=ch;_() v=(v<<1)+(v<<3)+ch;return v;
}
int n,a[N],tot,p[M],s[M],r[M],ans;
bool f[M];
void pre(int lim){
	for(int i=2;i<=lim;i++){
		if(!f[i]) p[++tot]=i,r[i]=i;
		for(int j=1;j<=tot;j++){
			if(i*p[j]>lim) break;
			f[i*p[j]]=1;
			r[i*p[j]]=p[j];
			if(!(i%p[j])) break;
		}
	}
}
void divide(int x){
	while(x>1){
		s[r[x]]++;
		for(int t=r[x];!(x%t);x/=t);
	}
}
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
int main(){
	pre(15000000);
	n=get();
	int tmp=0;
	for(int i=1;i<=n;i++) a[i]=get(),tmp=gcd(tmp,a[i]);
	for(int i=1;i<=n;i++) divide(a[i]/tmp);
	for(int i=1;i<=tot;i++) ans=max(ans,s[p[i]]);
	if(!ans) puts("-1");
	else printf("%d\n",n-ans);
	return 0;
}