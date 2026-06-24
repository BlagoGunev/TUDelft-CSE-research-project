#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
const double pi = acos(-1.0);

// x[i]*2 < maxx

deque<pair<int,int> > valpos;
int n;
int a[100010];
int ans[100010];

int main(){
  cin>>n;
  int maxai = 0;
  rep(i,0,n){
    scanf("%d",a+i);
    if(a[i] > a[maxai]){
      maxai = i;
    }
  }
  valpos.pb({a[maxai],maxai});
  rep(step,1,n){
    int i = (maxai+step)%n;
    int jj = -1;
    rep(j,0,valpos.size()){
      if(a[i]*2 >= valpos[j].first){
        break;
      }
      jj = j;
    }
    rep(j,0,jj+1){
      ans[valpos[j].second] = (i+n-valpos[j].second)%n;
    }
    rep(j,0,jj+1){
      valpos.pop_front();
    }
    while(valpos.size() > 0 && a[i] > valpos[valpos.size()-1].first){
      valpos.pop_back();
    }
    valpos.pb({a[i],i});
  }
  if(valpos[0].second == maxai){
    rep(i,0,n){
      if(a[i] == a[maxai]){
        ans[i] = -1;
      }
    }
  }
  rep(i,1,n){
    int pos = (maxai+n-i)%n;
    if(ans[pos] != 0)continue;
    if(ans[(pos+1)%n] == -1){
      ans[pos] = -1;
      continue;
    }
    ans[pos] = ans[(pos+1)%n]+1;
  }
  rep(i,0,n){
    printf("%d ",ans[i]);
  }
  return 0;
}