#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<bitset>
#define ll long long
#define ui unsigned int
//#define d double
#define ull unsigned long long
using namespace std;
const int maxn=100233;
int val[maxn],mx[maxn<<2],add[maxn<<2];
int i,j,k,n,m;int L,R,ADD;

int ra,fh;char rx;
inline int read(){
	rx=getchar(),ra=0,fh=1;
	while(rx<'0')rx=='-'&&(fh=-1),rx=getchar();
	while(rx>='0')ra=ra*10+rx-48,rx=getchar();return ra*fh;
}
inline int max(int a,int b){return a>b?a:b;}
inline void run_add(int x,int ADD){mx[x]+=ADD,add[x]+=ADD;}
inline void pushdown(int x){
	run_add(x<<1,add[x]),run_add(x<<1|1,add[x]),add[x]=0;
}
inline void update(int x,int l,int r){
	if(L<=l&&r<=R){run_add(x,ADD);return;}
	if(add[x])pushdown(x);
	int mid=l+r>>1;
	if(L<=mid)update(x<<1,l,mid);
	if(R>mid)update(x<<1|1,mid+1,r);
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}

inline void query(int x,int l,int r){
	if(l==r){printf("%d\n",val[l]);return;}
	if(add[x])pushdown(x);
	int mid=l+r>>1;
	if(mx[x<<1|1]>=1)query(x<<1|1,mid+1,r);else query(x<<1,l,mid);
}

int main(){
	n=read();
	for(i=1;i<=n;i++){
		m=read();
		if(!read()){
			L=1,R=m,ADD=-1,update(1,1,n);
			if(mx[1]>=1)query(1,1,n);else puts("-1");
		}else{
			L=1,R=m,val[m]=read(),ADD=1,update(1,1,n);
			if(mx[1]>=1)query(1,1,n);else puts("-1");
		}
	}
}