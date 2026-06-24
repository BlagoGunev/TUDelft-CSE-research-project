#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int pre[2010];

int find(int x) {
  if(pre[x]==-1) {
    return x;
  }
  return pre[x]=find(pre[x]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int n,m,k,i,j;
  memset(pre,-1,sizeof(pre));
  scanf("%d%d%d",&n,&m,&k);
  int x,y;
  for(i = 1; i+k-1 <= n;i++){
    int lt=i,rt=i+k-1;
    while (lt <= rt){
      x = find(lt);
      y = find(rt);
      if (x != y) { 
        pre[x]=y;
      }
      ++lt;
      --rt;
    }
  }
  long long ans=1;
  long long mod = 1000000007;
  for(i=1; i<=n; i++) {
    if (pre[i] == -1) {
     ans=ans*(long long)m % mod;
    }
  }
  cout << ans << endl;
  return 0;
}