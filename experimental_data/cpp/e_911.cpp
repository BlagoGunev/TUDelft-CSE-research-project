#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(int i=(int)(st),i##end=(int)(ed);i<=i##end;++i)
#define DREP(i,st,ed) for(int i=(int)(st),i##end=(int)(ed);i>=i##end;--i)
template<typename T>bool chkmin(T &x,const T &y){return x>y?x=y,1:0;}
template<typename T>bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
template<typename T>T read(){
 T x=0,f=1;
 char c=getchar();
 while((c<'0')||(c>'9')){if(c=='-')f=-1;c=getchar();}
 while((c>='0')&&(c<='9'))x=(x<<1)+(x<<3)+(c^48),c=getchar();
 return x*f;
}
#define read() read<int>()
template<typename T>void write(T x,char c){
 static char t[25];
 static int tlen;
 t[tlen=1]=c;
 if(x<0)putchar('-'),x=-x;
 do t[++tlen]=(x%10)^48;
 while(x/=10);
 while(tlen)putchar(t[tlen--]);
}
const int maxn=200005;
bool vis[maxn],done[maxn];
int n,m,a[maxn],p[maxn],tot;
stack<int>s;
int main(){
#ifndef ONLINE_JUDGE
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
#endif
 n=read(),m=read();
 REP(i,1,m)a[i]=read(),vis[a[i]]=1;
 done[0]=1;
 REP(i,1,m){
  if((!s.empty())&&(a[i]>s.top())){puts("-1");return 0;}
  s.push(a[i]);
  while(!s.empty()){
   if(!done[s.top()-1])break;
   done[s.top()]=1,s.pop();
  }
 }
 REP(i,1,m)
  write(a[i],' ');
 while(!s.empty()){
  DREP(i,s.top()-1,1){
   if(vis[i])break;
   write(i,' '),vis[i]=1;
  }s.pop();
 }
 DREP(i,n,1){
  if(vis[i])break;
  write(i,' '),vis[i]=1;
 }
 return 0;
}