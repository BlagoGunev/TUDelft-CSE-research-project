#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair

// 

int a[510];
vector<int>ans;
vector<int>ones;

vector<pair<int,int>>lk;

int main(){
  int n;
  cin>>n;
  rep(i,1,n+1){
    scanf("%d",a+i);
  }
  rep(i,1,n+1){
    if(a[i] > 1){
      ans.pb(i);
    }else{
      ones.pb(i);
    }
  }
  if(ones.size()<=2){
    printf("YES %d\n",n-1);
    printf("%d\n",n-1);
    if(ones.size() > 0){
      printf("%d %d\n",ans[0],ones[0]);
    }
    if(ones.size() > 1){
      printf("%d %d\n",ans[ans.size()-1],ones[1]);
    }
    rep(i,1,ans.size()){
      printf("%d %d\n",ans[i-1],ans[i]);
    }
    return 0;
  }
  if(ans.size()==0){
    printf("NO\n");
    return 0;
  }
  lk.pb({ones[0],ans[0]});
  lk.pb({ones[1],ans[ans.size()-1]});
  int j = 0;
  for(int i = 2;i<ones.size();i++){
    while(j<ans.size() && a[ans[j]] <= 2 )j++;
    if(j == ans.size()){
      printf("NO\n");
      return 0;
    }
    a[ans[j]] -- ;
    lk.pb({ones[i],ans[j]});
  }
  printf("YES %lu\n",ans.size()+1);
  printf("%d\n",n-1);
  for(auto item:lk){
    printf("%d %d\n",item.first,item.second);
  }
  for(int i=1;i<ans.size();i++){
    printf("%d %d\n",ans[i-1],ans[i]);
  }
  return 0;
}

/*
 *
 * hash prime
   61,83,113,151,211,281,379,509683,911
   1217,1627,2179,2909,3881,6907,9209
   12281,16381,21841,29123,38833,51787,69061,92083
   122777,163729,218357,291143,388211,517619,690163,999983
   1226959,1635947,2181271,2908361,3877817,5170427,6893911,9191891
   12255871,16341163,21788233,29050993,38734667,51646229,68861641,91815541
   122420729,163227661,217636919,290182597,386910137,515880193,687840301,917120411
   1000000007,1000000009
 * */