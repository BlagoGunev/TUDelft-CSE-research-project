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
int depth[N];
int num[N];
int main(){
 int n=read();
 depth[1]=1;
 memset(num,0,sizeof(num));
 ++num[1];
 int mxdp=1;
 for (int i=2;i<=n;++i){
  int p=read();
  depth[i]=depth[p]+1;
  ++num[depth[i]];
  mxdp=max(mxdp,depth[i]);
 }
 int ans=0;
 for (int i=1;i<=mxdp;++i)
 if(num[i]&1) ++ans;
 printf("%d\n",ans);
 return 0;
}