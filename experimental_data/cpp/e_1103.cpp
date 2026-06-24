#include<bits/stdc++.h>
using namespace std;
int n;
struct poly{
  unsigned long long v[10];
  poly(){
    memset(v,0,sizeof(v));
  }
  poly operator+(poly a){
    poly ans;
    for(int i=0;i<10;i++)ans.v[i]=v[i]+a.v[i];
    return ans;
  }
  poly operator*(poly a){
    poly ans;
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)ans.v[(i+j)%10]+=v[i]*a.v[j];
    return ans;
  }
  poly shift(int k){
    poly ans;
    for(int i=0;i<10;i++)ans.v[(i+k)%10]=v[i];
    return ans;
  }
}f[100005];
poly qpow(poly a,int b){
  poly ans;
  for(ans.v[0]=1;b;b>>=1){
    if(b&1)ans=ans*a;
    a=a*a;
  }
  return ans;
}
void FWT(int n,poly f[],int c){
  for(int k=1;k<n;k*=10){
    for(int i=0;i<n;i+=10*k){
      for(int j=0;j<k;j++){
        poly t[10];
        for(int x=0;x<10;x++)for(int y=0;y<10;y++)t[x]=t[x]+f[i+j+y*k].shift((c*x*y%10+10)%10);
        for(int x=0;x<10;x++)f[i+j+x*k]=t[x];
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cin>>n;
  for(int i=1,a;i<=n;i++)cin>>a,f[a].v[0]++;
  FWT(100000,f,1);
  for(int i=0;i<100000;i++)f[i]=qpow(f[i],n);
  FWT(100000,f,-1);
  for(int i=0;i<n;i++){
    for(int j=9;j>=4;j--)f[i].v[j-1]+=f[i].v[j],f[i].v[j-2]-=f[i].v[j],f[i].v[j-3]+=f[i].v[j],f[i].v[j-4]-=f[i].v[j];
    cout<<((94170628496287261ull*(f[i].v[0]>>5))&288230376151711743)<<'\n';
  }
  return 0;
}