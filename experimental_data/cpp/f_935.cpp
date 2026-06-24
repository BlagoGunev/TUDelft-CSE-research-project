#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long int
#define inf 1e9+10
using namespace std;
const int maxn=100100;

/*
??i'|????x2??????????a
 1.a[i]>a[i-1],a[i+1] : 2x ('???,a[i-1]-a[i],a[i+1]-a[i]<0);
 2.a[i+1]>a[i]>a[i-1] : 2x-2(a[i+1]-a[i]) ('?????a[i-1]-a[i]<0);
 3.a[i-1]>a[i]>a[i+1] : 2x-2(a[i-1]-a[i]) (??2);
 4.a[i]<a[i-1],a[i+1] : ?3?o???? / ?3?o???? / 2x-2((a[i+1]-a[i])+(a[i-1]-a[i]));
 
 ?y?????????????a2x-2(max(a[i+1]-a[i],0)+max(a[i-1]-a[i],0))
 ?????a??????????[l,r](l<r)????????'????y??????2????????D???????a4?? 
 ????:
 ????mq[l,r]={
  l<r: 2x-2*{
   min(q[l,m],q[m+1,r]) , l<r
   max(a[i+1]-a[i],0)+max(a[i-1]-a[i],0) , l=r
  }
  l=r: |a[i+1]-a[i]-x|+|a[i-1]-a[i]-x|-|a[i+1]-a[i]|-|a[i-1]-a[i]|
 }
*/

inline LL max(LL a,LL b){return a>b?a:b;}
inline LL min(LL a,LL b){return a>b?b:a;}

inline int read(){
 int x=0;char c=getchar();
 while(c<'0'||c>'9')  c=getchar();
 while(c>='0'&&c<='9')  x=x*10+c-'0',c=getchar();
 return x;
}

LL sum[maxn*4],mq[maxn*4],dl[maxn*4],dr[maxn*4];
int lb[maxn*4],rb[maxn*4]; //dl[i]=a[i-1]-a[i],dr[i]=a[i+1]-a[i]
int N,M;
int a[maxn];

inline void update(int i){
 //printf("\tupdate:%d\n",i);
 if(lb[i]==rb[i]) {
  sum[i]=fabs(dr[i]);
  mq[i]=max(dl[i],0)+max(dr[i],0);
  return;
 }
 sum[i]=sum[i<<1]+sum[(i<<1)+1];
 mq[i]=min(mq[i<<1],mq[(i<<1)+1]);
}

inline void updateall(int i){while(i>1){update(i);i=i>>1;}update(1);}

void build(int i,int l,int r){
 lb[i]=l;rb[i]=r;
 if(l==r){
  dl[i]=a[l-1]-a[l];dr[i]=a[l+1]-a[l];
  sum[i]=fabs(dr[i]);
  mq[i]=max(dl[i],0)+max(dr[i],0);
 }
 else{
  int m=(l+r)>>1;
  build(i<<1,l,m);build((i<<1)+1,m+1,r);update(i);
 }
}

LL getmq(int i,int l,int r){
 if(l==lb[i]&&r==rb[i])  return mq[i];
 int m=(lb[i]+rb[i])>>1;
 LL re=inf;
 if(l<=m) re=min(re,getmq(i<<1,l,min(m,r)));
 if(r>m)  re=min(re,getmq((i<<1)+1,max(m+1,l),r));
 return re;
}

int find(int x,int i){
 if(lb[i]==rb[i]&&lb[i]==x)  return i;
 else if(x<=((lb[i]+rb[i])>>1))  return find(x,i<<1);
 else  return find(x,(i<<1)+1);
}

inline LL solve1(int l,int r,int x){
 if(l==r){
  int p=find(l,1);
  return fabs(dl[p]-x)+fabs(dr[p]-x)-fabs(dl[p])-fabs(dr[p])+sum[1];
 }
 else{return max(0,2*x-2*getmq(1,l,r))+sum[1];}
}

inline void solve2(int l,int r,int x){
 int p=find(l,1);dl[p]-=x;updateall(p);
 p=find(l-1,1);dr[p]+=x;updateall(p);
 p=find(r,1);dr[p]-=x;updateall(p);
 p=find(r+1,1);dl[p]+=x;updateall(p);
 
}

int main(){
 int i,j,k,x,y;
 //freopen("a.in","r",stdin);
 N=read();
 for(i=1;i<=N;i++)  a[i]=read();a[N+1]=a[N];a[0]=a[1];
 build(1,1,N);M=read();//printf("%d\n",sum[1]);
 for(i=1;i<=M;i++){
  j=read();k=read();x=read();y=read();
  if(j==1){printf("%lld\n",solve1(k,x,y));}
  else{solve2(k,x,y);}
  //for(int i=1;i<=N*4;i++){
  // if(lb[i])  printf("!!%d %d %d %d %d %d %d\n",i,lb[i],rb[i],dl[i],dr[i],sum[i],mq[i]);
  //}
 }
}