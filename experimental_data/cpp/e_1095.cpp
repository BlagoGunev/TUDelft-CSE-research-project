#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  string s;
  cin>>s;
  int depth[n+1]={};
  bool flag=0;
  if(s[0]=='(') depth[0]=1;
  else depth[0]=-1;

  int mi=n+1,ma=-1;
  if(depth[0]<0) mi=0;
  if(depth[0]<=1) ma=0;

  for(int i=1;i<n;i++){
    if(s[i]=='(') depth[i]=depth[i-1]+1;
    else depth[i]=depth[i-1]-1;
    if(depth[i]<-2) flag=1;

    if(depth[i]<0) mi=min(mi,i);
    if(depth[i]<=1) ma=max(ma,i);
  }

  if(flag||(depth[n-1]!=2&&depth[n-1]!=-2)){
    cout<<0<<endl;
    return 0;
  }

  if(depth[n-1]==2){
    if(mi!=n+1){
      cout<<0<<endl;
      return 0;
    }

    int ans=0;
    for(int i=ma+1;i<n;i++){
      if(s[i]=='('&&depth[i]>=2) ans++;
    }
    cout<<ans<<endl;
  }else if(depth[n-1]==-2){
    int ans=0;
    for(int i=0;i<=mi;i++){
      if(s[i]==')') ans++;
    }
    cout<<ans<<endl;
  }

  return 0;
}