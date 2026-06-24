#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int N=100005,M=100005;
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int sum,b[N],k,n,len,m,i,ll,rr,qian[N],hou[N];
long long tong[N],a[N],c[N],kind,an[N];
map<long long,int>Ma;
struct data{
	int l,r,id,num;
}q[M];
inline void del1(int p){
	tong[a[p]]--;
	if(hou[a[p]])kind-=tong[hou[a[p]]];
}
inline void del2(int p){
	tong[a[p]]--;
	if(qian[a[p]])kind-=tong[qian[a[p]]];
}
inline void ins1(int p){
	if(hou[a[p]])kind+=tong[hou[a[p]]];
	tong[a[p]]++;
}
inline void ins2(int p){
	if(qian[a[p]])kind+=tong[qian[a[p]]];
	tong[a[p]]++;
}
inline bool cmp(data a,data b){
	return a.id<b.id||(a.id==b.id&&a.r<b.r);
}
int main(){
	n=read(); k=read(); len=sqrt(n);
	for(i=1;i<=n;i++)b[i]=read();
	for(i=1;i<=n;i++)c[i]=a[i]=read()*(b[i]==1?1:-1)+a[i-1];
	sort(&c[1],&c[n+1]); c[0]=c[1]-1;
	for(i=1;i<=n;i++){
		if(c[i]!=c[i-1]){
			Ma[c[i]]=++sum;
		}
	}
	for(i=1;i<=n;i++){
		qian[Ma[c[i]]]=Ma[c[i]-k];
		hou[Ma[c[i]]]=Ma[c[i]+k];
		a[i]=Ma[a[i]];
	}
	hou[0]=Ma[k];
	m=read();
	for(i=1;i<=m;i++){
		q[i].l=read(); q[i].r=read();
		q[i].id=q[i].l/len; q[i].num=i;
	}
	sort(&q[1],&q[m+1],cmp);
	ll=q[1].l; rr=q[1].l-1;
	for(i=1;i<=m;i++){
		while(ll>q[i].l)ins1(--ll);
		while(rr<q[i].r)ins2(++rr);
		while(ll<q[i].l)del1(ll++);
		while(rr>q[i].r)del2(rr--);
		an[q[i].num]=kind+tong[hou[a[ll-1]]];
	}
	for(i=1;i<=m;i++)writeln(an[i]);
}