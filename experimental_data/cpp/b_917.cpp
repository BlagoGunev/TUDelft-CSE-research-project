#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MAX 20000
using namespace std;

char mp[105][105],mx[105];
int out[105];
bool dp[105][105][26];
vector<int> v;

int main(){
 int n,m,fr,to;
 char x;
 scanf("%d%d",&n,&m);
 while(m--){
  scanf("%d%d %c",&fr,&to,&x);
  //printf("%d %d %c");
  mp[fr][to]=x;
  mx[fr]=max(mx[fr],x);
  out[fr]++;
 }
 for(int i=0;i<n;i++){
  for(int j=1;j<=n;j++){
   if(out[j]==0){
    v.PB(j);
    for(int k=1;k<=n;k++){
     if(mp[k][j])out[k]--;
    }
    out[j]=-1;
   }
  }
 }
 for(int i=0;i<v.size();i++){
  for(int j=i+1;j<v.size();j++){
   int mx=-1;
   for(int k=1;k<=n;k++){
    if(mp[v[i]][k]&&!dp[v[j]][k][mp[v[i]][k]-'a']){
     mx=max(mx,mp[v[i]][k]-'a');
    }
   }
   for(int k=0;k<=mx;k++){
    dp[v[i]][v[j]][k]=1;
   }
   mx=-1;
   for(int k=1;k<=n;k++){
    if(mp[v[j]][k]&&!dp[v[i]][k][mp[v[j]][k]-'a']){
     mx=max(mx,mp[v[j]][k]-'a');
    }
   }
   for(int k=0;k<=mx;k++){
    dp[v[j]][v[i]][k]=1;
   }
  }
 }
 for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
   if(dp[i][j][0])printf("A");
   else printf("B");
  }
  puts("");
 }
}