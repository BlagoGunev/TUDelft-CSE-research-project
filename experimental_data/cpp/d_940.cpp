#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define ll long long
using namespace std;
inline int read(){
 int x=0,f=1;char ch;
 do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
 do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
 return x*f;
}
const int N=100010;
const int INF=1e9;
int a[N];
inline int getmx(int x){
 return max(max(max(a[x-4],a[x-3]),max(a[x-2],a[x-1])),a[x]);
}
inline int getmn(int x){
 return min(min(min(a[x-4],a[x-3]),min(a[x-2],a[x-1])),a[x]);
}
struct node{
 int mn,mx;
 node(){mn=-INF,mx=INF;}
};
int main(){
 node l,r;
 int n=read();
 for (int i=1;i<=n;++i) a[i]=read();
 int b,lb,len=4;
 for (int i=1;i<=4;++i) scanf("%1d",&lb);
 for (int i=5;i<=n;++i){
  b=getchar()-'0';
  ++len;
  if (len<5){
   lb=b;
   continue;
  }
  if (b==lb){
   if (b==0) l.mx=min(l.mx,getmx(i));
   else r.mn=max(r.mn,getmn(i));
  }
  else{
   if (b==0) r.mx=min(r.mx,getmn(i)-1);
   else l.mn=max(l.mn,getmx(i)+1);
   len=1;
  }
  lb=b;
 }
 printf("%d %d\n",l.mn,r.mx);
 return 0;
}