#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long n, ans = 1e18, cur;
pll srt[1<<20];
set<long long> st;

int main() 
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> srt[i].first;
    srt[i].second = i;
  }
  sort(srt, srt+n);
  for(int i=0; i<n; i++){
    if(srt[i].second != i) st.insert(i);
  }
  cur = -1;
  for(long long i=0; i<n; i++){
    cur = max(cur, srt[i].second);
    if(st.lower_bound(i+1) != st.end()){
      long long temp = *(st.lower_bound(i+1));
      ans = min((cur+1)*(cur+1) + (n-temp)*(n-temp), ans);
    }else{
      ans = min((cur+1)*(cur+1), ans);
    }
    //cout << "i cur ans " << i << " " << cur << " " << ans << endl;
    //ans = min(cur*cur + (n-1-i)*(n-1-i), ans);
  }
  //cout << ans << endl;
  
  for(int i=0; i<n; i++){
    srt[i] = {-srt[i].first, n-1-srt[i].second};
  }
  st.clear();
  sort(srt, srt+n);
  for(int i=0; i<n; i++){
    if(srt[i].second != i) st.insert(i);
  }
  cur = -1;
  for(long long i=0; i<n; i++){
    cur = max(cur, srt[i].second);
    if(st.lower_bound(i+1) != st.end()){
      long long temp = *(st.lower_bound(i+1));
      ans = min((cur+1)*(cur+1) + (n-temp)*(n-temp), ans);
    }else{
      ans = min((cur+1)*(cur+1), ans);
    }
    //ans = min(cur*cur + (n-1-i)*(n-1-i), ans);
  }
  
  cout << ans << endl;
}