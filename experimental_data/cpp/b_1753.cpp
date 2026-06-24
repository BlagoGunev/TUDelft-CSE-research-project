#include<iostream>
using namespace std;
#define maxco 100000+5
#define lld long double
#define cha ios_base::sync_with_stdio(false);
#define mod 1000000007
#define ffl cout.flush();
#define phi acos(-1)
#define ll long long

ll cnt[500069];
int main(){
    cha
    ll n,x;
    cin>>n>>x;
  for(ll w,i=1;i<=n;i++){
    cin>>w;
    cnt[w]++;
  }
  ll mn=1e18;
  for(ll i=1;i<=500009;i++){
    if(cnt[i]!=0){
      ll val=cnt[i];
      val/=(i+1);
      cnt[i+1]+=val;
      cnt[i]-=val*(i+1);
      if(cnt[i]!=0)mn=i;
    }
  }
  for(ll i=1;i<=500009;i++){
    if(cnt[i]!=0){
      // cout<<i<<" "<<cnt[i]<<endl;
      mn=min(i,mn);
    }
  }
  if(mn>=x){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
/*
 
 2
 
 
 
 */