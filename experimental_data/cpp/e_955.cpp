#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
//~ int pre[MAXN],suf[MAXN];
int arr[MAXN],n;
struct node{
 int mn,mx,lazy;
}s[MAXN<<2];
void build(int nd,int x,int y){
 s[nd].lazy=0;
 if(x==y){
  s[nd].mn=arr[x]+x-1;
  s[nd].mx=-arr[x]+1;
  //~ s[nd].mx=x-(arr[x]+x-1);
  return;
 }
 int mid=(x+y)>>1;
 build(nd<<1,x,mid);
 build(nd<<1|1,mid+1,y);
 s[nd].mn=min(s[nd<<1].mn,s[nd<<1|1].mn);
 s[nd].mx=max(s[nd<<1].mx,s[nd<<1|1].mx);
}
void shift(int nd){
 int &ret=s[nd].lazy;
 if(!ret)
  return;
 s[nd<<1].lazy+=ret;s[nd<<1].mn+=ret;s[nd<<1].mx-=ret; 
 s[nd<<1|1].lazy+=ret;s[nd<<1|1].mn+=ret;s[nd<<1|1].mx-=ret; 
 ret=0;
}
void inc(int l,int r,int v,int nd,int x,int y){
 if(l>y or x>r)
  return;
 if(l<=x and y<=r){
  s[nd].mn+=v;
  s[nd].mx-=v;
  s[nd].lazy+=v;
  return;
 }shift(nd);
 int mid=(x+y)>>1;
 inc(l,r,v,nd<<1,x,mid);
 inc(l,r,v,nd<<1|1,mid+1,y);
 s[nd].mn=min(s[nd<<1].mn,s[nd<<1|1].mn);
 s[nd].mx=max(s[nd<<1].mx,s[nd<<1|1].mx);
}
int get(int l,int r,int nd,int x,int y){
 if(l>y or x>r)
  return INF;
 if(l<=x and y<=r)
  return s[nd].mn;
 shift(nd);
 int mid=(x+y)>>1;
 return min(get(l,r,nd<<1,x,mid),get(l,r,nd<<1|1,mid+1,y)); 
}
int tap(int nd,int x,int y){
 if(s[nd].mx<=0)
  return -1;
 if(x==y) 
  return x;
 shift(nd); 
 int mid=(x+y)>>1;
 int res=tap(nd<<1,x,mid);
 if(~res)
  return res;
 return tap(nd<<1|1,mid+1,y); 
}
void dfs(int nd,int x,int y){
 if(x==y){
  cout<<s[nd].mx<<" ";
  return; 
 }
 shift(nd);
 int mid=(x+y)>>1;
 dfs(nd<<1,x,mid);
 dfs(nd<<1|1,mid+1,y);
}
void print(){
 dfs(1,1,n);puts("");
}
int main(){
    //~ freopen("file.in", "r", stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
  scanf("%d",arr+i);
 build(1,1,n); 
 int ans=INF; 
 for(int t=1;t<=n;t++){
  //~ print();
  int pos=tap(1,1,n);
  //~ debug(pos);
  if(~pos)
   umin(ans,max(get(1,pos-1,1,1,n),get(pos,n,1,1,n)));
  inc(t+1,n,-1,1,1,n);
  inc(1,t,+1,1,1,n); 
  //~ pre[0]=suf[n+1]=INF;
  //~ for(int i=1;i<=n;i++)
   //~ pre[i]=min(pre[i-1],arr[i]+abs(t-i));
  //~ for(int i=n;i>=1;i--)
   //~ suf[i]=min(suf[i+1],arr[i]+abs(t-i));
  //~ for(int i=2;i<=n;i++)
   //~ if(arr[i]+abs(t-i)<i){
    //~ umin(ans,max(pre[i-1],suf[i]));
    //~ break;
   //~ }
 }
 if(ans==INF)
  ans=-1;
 printf("%d\n",ans); 
 return 0;
}