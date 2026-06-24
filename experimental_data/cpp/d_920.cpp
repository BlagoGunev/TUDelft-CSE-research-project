/*
By Snickeen.
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL MAXN = 5e3+7;
LL f[MAXN],vm[MAXN],vis[MAXN],ad[MAXN];
LL N,K,V,res[MAXN]; 

signed main()
{
 LL i,j,k,l,r,s,t,ca=0;
 scanf("%lld%lld%lld",&N,&K,&V);
 for(i=1;i<=N;i++)scanf("%lld",&f[i]),ca+=f[i];
 if(ca<V)return puts("NO"),0;
 if(V%K==0){
  puts("YES");
  for(i=2;i<=N;i++)
   if((f[i]+K-1ll)/K)printf("%lld %lld %lld\n",(f[i]+K-1ll)/K,i,1ll);
  if(V/K)printf("%lld %lld %lld\n",V/K,1ll,2ll);
  return 0;
 }
 vis[0]=-1;
 l=k=1;
 for(j=1;j<=N;j++){
  s=f[j]%K;
  for(i=1;i<=l;i++){
   t=(s+vm[i])%K;
   if(vis[t])continue;
   vm[++k]=t;
   vis[t]=i;
   ad[t]=j;
   if(vis[V%K])break;
  }
  l=k;
  if(vis[V%K])break;
 }
 if(!vis[t=V%K])return puts("NO"),0;
 LL tot=0;
 while(t>0){
  res[++tot]=ad[t];
  t=vm[vis[t]];
 }
 LL ans=f[res[1]];
 puts("YES");
 for(i=2;i<=tot;i++){
  ans+=f[res[i]];
  if((f[res[i]]+K-1)/K)printf("%lld %lld %lld\n",(f[res[i]]+K-1)/K,res[i],res[1]);
  f[res[i]]=0;
 }
 if(ans>V){
  for(i=1;i<=N;i++)if(i!=res[1])break;
  printf("%lld %lld %lld\n",(ans-V)/K,res[1],i);
 }
 else if(ans<V){
  f[res[1]]=ans;
  for(i=1;i<=N;i++)if(i!=res[1])break;
  for(j=1;j<=N;j++){
   if(j==i||j==res[1]||f[j]==0)continue;
   f[i]+=f[j];
   if((f[j]+K-1)/K)printf("%lld %lld %lld\n",(f[j]+K-1)/K,j,i);
   //f[j]=0;
  }
  printf("%lld %lld %lld\n",(V-ans)/K,i,res[1]);
 }
 return 0;
}